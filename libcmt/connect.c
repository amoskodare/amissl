#include <sys/types.h>
#include <netinet/in.h>

#ifdef __amigaos4__
#undef __USE_INLINE__
#include <proto/bsdsocket.h>
#else
#define AMITCP_NEW_NAMES
#include <errno.h>
#include "multitcp.h"
#include <internal/amissl.h>
#endif

#include "libcmt.h"

int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
#ifdef __amigaos4__
  GETISOCKET();
  if(ISocket) return ISocket->connect(sockfd, (struct sockaddr *)addr, addrlen);
  else return -1;
#else
	GETSTATE();

	if (state->SocketBase)
	{
		switch(state->TCPIPStackType)
		{
			case TCPIP_MLink:{
				int res;
				ObtainSemaphore(&state->MLinkLock->Semaphore);
				res = amitcp_Connect(sockfd, addr, addrlen);
				ReleaseSemaphore(&state->MLinkLock->Semaphore);
				return res;
				break;}
			case TCPIP_Miami:
			case TCPIP_AmiTCP:
				return amitcp_Connect(sockfd, addr, addrlen);
				break;
			case TCPIP_IN225:
				return in225_connect(sockfd, (struct sockaddr *)addr, addrlen);
				break;
			case TCPIP_Termite:
				return termite_connect(sockfd, (struct sockaddr *)addr, addrlen);
				break;
		}
	}

	return(-1);
#endif
}
