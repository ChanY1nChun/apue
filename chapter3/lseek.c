#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
	
	int fd1 = open(argv[1],O_RDONLY);
	int fd2 = open(argv[2],O_CREAT|O_WRONLY,0666);
	
	char buf[64] = {0};

	lseek(fd1,6,SEEK_SET);
	int len = read(fd1,buf,64);
	write(fd2,buf,len);

	close(fd1);
	close(fd2);


	return 0;
}
