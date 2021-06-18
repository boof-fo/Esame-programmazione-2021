//Modulo utilizzato per il parsing dei comandi da tastiera.
#ifndef COMMANDS_H
#define COMMANDS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0

#include "../headers/string.h"
#include "../headers/list.h"
#include "../headers/actions.h"

void parsing(list commands,list item1, list item2, list item3, list attr6);

#endif