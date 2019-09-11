#include <stdio.h>
#include <signal.h>

void printsigset(sigset_t);

int main() {
	
	sigset_t st;
	printsigset(st);
	
	sigemptyset(&st);
	printsigset(st);
	
	sigfillset(&st);
	printsigset(st);

	sigdelset(&st,SIGHUP);
	sigdelset(&st,SIGINT);
	sigdelset(&st,SIGKILL);

	printsigset(st);
	
	return 0;
}


void printsigset(sigset_t st)
{
	int n;
	for(n = 1; n <= 64; ++n) {
		if(n == 33) putchar(' ');
		if(sigismember(&st,n) == 1)
			putchar('1');
		else
 			putchar('0');	
	}
	printf("\n");
}
