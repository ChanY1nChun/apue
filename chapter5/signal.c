#include <signal.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


void sig_handler(int signo)
{
	switch(signo) {
	case SIGUSR1:
		printf("This is SIGUSR1 signal!\n"); break;
	case SIGUSR2:
		printf("This is SIGUSR2 signal!\n"); break;
	case SIGINT:
		printf("This is SIGINT signal!\n"); break;
	case SIGSEGV:
		printf("This is SIGSEGV signal!\n"); break;
	case SIGTSTP:
		printf("This is SIGTSTP signal!\n"); break;
	case SIGQUIT:
		printf("This is SIGQUIT signal!\n"); break;
	}
	sleep(2);
}











int main() {
	
	printf("I am process %d.\n", getpid());
	
	signal(SIGUSR1,sig_handler);
	signal(SIGUSR2,sig_handler);
	signal(SIGINT,sig_handler);
	signal(SIGSEGV,sig_handler);
	signal(SIGTSTP,sig_handler);
	signal(SIGQUIT,sig_handler);

	while(1) {
		write(1,".",1);
		sleep(7);
	}

	return 0;
}
