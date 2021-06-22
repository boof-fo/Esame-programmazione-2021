//Modulo contenente la struttura "stanza"
#ifndef ROOM_H
#define ROOM_H

#include <stdio.h>

#include "../headers/enemy.h"
#include "../headers/player.h"
#include "../headers/bool.h"

//struttura di una stanza
typedef struct
{
	//numero della stanza (da 0 a 8)
	int ID;
	//numero di pozioni curative nella stanza
	int potions;
	//presenza di una mappa
	bool map;
	/*tipo di spada contenuta nella stanza
	 *0 = nessuna spada; 1 = spada ricurva; 2 alabarda
	 */
	int sword;
	//1 = armatura arruginita; 2 = armatura stilosa 
	int chestplate;
	//tesoro di fine gioco
	bool treasure;
	/*numero di nemici nella stanza
	 *0:nessun nemico;     
	 *1:un nemico nella prima posizione dell'array; 
	 *2:un nemico nella seconda posizione dell'array;
	 *3:due nemici;
	 */
	int enemies_configuration;
	enemy enemy[2];
}room;

//imposta/ritorna il numero della stanza
void setRoomID(room *room, int room_ID);
int getRoomID(room room);
//imposta/ritorna il numero di pozioni in una stanza
void setRoomPotions(room *room, int potions_number);
int getRoomPotions(room room);
//imposta/controlla se c'è una mappa
void setRoomMap(room *room, bool map);
bool getRoomMap(room room);
//imposta/ritorna l'ID della spada in una stanza
void setRoomSword(room *room, int sword_ID);
int getRoomSword(room room);
//presenza armatura
void setRoomChestplate(room *room, int chestplate_ID);
int getRoomChestplate(room room);
//tesoro di fine gioco
void setRoomTreasure(room *room, bool treasure);
bool getRoomTreasure(room room);
//imposta/ritorna il numero di nemici
void setEnemiesConfiguration(room *room, int enemies_config);
int getEnemiesConfiguration(room room);

//imposta i valori di una stanza
void populateRoom(room* room, int room_ID, int potions, int sword_ID, int chestplate_ID, int enemies_config, bool map, bool treasure);

//Controlla se un nemico è presente in una stanza
int checkEnemyPresent(room room, int target_enemy_ID);
//Controlla se la stanza non contiene oggetti
bool roomIsEmpty(room room);

//inserisci gli oggetti nella stanza e spawna i nemici
void spawnRoom(room* room, int room_ID);

//stampa una descrizione della stanza
void describeRoom(room room);

//
void removeRoomPotion(room *room);
void removeRoomSword(room *room);
void removeRoomChestplate(room *room);

#endif