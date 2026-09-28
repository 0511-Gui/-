#include <process_copy.h>

int check_pram(int argc,const char * srcfile,int pronum)
{
	 if (argc < 3) {
		 printf("参数异常\n");
		 exit(-1);
		 }
	if (access(srcfile, F_OK) != 0) {
		printf("源文件不存在\n");
		exit(-1);
		}
	if (pronum < 3 || pronum > 100) {
		printf("进程数异常\n");
		exit(-1);
		}
}
