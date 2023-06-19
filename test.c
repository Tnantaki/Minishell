#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
 
int main(int ac, char **av, char **envp) {
	// int fd = open("./infile.txt", O_RDONLY);
	// char buf[20];
	// read(fd, buf, 10);
	// printf("%s\n", buf);
	char	*pwd;
	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	free(pwd);
	return 0;
}