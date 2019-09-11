#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <aio.h>
#include <unistd.h>
#include <errno.h>

int main() {
	
	struct aiocb myaio;
	int fd, ret;
	char buf[64] = {0};
	myaio.aio_fildes = STDIN_FILENO;
	myaio.aio_offset = 0;
	myaio.aio_buf = buf;
	myaio.aio_nbytes = 64;

	
	const struct aiocb* aio_list[5] = {NULL};
	aio_list[2] = &myaio;

	aio_read(&myaio);

	aio_suspend(aio_list, 5, NULL);
	ret = aio_return(&myaio);

	printf("context: %s, return %d\n", buf, ret);

	return 0;
}
