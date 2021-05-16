#include <stdio.h>
#include <stdlib.h>


#include "map.h"

//imposta il numero di pozioni in una stanza
void setRoomPotions(room *room, int num)
{
	room->potions = num;
}

//imposta l'ID della spada in una stanza
void setRoomSword(room *room, int num)
{
	room->sword = num;
}

//presenza armatura
void setRoomChestplate(room *room, bool plate)
{
	room->chestplate = plate;
}

//imposta il numero di nemici
void setRoomEnemiesNum(room *room, int n)
{
	room->enemiesNumber = n;
}


//imposta i valori di una stanza
void spawnRoom(room* room, int potions, int sword, bool chestplate, int enemyNumber)
{
	setRoomPotions(room, potions);
	setRoomSword(room, sword);
	setRoomChestplate(room, chestplate);
	setRoomEnemiesNum(room, enemyNumber);
}




void spawnMap(map *map)
{
	int i = 0;
	int potions, sword;
	bool chestplate;
	int enemiesNumber;

	while (i < 7)
	{
		if (i == 0)
		{
			potions = 0;
			sword = 0;
			chestplate = false;
			enemiesNumber = 0;
		}
		if (i == 1 || i == 2)
		{
			potions = 1;
			sword = 0;
			chestplate = false;
			enemiesNumber = 1;
		}
		if (i == 3)
		{
			potions = 1;
			sword = 1;
			chestplate = true;
			enemiesNumber = 2;
		}
		if (i == 4 || i == 5)
		{
			potions = 2;
			sword = 2;
			chestplate = false;
			enemiesNumber = 2;
		}
		if (i == 6)
		{
			potions = 1;
			sword = 1;
			chestplate = false;
			enemiesNumber = 1;
		}

		spawnRoom(&map->room[i], potions, sword, chestplate, enemiesNumber);
		i++;
	}
}
