#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	ch = chdir("../..");
	char	cwd[256];

	if (ch < 0)
		perror("error");
	else
	{
		printf("change success!\n");
		if (getcwd(cwd, sizeof(cwd)) == NULL)
			perror("error");
		else
			printf("currently at: %s\n", cwd);
	}
	return (0);
}