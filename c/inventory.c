#include"../headers/inventory.h"

void setInventoryPotions(inventory *inventory, int newValue)
{
	inventory->potions = newValue;
}

void setInventorySword(inventory *inventory, int newValue)
{
	inventory->sword = newValue;
}

void setInventoryChestplate(inventory *inventory, int newValue)
{
	inventory->sword = newValue;
}


int getInventoryPotions(inventory inventory)
{
	return inventory.potions;
}
int getInventorySword(inventory inventory)
{
	return inventory.sword;
}
bool getInventoryChestplate(inventory inventory)
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
	inventory->potions = inventory->potions++;
}

void removeInventoryPotion(inventory *inventory)
{
	inventory->potions = inventory->potions++;
}



void showInventory(inventory inventory)
{

	printf("\nINVENTARIO:\nPozioni: %d\nTipo di spada: ", getInventoryPotions(inventory));
	if(getInventorySword(inventory) == 0)
	{
		printf("Spada semplice");
	}else if(getInventorySword(inventory) == 1)
	{
		printf("Spada ricurva");
	}else if(getInventorySword(inventory) == 2)
	{
		printf("Alabarda");
	}
	printf("\nChestplate: ");
	if(getInventoryChestplate(inventory) == false)
	{
		printf("Non presente\n");
	}else
	{
		printf("Presente\n");
	}
}