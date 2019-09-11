#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	char *argv[] = {"ls","-l",NULL};
	
	pid_t pid = fork();
	if(pid > 0)
		printf("father\n");
	if(pid == 0) {
		execvp("ls",argv);
		return 0;
	}	



	return 0;
}
