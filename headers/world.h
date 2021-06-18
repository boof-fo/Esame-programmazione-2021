//Modulo contenente strutture dati e funzioni relative al mondo di gioco.
#ifndef WORLD_H
#define WORLD_H
#include <stdio.h>

#include "../headers/player.h"
#include "../headers/enemy.h"
#include "../headers/room.h"

//Struttura del mondo
typedef struct
{
	//Stanze della fortezza
	room room[8];
	//stanza in cui si trova il personaggio
	int currentRoom;
}map;

//genera la mappa di gioco
map gameMap;

//genera giocatore
player gamePlayer;

//Imposta i valori di ogni stanza del mondo
void spawnWorld(map *map);

//imposta/ritorna la stanza in cui si trova il giocatore
void setCurrentRoom(map *map, int newRoom);
int getCurrentRoom(map map);

//Mostra la mappa della fortezza usando caratteri ASCII
void printMap(map map);

//Funzione utilizzata per far decidere al giocatore in quale stanza spostarsi
void attraversa(map *map);
//cambia la stanza in cui si trova il giocatore e imposta i valori della stanza
void enterRoom(map *map, int newRoom);
//imposta la configurazione nemici della stanza in base a quale nemico viene ammazzato.
void killEnemy(map *map, int enemyID);


#endif