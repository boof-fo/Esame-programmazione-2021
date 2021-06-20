#include"../headers/inventory.h"

void setInventoryPotions(inventory *inventory, int potions_number)
{
	inventory.potions = potions_number;
}
int getInventoryPotions(inventory inventory)
{
	return inventory.potions;
}

void setInventorySword(inventory *inventory, int sword_ID)
{
	inventory->sword = sword_ID;
}
int getInventorySword(inventory inventory)
{
	return inventory.sword;
}

void setInventoryChestplate(inventory *inventory, int chestplate_ID)
{
	inventory->chestplate = chestplate_ID;
}
int getInventoryChestplate(inventory inventory)
{
	return inventory.chestplate;
}

void spawnInventory(inventory *inventory)
{
	setInventory(inventory, 0, 0, 0);
}

void setInventory(inventory *inventory, int potions_number, int sword_ID, int chestplate_ID)
{
	setInventoryPotions(inventory, potions_number);
	setInventorySword(inventory, sword_ID);
	setInventoryChestplate(inventory, chestplate_ID);
}


void addInventoryPotion(inventory *inventory)
{
	inventory->potions += 1;
}
void removeInventoryPotion(inventory *inventory)
{
	inventory->potions -= 1;
}
