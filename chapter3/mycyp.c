#include <unistd.h>
#include <fcntl.h>


#define BUFFSIZE 4096
int main( int argc, char **argv) {
    
	int fd1 = open(argv[1],O_RDONLY);
	int fd2 = open(argv[2],O_CREAT|O_WRONLY, 0666);

	int len = 0;
	
	char buf[BUFFSIZE] = {0};
	
	while((len = read(fd1,buf,BUFFSIZE)) > 0)
		write(fd2,buf,len);
	
	close(fd1);
	close(fd2);

	return 0;
}
