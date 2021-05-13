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
	//numero di pozioni curative nella stanza
	int potions;
	//tipo di spada contenuta nella stanza
	//0 = nessuna spada; 1 = spada ricurva; 2 alabarda
	int sword;
	//1 = c'è un'armatura nella stanza
	bool chestplate;
	//numero di nemici nella stanza
	int enemiesNumber;
	//due puntatori che punteranno a variabili di tipo nemico
	//2 perché è il numero massimo di nemici in una stanza
	enemy *enemy1, *enemy2;
}room;

//imposta il numero di pozioni in una stanza
int setPotions(room *room, int num);
//imposta l'ID della spada in una stanza
int setSword(room *room, int num);
//presenza armatura
int setChestplate(room *room, bool plate);
//imposta il numero di nemici
int setEnemiesNumber(room *room, int n);
//imposta i nemici
int setEnemies(room *room, enemy *enemy1, enemy *enemy2);
//imposta i valori di una stanza
int setRoom(room* room, int potions, int sword, bool chestplate, int enemyNumber, enemy *enemy1, enemy *enemy2);


typedef struct
{
	room room[7];
	int currentRoom;
	enemy enemy[6];
}map;

int generateMap(map *map);


#endif