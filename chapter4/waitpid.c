#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	pid_t pid;
	int status;
	pid = fork();
	if(pid == 0)
		while(1) {
			sleep(5);
			printf("I am child %d, my father is %d\n", getpid(), getppid());
		}
	
	if(pid > 0) {
		while(1) {
			sleep(10);	
			waitpid(pid,&status,WCONTINUED | WUNTRACED);
			/*printf("I am parent %d, child %d ", getpid(), pid);*/
			if(WIFEXITED(status)) 
				printf("normal exited, and exit status is %d\n",WEXITSTATUS(status));
			else if(WIFSIGNALED(status)) 
				printf("abnormal termination, signal number is %d\n",WTERMSIG(status));
			else if(WIFSTOPPED(status)) 
				printf("child stopped, signal number is %d\n",WSTOPSIG(status));
			else if(WIFCONTINUED(status)) 
				printf("child continued\n");

		}
		
	}

	return 0;
}
