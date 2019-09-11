#include <stdio.h>
#include <unistd.h>

int main() {
	int n = 4;
	while(n--) {
		pid_t pid = fork();
		if(pid == 0) break;
	}

	printf("pid %d, ppid %d\n", getpid(), getppid());
	while(1);

	return 0;
	
}
