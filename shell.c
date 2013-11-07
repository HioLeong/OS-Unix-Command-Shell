#include "shell.h"
#include <assert.h>

int main() {
	init();
	while (1) {
		printf("%s > ", getHome());
		exec();
	}
	return 1;
}

void execute() {
	char *const parmList[] = {"/bin/ls", "/"};
	pid_t id = fork();
	if ((id = fork()) == -1) { 
		printf("fork failed\n");
	} else if (id == 0) {
		execv("/bin/ls", parmList);
	}
}

void shell() {
	init();
}

void init() {
	char* temp;
	char* strings[14];
	getProfileVariables(); // update the home and path environment variables
}

