//Modulo utilizzato per il parsing dei comandi da tastiera.
#ifndef PARSING_H
#define PARSING_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/string.h"
#include "../headers/list.h"
#include "../headers/actions.h"

void error(int errorCode);

void parsing(list commands,list item1, list item2, list item3, list item4, list item5, list item6, list item7);


#endif