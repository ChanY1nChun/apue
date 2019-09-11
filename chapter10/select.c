#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/select.h>
#include <fcntl.h>
int process(char *context, int fd);


int main() {

	fd_set st;
	int n;
	int fd0 = STDIN_FILENO;
	int fd1 = open("a.fifo", O_RDONLY);
	printf("open pipe = %d\n", fd1);
	int fd2 = open("b.fifo", O_RDONLY);
	printf("open pipe = %d\n", fd2);

	FD_SET(fd0, &st);
	FD_SET(fd1, &st);
	FD_SET(fd2, &st);

	int fdmax = fd2 + 1;
	while(1) {
		fd_set sttmp = st;
		select(fdmax, &sttmp, NULL, NULL, NULL);
		
		if(FD_ISSET(fd0, &sttmp)) {
			n = process("fd0", fd0);
			if(n == 0) FD_CLR(fd0, &st);
		}
		if(FD_ISSET(fd1, &sttmp)) {
			n = process("fd1", fd1);
			if(n == 0) FD_CLR(fd1, &st);
		}
		if(FD_ISSET(fd2, &sttmp)) {
			n = process("fd2", fd2);
			if(n == 0) FD_CLR(fd2, &st);
		}

	
	}
	return 0;
}


int process(char *context, int fd)
{
	char buf[64] = {0};
	char line[64] = {0};
	int n;

	n = read(fd, buf, 64);
	if(n == 0) {
		printf("%s exit!\n", context);
		return 0;
	}
	printf("%s : %s",context, buf);

	return n;
}
