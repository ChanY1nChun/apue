#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void printsig(sigset_t st)
{
	int n;
	for(n = 1; n <= 64; ++n) {
		if(n == 33)
			putchar(' ');
		if(sigismember(&st, n) == 1)
			putchar('1');
		else
			putchar('0');
	}
	printf("\n");
}

void handler(int signo)
{
	if(signo == SIGINT) printf("SIGINT signal\n");
	else if(signo == SIGTSTP) printf("SIGTSTP signal\n");
}

int main() {
	sigset_t st;
	sigemptyset(&st);
	
	sigaddset(&st,SIGINT);
	sigaddset(&st,SIGTSTP);
	sigprocmask(SIG_BLOCK, &st, NULL);
	
	printsig(st);
	
	signal(SIGINT,handler);
	signal(SIGTSTP,handler);


	printf("I am %d\n", getpid());
	int n = 0;
	while(1) {
	
		sigpending(&st);
		printsig(st);
		sleep(1);

		if(n == 10) {
			sigset_t tmp;
			sigemptyset(&tmp);
			sigaddset(&tmp,SIGINT);
			sigaddset(&tmp,SIGTSTP);
			sigprocmask(SIG_UNBLOCK, &tmp, NULL);
		}
	++n;
	printf("%d\n",n);
	}
	return 0;
}
