#ifndef FILES_H
#define FILES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void readFile(char *filename);
void readFileLine(char *filename, int lineNum);
void readFileRandomLine(char *filename);

#endif