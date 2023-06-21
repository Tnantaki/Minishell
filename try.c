#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int	main(void)
{
	int i = 0;

	while (++i < 5)
	{
		if (i % 2 == 0)
		{
			printf("i: is even\n");
			sleep(1);
			continue;
		}
		printf("i:%d\n", i);
		sleep(1);
	}
	// 	return (true);
	// return (err_cmd_exec(2, name, NULL), false);

}