#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int n = 5;
	pid_t pid;
	while(n--) {
		pid = fork();
		if(pid == 0) break;
	}
	
	if(pid == 0) {
		printf("I am child %d, my parent is %d\n", getpid(), getppid());
		return 0;
	}

	while(1) {
		sleep(3);
		pid = wait(NULL);
		if(pid == -1) {
	   		printf("I am father %d, clean all zombies\n", getpid());
			return 0;
		}
		printf("I am father %d, child %d exit\n",getpid(), pid);
	}

	return 0;
}
