#include "utils.h"

int pathExists(char *path) {
	DIR *dir = opendir(path);
	if (NULL != dir) {
		closedir(dir);
		return 1;
	} else {
		return 0;
	}
}

int fileExists(char *file) {
	if (access(file, F_OK) != -1) {
		return 1;
	} else {
		return 0;
	}
}

void prompt(char *name, char *message) {
	printf("%s: %s\n", name, message);
}
