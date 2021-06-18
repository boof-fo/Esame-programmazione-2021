/*Modulo contenente le azioni che il giocatore può svolgere.*/
#ifndef ACTIONS_H
#define ACTIONS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/world.h"
#include "../headers/string.h"
#include "../headers/enemy.h"

void answerPuzzle(map *map);
void aiuto();
void attraversa(map *map);
//void takeLoot(map *map);

#endif