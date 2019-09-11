#include <stdio.h>
#include <unistd.h>

int main() {
	int n = 5;
	pid_t pid;
	while(n--) {
		pid = fork();
		if(pid == 0) break;
	}
	
	if(pid == 0) {
		printf("I am kid %d, my father is %d\n", getpid(), getppid());
		return 0;
	}	
	while(1) {
		sleep(5);
		printf("I am father %d\n", getpid());
	}


	return 0;
}
