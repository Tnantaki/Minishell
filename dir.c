#include <stdio.h>
#include <dirent.h>
// #include <sys/types.h>

int main() {
	DIR *dir;
	struct dirent *entry;
	printf("size:%ld\n", sizeof(*dir));

	dir = opendir("learn"); // Replace with the actual directory path

	if (dir == NULL) {
		printf("Failed to open directory.\n");
		return 1;
	}

	while ((entry = readdir(dir)) != NULL) {
		printf("%s\n", entry->d_name);
	}

	closedir(dir);

	return 0;
}
