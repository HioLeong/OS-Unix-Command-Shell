#include "commands.h"
#include "initUtils.h"

void cd() {
	//printf("Change dir\n");
}

void execProcess(const char *file, const char* argv[]) {
	int i = 0;
	char* searchPaths[12]; 
	getSearchPaths(searchPaths);
	for (i = 0; i < 3; i++) {
		printf("%s\n", searchPaths[i]);
	}
}


void exec(const char *file, const char *argv[]) {
	char cdCommand[] = "cd";
	if (strcmp(cdCommand, file) == 0) {
		cd();
	} else {
		execProcess(file, argv);
	}
}
