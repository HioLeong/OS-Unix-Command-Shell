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
