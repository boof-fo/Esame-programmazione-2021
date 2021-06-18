#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>

#include "../headers/inventory.h"

//struttura del giocatore
typedef struct
{
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
int getPlayerDamage(player player);

void setPlayerProtection(player *player, int protectionPoints);
int getPlayerProtection(player player);

void setPlayerSword(player *player, int swordType);
int getPlayerSword(player player);

//imposta i valori predefiniti
void spawnPlayer(player *player);

void usePotion(player *player);
void giveSwordEffects(player *player);
void removeSwordEffects(player *player);
void raisePlayerProtection(player *player);
void lowerPlayerProtection(player *player);

void showInventory(player player);

#endif