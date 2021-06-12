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
void setPlayerDamage(player *player, int damage);
void setPlayerProtection(player *player, int protectionPoints);
void setPlayerSword(player *player, int swordType);
void setPlayerChestplate(player *player);

int getPlayerHP(player player);
int getPlayerDamage(player player);
int getPlayerProtection(player player);
//imposta i valori predefiniti

void spawnPlayer(player *player);

void attackPlayer(player *player, int damage);

void usePotion(player *player);
void giveSwordEffects(player *player);
void removeSwordEffects(player *player);

void showInventory(player player);

#endif