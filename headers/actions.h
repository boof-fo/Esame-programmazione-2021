//Modulo contenente le azioni che il giocatore può svolgere.
#ifndef ACTIONS_H
#define ACTIONS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../headers/world.h"
#include "../headers/string.h"
#include "../headers/enemy.h"
#include "../headers/bool.h"

//funzioni eseguite dal comando "prendi"
void takePotion(player *player, room *room);
void takeSword(player *player, room *room);
void takeChestplate(player *player, room *room);
void takeMap(map *map, player *player);
void takeTreasure(map *map, player *player);

void answerPuzzle(map *map);
void help();

//Funzione utilizzata per far decidere al giocatore in quale stanza spostarsi
void walkThroughDoor(map *map, player player);

void usePotion(player *player);

//comandi per il combattimento
int attackEnemy(player *player, enemy *enemy);

void helpSelect(int selections);
#endif