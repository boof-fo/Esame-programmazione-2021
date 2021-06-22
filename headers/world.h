//Modulo contenente strutture dati e funzioni relative al mondo di gioco.
#ifndef WORLD_H
#define WORLD_H
#include <stdio.h>

#include "../headers/player.h"
#include "../headers/inventory.h"
#include "../headers/enemy.h"
#include "../headers/room.h"

//Struttura del mondo
typedef struct
{
	//Stanze della fortezza
	room room[8];
	//stanza in cui si trova il personaggio
	int current_room;
}map;

//genera la mappa di gioco
map game_map;

//genera giocatore
player game_player;

//Imposta i valori di ogni stanza del mondo
void spawnWorld(map *map);

//Mostra la mappa della fortezza usando caratteri ASCII
void printMap(map map, inventory inventory);

//imposta/ritorna la stanza in cui si trova il giocatore
void setCurrentRoom(map *map, int new_room_ID);
int getCurrentRoom(map map);

//cambia la stanza in cui si trova il giocatore e imposta i valori della stanza
void enterRoom(map *map, player player, int new_room_ID);
//imposta la configurazione nemici della stanza in base a quale nemico viene ammazzato.
void killEnemy(map *map, int enemy_ID);

//premi invio per continuare
void enterToContinue();

//fine del gioco
void ending();


#endif