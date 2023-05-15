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

int	main(int ac, char **av)
{
	enum week day;
	day = sunday;

	// printf("%lu\n", sizeof(t_reoptr));
	// printf("%s\n", FILENAME);
	printf("%d\n", getppid());

}

