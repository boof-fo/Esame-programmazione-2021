#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0

#include "enemy.h"


//struttura di una stanza
typedef struct
{
	//numero della stanza (da 0 a 6)
	int ID;
	//descrizione che verra visualizzata entrando nella stanza
	char descrizione[50];
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

//imposta il numero di pozioni in una stanza
void setPotions(room *room, int num);
//imposta l'ID della spada in una stanza
void setSword(room *room, int num);
//presenza armatura
void setChestplate(room *room, bool plate);
//imposta il numero di nemici
void setEnemiesNumber(room *room, int n);
//imposta i valori di una stanza
void setRoom(room* room, int potions, int sword, bool chestplate, int enemyNumber);


typedef struct
{
	room room[7];
	int currentRoom;
	enemy enemy[2];
}map;

void generateMap(map *map);


#endif