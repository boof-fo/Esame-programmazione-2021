#include <stdio.h>
#include <stdlib.h>

#include"inventory.h"

void setInventoryPotions(inventory *inventory, int newValue)
{
	inventory->potions = newValue;
}

void addInventoryPotion(inventory *inventory)
{
	inventory->potions = ++inventory->potions;
}

void removeInventoryPotion(inventory *inventory)
{
	inventory->potions = --inventory->potions;
}

void setInventorySword(inventory *inventory, int newValue)
{
	inventory->sword = newValue;
}

void setInventoryChestplate(inventory *inventory, int newValue)
{
	inventory->sword = newValue;
}

#include "player.h"


