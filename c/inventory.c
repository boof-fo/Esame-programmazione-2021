#include"../headers/inventory.h"

void setInventoryPotions(inventory *inventory, int newValue)
{
	inventory->potions = newValue;
}

void setInventorySword(inventory *inventory, int newValue)
{
	inventory->sword = newValue;
}

void setInventoryChestplate(inventory *inventory)
{
	inventory->sword = true;
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


void takePotion(inventory *inventory, room *room)
{
	if (getRoomPotions(*room) > 0)
	{
		removeRoomPotion(room);
		inventory->potions += 1;
		printf("Pozione raccolta\n");
	}
	else
		printf("Non ci sono pozioni. Buona fortuna :)\n");
}
void takeSword(inventory *inventory, room *room)
{
	if (getRoomSword(*room) != 0)
	{
		removeRoomSword(room);
		inventory->potions += 1;
		printf("Spada raccolta\n");
	}
	else
		printf("Non ci sono spade nella stanza. ¯\_(ツ)_/¯\n");
}
void takeArmor(inventory *inventory, room *room)
{
	if (getRoomChestplate(*room) > 0)
	{
		removeRoomPotion(room);
		inventory->potions += 1;
		printf("Pozione raccolta\n");
	}
	else
		printf("Non ci sono armature nella stanza. ¯\_(ツ)_/¯\n");
}

void removeInventoryPotion(inventory *inventory)
{
	inventory->potions = inventory->potions++;
}



void showInventory(inventory inventory)
{

	printf("\nINVENTARIO:\nPozioni: %d\n", getInventoryPotions(inventory));

	printf("Tipo di spada: ");
	if(getInventorySword(inventory) == 0)
	{
		printf("Spada semplice\n");
	}else if(getInventorySword(inventory) == 1)
	{
		printf("Spada ricurva\n");
	}else if(getInventorySword(inventory) == 2)
	{
		printf("Alabarda\n");
	}

	printf("Chestplate: ");
	if(getInventoryChestplate(inventory) == false)
	{
		printf("Non presente\n");
	}else
	{
		printf("Presente\n");
	}
}