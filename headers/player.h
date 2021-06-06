#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>

#include "../headers/inventory.h"

//struttura del giocatore
typedef struct{
	//punti vita
	int HP;
	//punti danno
	int damage;
	//punti protezione dati dall'armatura
	int protection;
	//inventario
	inventory inventory;
}player;


void setPlayerHP(player *player, int HP);
void setPlayerDamage(player *player, int damage);
void setPlayerProtection(player *player, int protectionPoints);
void setSword(player *player, int swordType);
void setChestplate(player *player);

int getPlayerHP(player player);

//imposta i valori predefiniti
void spawnPlayer(player *player);

void playerReceiveDamage(player *player, int damage);

void usePotion(player *player);

#endif