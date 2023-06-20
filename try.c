#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int	main(void)
{
	DIR	*dir;
	struct stat	info;
	char	*name = "out1feff";

	if (stat(name, &info) != 0)
		perror(NULL);
		// printf("File not found\n");
	if (S_ISDIR(info.st_mode))
		printf("is dir\n");
	else if (S_ISREG(info.st_mode))
		printf("is file\n");
	// if (access(name, F_OK) == 0)
	// 	printf("Can access\n");
	// if (access(name, X_OK) == 0)
	// 	printf("Can exec\n");
	// dir = opendir(name);
	// if (dir)
	// 	printf("can open\n");
	// else
	// 	printf("can not open\n");
	// if (chdir(name) == -1)
	// 	printf("can cd\n");
		
	// if (access(name, F_OK) == 0)
	// 	return (true);
	// return (err_cmd_exec(2, name, NULL), false);

}