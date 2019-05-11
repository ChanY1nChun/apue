#include <unistd.h>
#include <stdio.h>

int main() {
	
	char buf[64] = {0};
	getcwd(buf, 64);
	printf("current dir:%s\n ", buf);
	
	return 0;
}
