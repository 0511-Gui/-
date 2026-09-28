#include <process_copy.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int process_create(const char * srcfile, const char * destfile, int pronum , int blocksize)
{
	int i;
	pid_t pid;
	char str_offset[100];
	char str_blocksize[100];
	off_t offset;

	for(i = 0; i < pronum; i++)
	{
		pid = fork();
		if(pid == 0)
		{
			offset = i * blocksize;
			sprintf(str_offset,"%ld", offset);
			sprintf(str_blocksize,"%d", blocksize);


	execl("./MOD/Copy","Copy",srcfile,destfile,str_offset,str_blocksize,NULL);
	perror("execl failed");
	exit(EXIT_FAILURE);
	}
	}
	return 0;
}

