//Modulo contenente strutture dati e funzioni relative all'inventario
#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdio.h>

#include "../headers/bool.h"

typedef struct
{
	//numero di pozioni curative
	int potions;
	/**tipo di spada
	 *0 = spada semplice; 1 = spada ricurva; 2 alabarda; 3 spada protettiva; 4 spada succhiavita 
	 */
	int sword;
	//1 = chestplate presente
	int chestplate;
	//mappa
	bool map;
	//tesoro di fine gioco
	bool treasure;
}inventory;


void setInventoryPotions(inventory *inventory, int potions_number);
int getInventoryPotions(inventory inventory);

void setInventorySword(inventory *inventory, int swordTyper);
int getInventorySword(inventory inventory);

void setInventoryChestplate(inventory *inventory, int chestplateType);
int getInventoryChestplate(inventory inventory);

void setInventoryMap(inventory *inventory, bool map);
bool mapIsPresent(inventory inventory);

void setInventoryTreasure(inventory *inventory, bool treasure);
bool treasureIsPresent(inventory inventory);

void spawnInventory(inventory *inventory);
void setInventory(inventory *inventory, int potions, int swordType, int chestplate);

void addInventoryPotion(inventory *inventory);
void removeInventoryPotion(inventory *inventory);

void emptyInventory(inventory *inventory);


#endif