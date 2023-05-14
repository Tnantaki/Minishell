#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef enum e_reoptr
{
	is_stdin,
	is_stdout,
	is_heredoc,
	is_append,
	is_pipe,
}	t_reoptr;


// int	main(void)
// {
// 	char	*input;

// 	input = "Hello";
// 	printf("You entered: %s\n", input);
// 	// free(input);
// 	return (0);
// }
 
// int main(int ac, char **av, char **envp) {
//   char *binaryPath = "/usr/bin/echo"; // file name
//   char *args[] = {binaryPath, "Hello", NULL}; // file name and option
 
//   execve(binaryPath, args, envp);
//   return 0;
// }

int	main(int ac, char **av)
{
	// printf("%d\n", av[1][0]);
	// printf("%s\n", av[1]);
	char *str = "Hello";
	if (str[4])
		printf("str4:%c\n", str[4]);
	if (!str[5])
		printf("Work!\n");
}