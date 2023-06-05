#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
// #include <readline/readline.h>
// #include <readline/history.h>

// int main() {
// 	while (1)
// 	{
// 		char* input = readline("Enter a string: ");
// 		// add_history(input);
// 		if (!input)
// 			printf("What!!!\n");
// 		// printf("1:%d\n", input[0]);
// 		// printf("2:%d\n", input[1]);
// 		// printf("3:%d\n", input[2]);
// 		// printf("4:%d\n", input[3]);
// 		// printf("5:%d\n", input[4]);
// 		// printf("6:%d\n", input[5]);
// 		// printf("7:%d\n", input[6]);
// 		// printf("8:%d\n", input[7]);
// 		// printf("9:%d\n", input[8]);
// 		// printf("You entered: %s\n", input);
// 		rl_on_new_line();
// 		// printf("\n"); // Move to a new line
// 		// printf("Messege to the users.\n");
// 		free(input);
// 		// exit(0);
// 	}
// 	return 0;
// }

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
int main() {
	// while (1)
	// {
	// 	char* input = readline("Enter a string: ");
	// 	add_history(input);
	// 	printf("You entered: %s\n", input);
	// 	// rl_on_new_line(); // Move to a new line
	// 	// printf("This is a new message.\n");
	// 	free(input);
	// }
	// char	*s1 = "Hello";
	// char	*s2 = "Hela";
	char	*s1 = NULL;
	char	*s2 = NULL;
	int car = ft_strcmp(s1, s2);
	if (car == 0)
		printf("String is equal\n");
	else
		printf("Diff :%d\n", car);
	return 0;
}