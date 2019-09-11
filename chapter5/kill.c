#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void handler(int);
void child();


int main() {
	
	signal(SIGUSR1,handler);
	signal(SIGCHLD,handler);
	
	pid_t pid = fork();

	if(pid == 0) child();
	
	if(pid > 0) {

		while(1) {
			write(1,".",1);
			sleep(10);
		}
	}
	return 0;
}
void handler(int signo)
{
	int status;
	if(signo == SIGUSR1)
		printf("SIGUSR1 signal!\n");
	else if(signo == SIGCHLD) {
		wait(&status);
		printf("exit code %d\n", WEXITSTATUS(status));
	}
}

void child()
{
	int n = 10;
	while(n--) {
		kill(getppid(),SIGUSR1);
		sleep(1);
	}
	exit(0);
}
