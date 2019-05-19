#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
	
	struct stat st;
	int i;
	char *ptr;

	for(i = 1; i < argc; ++i) {
		printf("%s:",argv[i]);
		lstat(argv[i],&st);
		
		if(S_ISREG(st.st_mode))
			ptr = "regular";
		else if(S_ISDIR(st.st_mode))
			ptr = "directory";
		else if(S_ISCHR(st.st_mode))
			ptr = "character special";
		else if(S_ISBLK(st.st_mode))
			ptr = "block special";
		else if(S_ISFIFO(st.st_mode))
			ptr = "fifo";
		else if(S_ISLNK(st.st_mode))
			ptr = "symbolic link";
		else if(S_ISSOCK(st.st_mode))
			ptr = "socket";
		else
			ptr = "unknown mode";
		
		printf("%s\n", ptr);
	}
	

	return 0;
}
