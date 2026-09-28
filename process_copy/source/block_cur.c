#include <process_copy.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int block_cur(const char * srcfile, int pronum)
{
	int fd;
	off_t filesize;
	int ret_size;

	fd = open(srcfile, O_RDONLY);
	filesize = lseek(fd, 0, SEEK_END);
	close(fd);

	if(filesize % pronum == 0)
	{
		ret_size = filesize / pronum;
	}
	else
	{
		ret_size = filesize / pronum + 1;
	}
	return ret_size;
}

