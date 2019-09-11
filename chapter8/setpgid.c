#include <stdio.h>
#include <unistd.h>


int main() {
	setpgid(getpid(), getppid());
	while(1);
	
	return 0;
}
