#ifndef WORLD_H
#define WORLD_H
#include <stdio.h>

#include "../headers/player.h"
#include "../headers/enemy.h"
#include "../headers/room.h"

typedef struct
{
	room room;
	enemy enemy[2];
}map;

void printMap(player player);
void setCurrentRoom(map *map, player *player, int newRoom);
void spawnMap(map *map);

void killEnemy(map *map, int enemyID);

void help();
void exitGame();

#endif