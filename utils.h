#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

int pathExists(char *path);
int fileExists(char *path);
void prompt(char *name, char *message);
