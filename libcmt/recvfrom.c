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

ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                 struct sockaddr *src_addr, socklen_t *addrlen)
{
#ifdef __amigaos4__
  GETISOCKET();
  if(ISocket) return ISocket->recvfrom(sockfd, buf, len, flags, src_addr, addrlen);
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
				return amitcp_RecvFrom(sockfd, buf, len, flags, src_addr, addrlen);
				break;
			case TCPIP_IN225:
				return in225_recvfrom(sockfd, buf, len, flags, src_addr, addrlen);
				break;
			case TCPIP_Termite:
				return termite_recvfrom(sockfd, buf, len, flags, src_addr, addrlen);
				break;
		}
	}

	return(-1);
#endif
}
