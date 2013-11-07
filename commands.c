#include "commands.h"

int processExists(char* file, char* searchPaths[]) {
	return 1;
}

void cd(char *argv[]) {
	char *requested = argv[1];
	char *home = getHome();
	char newDir[80];

	strcat(newDir, home);
	strcat(newDir, "/");
	strcat(newDir, requested);
	
	if (pathExists(newDir) == 1) {
		setHome(newDir);
	} else {
		printf("No such file or directory\n");
	}
}

void execProcess(char *file,  char* argv[]) {
	char* searchPaths[12]; 
	getSearchPaths(searchPaths);
}

void exec() {

	char buffer[512];
	char *inputs = getInput(buffer);

	int i = 0;
	char *argv[12];

	char *pch = strtok(inputs, " ");
	while (NULL != pch) {
		argv[i++] = pch;
		pch = strtok(NULL, " ");
	}

	char *cdCommand = "cd";
	if (strcmp(argv[0], cdCommand) == 0) {
		cd(argv);
	} else {
		printf("process");
	}
}


