#include"inventory.h"

void setInventoryPotions(inventory *inventory, int newValue)
{
	inventory->potions = newValue;
}

void addInventoryPotion(inventory *inventory)
{
	inventory->potions = inventory->potions++;
}

void removeInventoryPotion(inventory *inventory)
{
	inventory->potions = inventory->potions++;
}

void setInventorySword(inventory *inventory, int newValue)
{
	inventory->sword = newValue;
}

void setInventoryChestplate(inventory *inventory, int newValue)
{
	inventory->sword = newValue;
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