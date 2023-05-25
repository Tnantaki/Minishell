#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_number_struct
{
	int	arg;
	int	in;
	int	out;
	int	pipe;
}	t_nb;
void	add(char *str)
{
	str[0] = 'A';
	str++;
	str[0] = 'B';
}

int main()
{
	// char *str = strdup("Hello");

	// add(str);
	// printf("%s\n", str);
	char *tmp = getenv("PATH");
	printf("%s\n", tmp);
	return (0);
}
