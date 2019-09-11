#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void handler(int, siginfo_t*, void*);


int main() {
	
	struct sigaction act;
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);

	printf("I am %d\n", getpid());
	
	sigaction(SIGQUIT, &act, NULL);
	
	while(1) {
		write(1,".",1);
		pause();
	}
	
	return 0;
}

void handler(int signo, siginfo_t *siginfo, void *context)
{
	if(signo == SIGQUIT) printf("SIGQUIT signal!\n");

	if(siginfo) {
		printf("%d sent me the signal!\n", siginfo->si_pid);
		printf("real user ID %d\n",siginfo->si_uid);
		printf("signal number is %d\n",siginfo->si_signo);
		printf("sival_int is %d\n",siginfo->si_value.sival_int);
		printf("sival_ptr is %p\n",siginfo->si_value.sival_ptr);
	}
}
