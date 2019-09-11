#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char **argv) {

	char buf[64] = {0};
	int fd = open(argv[1], O_WRONLY);
	int n;
	while(1) {
		n = read(STDIN_FILENO, buf, 64);
		write(fd, buf, n);
	}

	return 0;
}
