#include <dos/dos.h>
#include <proto/dos.h>
#include <proto/exec.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <internal/amissl.h>
#include "libcmt.h"

FILE *freopen(const char *filename,const char *mode,FILE *stream)
{
	int error;
	error=fflush(stream);
#if 0
	if(stream->file>2)
	{
		Close(stream->_file);
		if(stream->name!=NULL) /* file is temporary */
		{
			BPTR cd;
			cd=CurrentDir(stream->tmpdir); /* cd t: */
			if(!DeleteFile(stream->name))	/* delete file */
			{
				SetAmiSSLerrno(__io2errno(IoErr()));
				error=1;
			}
			free(stream->name); /* free filename */
			stream->name=NULL;
			UnLock(CurrentDir(cd)); /* cd back, unlock t: */
		}
		stream->file=0l;
	}
	if(error)
		return NULL;
#endif

	if(filename!=NULL)
	{
		long file;
		long flags=MODE_OLDFILE;
		int append=0,plus=1;
		if(mode!=NULL)
		{
			switch(mode[0])
			{
				case 'r':
					break;
				case 'w':
					flags=MODE_NEWFILE;
					break;
				case 'a':
					flags=MODE_READWRITE;
					append=1;
					break;
				default:
					return NULL;
			}
			if(mode[1]=='b')
				plus=2;
			switch(mode[plus])
			{
				case '+':
					if(mode[plus+1])
						return NULL;
					break;
				case '\0':
					break;
				default:
					return NULL;
			}
		}

		if((file=Open((char *)filename,flags))<0)
			return NULL;
		
		if(append && Seek(file,0,SEEK_END)<0)
			return NULL;

		TOFILE(stream)->_flag &= ~(_IOLBF);
		if(IsInteractive(file))
			TOFILE(stream)->_flag |= _IOLBF; /* set linebuffered flag */
	 
		TOFILE(stream)->_file=file;
	}

	return stream;
}

DeclareMinList(__filelist); /* list of open files (fflush() needs also access) */
DeclareSemaphore(FileListLock);

#ifdef __amigaos4__
void __init_libcmt_file(void) __attribute__((constructor));

void __init_libcmt_file(void)
{
	NewList(&__filelist);
	InitSemaphore(&FileListLock);
}
#endif

FILE *fopen(const char *name, const char *mode)
{
	struct filenode *node;
	if((node=(struct filenode *)malloc(sizeof(struct filenode)))!=NULL)
	{
		memset(node,0,sizeof(struct filenode));
		if((node->FILE._base=(char *)malloc(BUFSIZ))!=NULL)
		{
			node->FILE._size=BUFSIZ;
			node->FILE._flag|=0x80; /* Buffer is malloc'ed */
			if(freopen(name,mode,&node->FILE)!=NULL)
			{
				ObtainSemaphore(&FileListLock);
				AddHead((struct List *)&__filelist,(struct Node *)&node->node);
				ReleaseSemaphore(&FileListLock);
				return &node->FILE;
			}
			free(node->FILE._base);
		}
		else
		{
			SetAmiSSLerrno(ENOMEM);
		}
		free(node);
	}
	else
	{
		SetAmiSSLerrno(ENOMEM);
	}
	return NULL;
}

int fclose(FILE *file)
{
	struct filenode *node;
	fflush(file);
	Close(TOFILE(file)->_file);

	node = (struct filenode *)(((BYTE *)file)-offsetof(struct filenode,FILE));
	Remove((struct Node *)node);
	free(node);
	return 0;
}

int fseek(FILE *file, LONG pos, int mode)
{
	int res;
	fflush(file);
	res = Seek(TOFILE(file)->_file, pos, mode);
	if(res==-1)
	{
		SetAmiSSLerrno(__io2errno(IoErr()));
	}
	return res;
}

/* Only used by the (currently) unsupported FD interface */

int open(const char *path_name, int open_flag, ... /* mode_t mode */ )
{
	return(-1);
}

int close(int fd)
{
	SetAmiSSLerrno(EINVAL);

	return(-1);
}

int lseek(int fd, long offset, int mode)
{
	SetAmiSSLerrno(EINVAL);

	return(-1);
}

int read(int fd, void *buffer, size_t num_bytes)
{
	SetAmiSSLerrno(EINVAL);

	return(-1);
}

int write(int fd, const void* buffer, size_t num_bytes)
{
	SetAmiSSLerrno(EINVAL);

	return(-1);
}
