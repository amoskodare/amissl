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

int listen(int sockfd, int backlog)
{
#ifdef __amigaos4__
  GETISOCKET();
  if(ISocket) return ISocket->listen(sockfd, backlog);
  else return -1;
#else
	GETSTATE();

	if (state->SocketBase)
	{
		switch(state->TCPIPStackType)
		{
			case TCPIP_Miami:
			case TCPIP_AmiTCP:
			case TCPIP_MLink:
				return amitcp_Listen(sockfd, backlog);
				break;
			case TCPIP_IN225:
				return in225_listen(sockfd, backlog);
				break;
			case TCPIP_Termite:
				return termite_listen(sockfd, backlog);
				break;
		}
	}

	return(-1);
#endif
}
