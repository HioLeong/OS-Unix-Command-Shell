#include "input.h"

void getInputTokens(char *argv[]) {
	int i = 0;

	char buffer[512];
	char *inputs = getInput(buffer);
	printf("%s\n", inputs);
	char *pch = strtok(inputs, " ");

	while (NULL != pch) {
		argv[i++] = pch;	
		printf("%s\n", pch);
		pch = strtok(NULL, " ");
	}
}

char* getInput(char* string) {
	char *word = fgets(string, INPUT_SIZE, stdin);
	if (word != NULL) {
		strtok(string, "\n");
	}
	return word;
}
