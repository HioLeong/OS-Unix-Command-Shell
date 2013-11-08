#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "initUtils.h"
#include "input.h"

void cd(char *argv[]);
void execProcess(char *file, char *argv[]);
void exec();
