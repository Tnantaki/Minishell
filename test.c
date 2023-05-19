#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef enum e_reoptr
{
	STDOUT,
	is_stdout,
	is_heredoc,
	is_append,
	is_pipe,
}	t_reoptr;

enum week {monday = 1, tuesday, wednesday, thurday, firday, saturday, sunday};

void	ft_check(int *i, int *b)
{
	printf("i: %d\n", *i);
	printf("b: %d\n", *b);
}

int	main(void)
{
	// enum week day;
	// day = sunday;

	int	i;
	int	*b;
	
	i = 0;
	b = &i;
	ft_check(b++, b);
	// printf("i: %d\n", i);
	// printf("%lu\n", sizeof(t_reoptr));
	// printf("%s\n", FILENAME);
	// printf("%d\n", getppid());

}

