#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <aio.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
int main() {
	
	struct aiocb myaio;
	char buf[64] = {0};
	int fd, ret;
	
	bzero((char*)&myaio, sizeof(myaio));
	
	myaio.aio_fildes = STDIN_FILENO;
	myaio.aio_offset = 0;
	myaio.aio_nbytes = 64;
	myaio.aio_buf = buf;


	aio_read(&myaio);

	while(aio_error(&myaio) == EINPROGRESS)
		sleep(1);
	
	ret = aio_return(&myaio);

	printf("context: %s, return %d\n", buf, ret);

	return 0;
}
