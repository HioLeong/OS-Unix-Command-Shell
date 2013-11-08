#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "input.h"
#include "initUtils.h"
//#include "commands.h"
#include "utils.h"


void cd(char *argv[]);
void execProcess(char *file, char *argv[]);
void exec();
void shell();
void init();
