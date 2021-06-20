//Modulo contenente strutture dati e funzioni relative al giocatore
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

//imposta/ritorna i punti vita del giocatore
void setPlayerHP(player *player, int health_points);
int getPlayerHP(player player);

//imposta/ritorna i punti danno del giocatore
void setPlayerDamage(player *player, int damage_points);
int getPlayerDamage(player player);

//imposta/ritorna i punti protezione del giocatore
void setPlayerProtection(player *player, int protection_points);
int getPlayerProtection(player player);

//Applica/rimuovi gli effetti di una spada
void giveSwordEffects(player *player);
void removeSwordEffects(player *player);

//imposta una spada con i suoi punti danno ed i suoi effetti
void setPlayerSword(player *player, int sword_ID);
int getPlayerSword(player player);

//imposta i valori predefiniti
void spawnPlayer(player *player);

//aumenta/ diminuisci la protezione di 10 punti
void raisePlayerProtection(player *player);
void lowerPlayerProtection(player *player);

//mostra il contenuto dell'inventario
void showInventory(player player);

#endif