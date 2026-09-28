#include <process_copy.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void process_wait(void )
{
	pid_t zpid;
	while((zpid = waitpid(-1,NULL,WNOHANG))!=-1)
	{
		if(zpid > 0)
		{
			printf("回收子进程 pid=%d\n", zpid);
		}
		else
		{
			usleep(100000);
		}
	}
}

