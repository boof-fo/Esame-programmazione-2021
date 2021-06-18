//Modulo contenente la struttura "stanza"
#ifndef ROOM_H
#define ROOM_H

#include <stdio.h>

#include "../headers/enemy.h"
#include "../headers/player.h"

//struttura di una stanza
typedef struct
{
	//numero della stanza (da 0 a 8)
	int ID;
	//numero di pozioni curative nella stanza
	int potions;
	/*tipo di spada contenuta nella stanza
	 *0 = nessuna spada; 1 = spada ricurva; 2 alabarda
	 */
	int sword;
	//1 = armatura arruginita; 2 = armatura stilosa 
	int chestplate;
	/*numero di nemici nella stanza
	 *0:nessun nemico;     
	 *1:un nemico nella prima posizione dell'array; 
	 *2:un nemico nella seconda posizione dell'array;
	 *3:due nemici;
	 */
	int enemiesConfiguration;
	enemy enemy[2];
}room;

//imposta/ritorna il numero della stanza
void setRoomID(room *room, int ID);
int getRoomID(room room);
//imposta/ritorna il numero di pozioni in una stanza
void setRoomPotions(room *room, int num);
int getRoomPotions(room room);
//imposta/ritorna l'ID della spada in una stanza
void setRoomSword(room *room, int num);
int getRoomSword(room room);
//presenza armatura
void setRoomChestplate(room *room, int plate);
int getRoomChestplate(room room);
//imposta/ritorna il numero di nemici
void setEnemiesConfiguration(room *room, int enemyConfig);
int getEnemiesConfiguration(room room);

//Controlla se un nemico è presente in una stanza
int checkEnemyPresent(room room, int targetEnemyID);

//imposta i valori di una stanza
void populateRoom(room* room, int ID, int potions, int sword, int chestplate, int enemyNumber);

//inserisci gli oggetti nella stanza e spawna i nemici
void spawnRoom(room* room, int roomNumber);

//stampa una descrizione della stanza
void describeRoom(room room, int ID);

//
void removeRoomPotion(room *room);
void removeRoomSword(room *room);
void removeRoomChestplate(room *room);

#endif