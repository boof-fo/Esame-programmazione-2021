#include"../headers/inventory.h"

void setLetterID(letter *letter, int ID)
{
	letter->ID = ID;
}
int getLetterID(letter letter)
{
	return letter->ID;
}

void setLetterExists(letter *letter)
{
	letter->exists = true;
}
bool getLetterExists(letter letter)
{
	return letter->exists;
}
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
int getInventoryChestplate(inventory inventory)
{
	return inventory.chestplate;
}

int setLetter(inventory *inventory, int ID)
{
	//TODO: if letter exists
	setLetterExists(inventory->letter[i]);
	setLetterID(ID);
	char content[];
	if(ID == 0)
	{
		content = "ciao";
		setLetterContent(content[]);
		getLetterContent(inventory.letters[0]);
	}
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
