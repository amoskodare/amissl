#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libcmt.h"

size_t fwrite(const void *ptr,size_t size,size_t nmemb,FILE *stream)
{
	signed long subsize;
	unsigned long total;
	unsigned char *b=(unsigned char *)ptr;
	if(!(total=size*nmemb)) /* Just in case size==0 */
		return total;
	do
	{
		if(TOFILE(stream)->_wcnt<TOFILE(stream)->_size)
		{
			subsize=total>TOFILE(stream)->_size-TOFILE(stream)->_wcnt?TOFILE(stream)->_size-TOFILE(stream)->_wcnt:total;
			memcpy(TOFILE(stream)->_ptr,b,subsize);
			TOFILE(stream)->_ptr+=subsize;
			TOFILE(stream)->_wcnt+=subsize;
			b+=subsize;
			total-=subsize;
		}
		else
		{
			int c;
			c=*b++;
			if(putc(c,TOFILE(stream))==EOF)
				break;
			total--;
		}
	}while(total);
	return (b-(unsigned char *)ptr)/size;
}