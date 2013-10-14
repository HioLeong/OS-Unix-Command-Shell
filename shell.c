#include <string.h>
#include "shell.h"
#include "input.h"
#include "init.h"

//TODO: set constant size
char home[512];
char path[512];

int main() {
	shell();
	return 1;
}

void shell() {
	init();
	while (1) {
		printf("> ");
		char* input = getInput();
	}
}

void init() {
	char* sub = strpbrk("test", "es");
	printf("%s\n", sub);
}

