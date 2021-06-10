#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdio.h>


typedef int bool;
#define true 1
#define false 0

typedef struct
{
	int ID;
	bool exists;
	char content[50];
}letter;

typedef struct
{
	//numero di pozioni curative
	int potions;
	//tipo di spada
	//0 = spada semplice; 1 = spada ricurva; 2 alabarda
	int sword;
	//1 = chestplate presente
	int chestplate;
	//lettere
	letter letters[3];
}inventory;

void setLetterID(letter *letter , int ID);
int getLetterID(letter *letter);
void setLetterExists(*letter letter);
bool getLetterExists(letter letter);
void setLetterContent(*letter letter);


void setInventoryPotions(inventory *inventory, int newValue);
void setInventorySword(inventory *inventory, int type);
void setInventoryChestplate(inventory *inventory);

int getInventoryPotions(inventory inventory);
int getInventorySword(inventory inventory);
int getInventoryChestplate(inventory inventory);

int setLetter(inventory *inventory, char content[]);

void setInventory(inventory *inventory, int potions, int swordType, int chestplate);

void spawnInventory(inventory *inventory);

void addInventoryPotion(inventory *inventory);
void removeInventoryPotion(inventory *inventory);


#endif