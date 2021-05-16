#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0


typedef struct{
	//numero di pozioni curative
	int potions;
	//tipo di spada
	//0 = spada iniziale; 1 = spada ricurva; 2 alabarda
	int sword;
	//1 = chestplate presente
	bool chestplate;
}inventory;

void setInventoryPotions(inventory *inventory, int newValue);
void addInventoryPotion(inventory *inventory);
void removeInventoryPotion(inventory *inventory);

void setInventorySword(inventory *inventory, int type);
void setInventoryChestplate(inventory *inventory, int newValue);

void spawnInventory(inventory *inventory)
{
	setInventoryPotions(inventory, 0);
	setInventorySword(inventory, 0);
	setInventoryChestplate(inventory, 0);
}

#endif