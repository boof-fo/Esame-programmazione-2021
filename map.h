#ifndef MAP_H
#define MAP_H
#include <stdio.h>

#include "enemy.h"
#include "player.h"

typedef int bool;
#define true 1
#define false 0

//struttura di una stanza
typedef struct
{
	//numero della stanza (da 0 a 6)
	int ID;
	//numero di pozioni curative nella stanza
	int potions;
	//tipo di spada contenuta nella stanza
	//0 = nessuna spada; 1 = spada ricurva; 2 alabarda
	int sword;
	//1 = c'è un'armatura nella stanza
	bool chestplate;
	//numero di nemici nella stanza
	int enemiesNumber;
}room;

//imposta il numero della stanza
void setRoomID(room *room, int ID);
//imposta il numero di pozioni in una stanza
void setRoomPotions(room *room, int num);
//imposta l'ID della spada in una stanza
void setRoomSword(room *room, int num);
//presenza armatura
void setRoomChestplate(room *room, bool plate);
//imposta il numero di nemici
void setRoomEnemiesNumber(room *room, int n);

//imposta i valori di una stanza
void populateRoom(room* room, int ID, int potions, int sword, bool chestplate, int enemyNumber);

//crea stanza
void spawnRoom(room* room, int roomNumber);

//stampa una descrizione della stanza
void describeRoom(room room, int ID);


typedef struct
{
	room room;
	enemy enemy[2];
}map;

void spawnMap(map *map);
void printMap(player player);
void setCurrentRoom(map map, player *player, int newRoom);

#endif