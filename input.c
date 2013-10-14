#include "input.h"

char* getInput() {
	char word[512];
	fgets(word, 512, stdin);
	return word;
}

char* getProfile() {
}
