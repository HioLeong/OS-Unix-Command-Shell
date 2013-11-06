#include "shell.h"

int main() {
	//shell();
	printf("> ");
	//char buffer[512];
	//char* input = getInput(buffer);
	//printf("%s\n" , input);

	char* values[15];
	getInputTokens(values);


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
	const char* paramList[] = {"a","b"};
	const char* command = "ls";
	exec(command, paramList);
}

