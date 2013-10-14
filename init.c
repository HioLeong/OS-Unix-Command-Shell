#include <stdio.h>
#include <regex.h>
#include <string.h>
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

char* getOption(char* name) {
	regex_t regex;
	int reti;
	char msgbuf[100];
	char* 


	reti = regexcomp(&regex, "HOME=.*",0);
	if (reti) {
		exit(1);
	}
}
