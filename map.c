#include "map.h"

//imposta identificativo
void setRoomID(room *room, int ID)
{
	room->ID = ID;
}
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
void populateRoom(room* room, int ID, int potions, int sword, bool chestplate, int enemyNumber)
{
	setRoomID(room, ID);
	setRoomPotions(room, potions);
	setRoomSword(room, sword);
	setRoomChestplate(room, chestplate);
	setRoomEnemiesNum(room, enemyNumber);
}

void spawnRoom(room* room, int roomNumber)
{
	if (roomNumber == 0)
		{
			populateRoom(room, 0, 0, 0, false, 0);
		}
		if (roomNumber == 1)
		{
			populateRoom(room, 1, 1, 0, false, 1);
		}
		if (roomNumber == 2)
		{
			populateRoom(room, 2, 1, 0, false, 1);
		}
		if (roomNumber == 3)
		{
			populateRoom(room, 3, 1, 1, true, 2);
		}
		if (roomNumber == 4)
		{
			populateRoom(room, 4, 2, 2, false, 2);
		}
		if (roomNumber == 5)
		{
			populateRoom(room, 5, 2, 2, false, 2);
		}
		if (roomNumber == 6)
		{
			populateRoom(room, 6, 1, 1, false, 1);
		}
}

void describeRoom(int ID)
{
	if (ID == 0)
		{
			printf("stanza 0");
		}
		if (ID == 1)
		{
			printf("stanza 1");
		}
		if (ID == 2)
		{
			printf("stanza 2");
		}
		if (ID == 3)
		{
			printf("stanza 3");
		}
		if (ID == 4)
		{
			printf("stanza 4");
		}
		if (ID == 5)
		{
			printf("stanza 5");
		}
		if (ID == 6)
		{
			printf("stanza 6");
		}
}

void spawnMap(map *map)
{
	spawnRoom(&map->room, 0);

}
