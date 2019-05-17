#include <unistd.h>

int main(int argc, char **argv) {
	
	rmdir(argv[1]);

	return 0;
}
