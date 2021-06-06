#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>

#include "../headers/inventory.h"

//struttura del giocatore
typedef extern struct{
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
int getPlayerHP(player player);
void setPlayerDamage(player *player, int damage);
void setPlayerProtection(player *player, int protectionPoints);
void setSword(player *player, int swordType);
void setChestplate(player *player);

//imposta i valori predefiniti
void spawnPlayer(player *player);



void playerReceiveDamage(player *player, int damage);

void usePotion(player *player);

#endif