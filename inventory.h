#ifndef INVENTORY_H
#define INVENTORY_H

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

void setInventory(inventory *inventory, int potions, int swordType, int chestplate);

void spawnInventory(inventory *inventory);




#endif