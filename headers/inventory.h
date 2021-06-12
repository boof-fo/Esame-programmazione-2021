#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

typedef struct
{
	//numero di pozioni curative
	int potions;
	//tipo di spada
	//0 = spada semplice; 1 = spada ricurva; 2 alabarda; 3 spada protettiva; 4 spada succhiavita 
	int sword;
	//1 = chestplate presente
	int chestplate;
	//lettera. 
	//TODO: numero di lettere
	bool letter[10];
}inventory;

void setInventoryPotions(inventory *inventory, int newValue);
void setInventorySword(inventory *inventory, int type);
void setInventoryChestplate(inventory *inventory);

int getInventoryPotions(inventory inventory);
int getInventorySword(inventory inventory);
int getInventoryChestplate(inventory inventory);


void setInventory(inventory *inventory, int potions, int swordType, int chestplate);

void spawnInventory(inventory *inventory);

void addInventoryPotion(inventory *inventory);
void removeInventoryPotion(inventory *inventory);


#endif