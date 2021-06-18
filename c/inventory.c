#include"../headers/inventory.h"

void setInventorySword(inventory *inventory, int newValue)
{
	inventory->sword = newValue;
}

void setInventoryChestplate(inventory *inventory, int chestplateType)
{
	inventory->chestplate = chestplateType;
}


int getInventoryPotions(inventory inventory)
{
	return inventory.potions;
}
int getInventorySword(inventory inventory)
{
	return inventory.sword;
}
int getInventoryChestplate(inventory inventory)
{
	return inventory.chestplate;
}

void setInventory(inventory *inventory, int potions, int swordType, int chestplate)
{
	inventory->potions = potions;
	inventory->sword = swordType;
	inventory->chestplate = chestplate;
}

void spawnInventory(inventory *inventory)
{
	setInventory(inventory, 0, 0, 0);
}



void addInventoryPotion(inventory *inventory)
{
	inventory->potions += 1;
}
void removeInventoryPotion(inventory *inventory)
{
	inventory->potions -= 1;
}
