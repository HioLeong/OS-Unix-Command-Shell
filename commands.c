#include "commands.h"
#include "initUtils.h"

void cd() {
	//printf("Change dir\n");
}

void execProcess(const char *file, const char* argv[]) {
	int i = 0;
	char* searchPaths[12]; // TODO: change to dynamic
	getSearchPaths(searchPaths);
}


void exec(const char *file, const char *argv[]) {
	char cdCommand[] = "cd";
	if (strcmp(cdCommand, file) == 0) {
		cd();
	} else {
		execProcess(file, argv);
	}
}
