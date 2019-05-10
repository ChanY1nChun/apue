#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main(int argc, char **argv) {
	
	chdir(argv[1]);
	char *buf = "succeed!";
	int fd = open("chdir_test.txt", O_CREAT | O_WRONLY, 0744);
	write(fd, buf, 9);
	
	close(fd);

	return 0;
}
