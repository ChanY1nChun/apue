#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid;
	int n = 4;
	
	while(n--) {
		pid = fork();
		if(pid > 0) break;
	}

	printf("pid %d, ppid %d\n", getpid(), getppid());

	while(1) pause();

	return 0;
}
