#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <fcntl.h>
#include <sys/wait.h>

int	mystdin = STDIN_FILENO;
int	mystdout = STDOUT_FILENO;
void	set_null(char **path)
{
	path = NULL;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main()
{
	// int	savein = dup(mystdin);
	// int fd = open("infile.txt", O_RDONLY);
	// // int fd = dup(STDIN_FILENO);
	// dup2(fd, mystdin);
	// printf("fd:%d\n", mystdin);
	// // if (!isatty(mystdin))
	// // 	dup2(fd, mystdin);

	// if (isatty(savein)) {
	// 	printf("Input is connected to a terminal.\n");
	// } else {
	// 	printf("Input is not connected to a terminal.\n");
	// }
	char *str = "";
	ft_strlen(str);
	if (*str)
		printf("Hel\n");
	return 0;
}