#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdio.h>

#include "../headers/room.h"

typedef int bool;
#define true 1
#define false 0


typedef struct{
	//numero di pozioni curative
	int potions;
	//tipo di spada
	//0 = spada semplice; 1 = spada ricurva; 2 alabarda
	int sword;
	//1 = chestplate presente
	bool chestplate;
}inventory;

void setInventoryPotions(inventory *inventory, int newValue);
void setInventorySword(inventory *inventory, int type);
void setInventoryChestplate(inventory *inventory);

int getInventoryPotions(inventory inventory);
int getInventorySword(inventory inventory);
int getInventoryChestplate(inventory inventory);

void setInventory(inventory *inventory, int potions, int swordType, int chestplate);

void spawnInventory(inventory *inventory);

void takePotion(inventory *inventory, room *room);
void takeSword(inventory *inventory, room *room);
void takeChestplate(inventory *inventory, room *room);
void removeInventoryPotion(inventory *inventory);

void showInventory(inventory inventory);

#endif