// #include <readline/readline.h>
// #include <readline/history.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	char* input = readline("Enter a string: ");
	add_history(input);
	printf("You entered: %s\n", input);
	rl_clear_history();
	// rl_clear_history();
	free(input);
	return 0;
}