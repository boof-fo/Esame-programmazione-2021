//Modulo contenente le azioni che il giocatore può svolgere.
#ifndef ACTIONS_H
#define ACTIONS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/world.h"
#include "../headers/string.h"
#include "../headers/enemy.h"

//funzioni eseguite dal comando "prendi"
void takePotion(player *player, room *room);
void takeSword(player *player, room *room);
void takeChestplate(player *player, room *room);

void answerPuzzle(map *map);
void aiuto();
void attraversa(map *map);

void usePotion(player *player);

#endif