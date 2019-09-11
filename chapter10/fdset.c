#include <sys/select.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void printset(fd_set*);

int main() {

	printf("initialzing!\n");
	fd_set st;
	printset(&st);

	printf("clear!\n");
	FD_ZERO(&st);
	printset(&st);

	printf("odd!\n");
	int i;
	for(i = 0; i < 16; ++i)
		if(i%2 != 0)
			FD_SET(i, &st);
	printset(&st);
	
	printf("clear 3!\n");
	FD_CLR(3, &st);
	printset(&st);

	printf("clear!\n");
	FD_ZERO(&st);
	printset(&st);

	return 0;
}

void printset(fd_set *st)
{
	int i;
	for(i = 0; i < 16; ++i) {
		if(FD_ISSET(i, st))
			putchar('1');
		else
			putchar('0');
		
	}
	printf("\n");
}
