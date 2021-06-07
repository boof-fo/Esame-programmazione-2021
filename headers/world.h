#ifndef WORLD_H
#define WORLD_H
#include <stdio.h>

#include "../headers/player.h"
#include "../headers/enemy.h"
#include "../headers/room.h"

typedef struct
{
	//TODO: inizializzare stanza ogni enterRoom
	room room[8];
	//stanza in cui si trova il personaggio
	int currentRoom;
}map;

void setCurrentRoom(map *map, int newRoom);
int getCurrentRoom(map map);

void printMap(map map);

void enterRoom(map *map, int newRoom);
void killEnemy(map *map, int enemyID);

void help();
void exitGame();

#endif