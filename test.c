#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>

int main() {
	char* input = readline("Enter a string: ");
	printf("You entered: %s\n", input);
	free(input);
	return 0;
}