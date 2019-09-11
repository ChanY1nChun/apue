#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char **argv) {
	pid_t pid = atoi(argv[1]);
	
	union sigval val;
	while(1) {
		scanf("%d",&val.sival_int);
		sigqueue(pid, SIGQUIT, val);
	}

	return 0;
}
