#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0

#include "map.h"

//imposta il numero di pozioni in una stanza
int setPotions(room *room, int num)
{
	room->potions = num;
}

//imposta l'ID della spada in una stanza
int setSword(room *room, int num)
{
	room->sword = num;
}

//presenza armatura
int setChestplate(room *room, bool plate)
{
	room->chestplate = plate;
}

//imposta il numero di nemici
int setEnemiesNumber(room *room, int n)
{
	room->enemiesNumber = n;
}

//imposta i nemici
int setEnemies(room *room, enemy *enemy1, enemy *enemy2)
{
	room->enemy1 = malloc(sizeof(enemy));
	room->enemy2 = malloc(sizeof(enemy));
	room->enemy1 = enemy1;
	room->enemy2 = enemy2;
}



//imposta i valori di una stanza
int setRoom(room* room, int potions, int sword, bool chestplate, int enemyNumber, enemy *enemy1, enemy *enemy2)
{
	setPotions(room, potions);
	setSword(room, sword);
	setChestplate(room, chestplate);
	setEnemiesNumber(room, enemyNumber);
	setEnemies(room, enemy1, enemy2);
}




int generateMap(map *map)
{
	int i = 0;
	int potions, sword;
	bool chestplate;
	int enemiesNumber;
	enemy *enemy1, *enemy2;

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
			enemy1 = &map->enemy[0];
		}
		if (i == 3)
		{
			potions = 1;
			sword = 1;
			chestplate = true;
			enemiesNumber = 2;
			enemy1 = &map->enemy[1];
			enemy2 = &map->enemy[2];
		}
		if (i == 4 || i == 5)
		{
			potions = 2;
			sword = 2;
			chestplate = false;
			enemiesNumber = 2;
			enemy1 = &map->enemy[3];
			enemy2 = &map->enemy[4];
		}
		if (i == 6)
		{
			potions = 1;
			sword = 1;
			chestplate = false;
			enemiesNumber = 1;
			enemy1 = &map->enemy[5];
		}

		setRoom(&map->room[i], potions, sword, chestplate, enemiesNumber, enemy1, enemy2);
		i++;
	}
}
