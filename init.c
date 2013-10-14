#include "init.h"

char home[512];
char path[512];

int getProfile() {
	FILE *profile;
	char line[80];

	profile = fopen("profile","rt");

	if (NULL == profile) {
		printf("Profile does not exist");
		return -1;
	}

	while (fgets(line, 80, profile) != NULL) {

		printf("%s\n", line);
	}
	return 0;
}

char* getPath() {
}

char* getHome() {
}

int getOption(char* name, char* input){

	char* reti = strpbrk(name,input);


	if (NULL != reti) {
		return 1;
	} else {
		return 0;
	}
}
