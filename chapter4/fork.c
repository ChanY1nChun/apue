#include <unistd.h>
#include <stdio.h>

int main() {
	
	pid_t pid = fork();

	if(pid == 0) 
		printf("I am child process. Pid:%d, Ppid:%d\n",getpid(), getppid());
	
	else if(pid != 0)
		printf("I am parent process. Pid:%d, Cpid:%d\n",getpid(), pid);

	return 0;

}
