#ifndef WORLD_H
#define WORLD_H
#include <stdio.h>

#include "../headers/player.h"
#include "../headers/enemy.h"
#include "../headers/room.h"

typedef struct
{
	room room[8];
	//stanza in cui si trova il personaggio
	int currentRoom;

}map;

//genera la mappa di gioco
map gameMap;

//genera giocatore
player gamePlayer;

void setCurrentRoom(map *map, int newRoom);
int getCurrentRoom(map map);

void printMap(map map);

void attraversa(map *map);
void enterRoom(map *map, int newRoom);
void killEnemy(map *map, int enemyID);

void answerPuzzle(map *map);

void help();
void exitGame();

//TODO: i print belli di fine gioco nella stanza 6 (attraversa) 

#endif