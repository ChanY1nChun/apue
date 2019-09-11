#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
void handler(int);

int main() {
	struct sigaction act;
	act.sa_flags = 0;
	act.sa_handler = handler;
	
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,SIGINT);

	sigaction(SIGINT, &act, NULL);
	sigaction(SIGTSTP, &act, NULL);

	while(1) {
		write(1, ".", 1);
		sleep(3);
	}

	return 0;
	
} 


void handler(int signo)
{
	if(signo == SIGINT) {
		printf("SIGINT signal!\n");
		sleep(5);
	}
	else if(signo == SIGTSTP) {
		printf("SIGTSTP signal!\n");
		sleep(5);
	}
}
