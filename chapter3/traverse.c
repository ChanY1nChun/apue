#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
int main(int agrc, char **argv) {
	
	struct dirent *dir = NULL; 
	DIR *dp = opendir(argv[1]);
	
	while((dir = readdir(dp)) != NULL)
		printf("%ld----%s\n",dir->d_ino,dir->d_name);
	
	closedir(dp);
	return 0;
}
