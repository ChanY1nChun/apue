#include <unistd.h>
#include <stdlib.h>
int main(int argc, char **argv) {
	
	int len = atoi(argv[2]);
	truncate(argv[1],len);
	
	return 0;
}
