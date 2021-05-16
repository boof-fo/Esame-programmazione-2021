#ifndef PLAYER_H
#define PLAYER_H

#include "inventory.h"

//struttura del giocatore
typedef struct{
	//punti vita
	int HP;
	//punti danno
	int damage;
	//stanza in cui si trova il personaggio
	int currentRoom;
	//inventario
	inventory inventory;
}player;


void setPlayerDamage(player *player, int damage);
void setPlayerHP(player *player, int HP);

void spawnPlayer(player *player);

#endif