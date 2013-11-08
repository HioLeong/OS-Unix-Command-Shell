#include "shell.h"

void cd(char *argv[]) {
	char *requested = argv[1];
	char *home = getHome();
	char newDir[512];

	memset(newDir, 0, sizeof(newDir));

	strcat(newDir, home);
	strcat(newDir, "/");
	strcat(newDir, requested);

	if (pathExists(newDir) == 1) {
		//XXX: set the home directory to be long enough
		setHome(newDir);
	} else {
		printf("No such file or directory\n");
	}
}

void exec() {
	printf("%s> ", getHome());
	char buffer[512];
	char *inputs;

	inputs = getInput(buffer);

	int i = 0;
	char *argv[5];
	for (i = 0; i < 5; i++) {
		argv[i] = NULL;
	}

	i = 0;
	char *pch = strtok(inputs, " ");
	while (NULL != pch) {
		argv[i++] = pch;
		pch = strtok(NULL, " ");
	}


	char *cdCommand = "cd";

	if (strcmp(argv[0], cdCommand) == 0) {
		cd(argv);
	} else {
		int i = 0;

		char **searchPaths = getSearchPaths();
		char procPath[512];
		bool procFound = false;

		i = 0;
		while (strlen(searchPaths[i]) > 0) {
			memset(procPath, 0, sizeof(procPath));

			//TODO: refactor
			strcat(procPath, searchPaths[i]);
			strcat(procPath, "/");
			strcat(procPath, argv[0]);

			if (fileExists(procPath) == true) {
				procFound = true;
				break;
			}
			i++;
		}

		if (procFound) {
			//if ((pid = fork()) == 0) {
			pid_t id = fork();
			if ((id = fork()) == -1) { 
				printf("fork failed\n");
			} else if (id == 0) {
				execv(procPath, argv);
			} else {
				waitpid(id, 0, 0);
			}

		} else {
			printf("Command not found\n");
		}
	}

}

int main() {
	init();
	while (1) {
		exec();
	}
	return 1;
}

void shell() {
	init();
}

void init() {
	char* temp;
	char* strings[14];
	getProfileVariables(); // update the home and path environment variables
}


