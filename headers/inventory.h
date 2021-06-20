//Modulo contenente strutture dati e funzioni relative all'inventario
#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdio.h>

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
}inventory;


void setInventoryPotions(inventory *inventory, int potions_number);
int getInventoryPotions(inventory inventory);

void setInventorySword(inventory *inventory, int swordTyper);
int getInventorySword(inventory inventory);

void setInventoryChestplate(inventory *inventory, int chestplateType);
int getInventoryChestplate(inventory inventory);

void setInventory(inventory *inventory, int potions, int swordType, int chestplate);

void spawnInventory(inventory *inventory);

void addInventoryPotion(inventory *inventory);
void removeInventoryPotion(inventory *inventory);

void emptyInventory(inventory *inventory);

#endif