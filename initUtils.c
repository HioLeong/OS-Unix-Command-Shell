#include "initUtils.h"

char home[512];
char path[512];

int getProfileVariables() {
	FILE *profile;
	char line[512];
	int reti;

	profile = fopen("profile","rt");

	if (NULL == profile) {
		printf("Profile does not exist");
		return -1;
	}

	while (fgets(line, 512, profile) != NULL) {
		reti = updateOption("HOME", line); // returns 1 
		reti = updateOption("PATH", line);
	}
	return 0;
}

void printPath() {
	printf("%s", path);
}

void printHome() {
	home[strlen(home) ] = '\0';
	printf("%s", home);
}

void setPath(char* inputPath) {
	path[strlen(path) ] = '\0';
	strcpy(path, inputPath);
}

void setHome(char* inputHome) {
	strcpy(home, inputHome);
	home[strlen(inputHome) - 1] = '\0';
}

char* getHome() {
	return home;
}

void getSearchPaths(char* strings[]) {
	if (NULL == strings) {
		printf("error");
		return;
	}

	int i = 0;
	char *pch = strtok(path, ":");
	while (NULL != pch) {
		strings[i++] = pch;
		pch = strtok(NULL, ":");
	}
}

int updateOption(char* name, char* input){
	if (strstr(input, name) != NULL) {
		if (name == "HOME") {
				char *pch = strtok(input,"=");
				pch = strtok(NULL,"=");
				setHome(pch);
		} else if (name == "PATH") {
				char *pch = strtok(input,"=");
				pch = strtok(NULL,"=");
				setPath(pch);
		}

		return 1;
	} else {
		// No substring found
		return 0;
	}
}
