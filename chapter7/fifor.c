#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	
	printf("I am %d\n",getpid());
	
	char buf[64] = {0};
	int len;
	int fd = open("hello",O_RDONLY | O_NONBLOCK);
	
	while(1) {
		len = read(fd,buf,64);
		if(*buf == 'q') {
			close(fd);
			exit(0);
		}
		write(1,buf,len);
	}

	return 0;
}
