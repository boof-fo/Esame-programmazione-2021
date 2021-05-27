#include "../headers/room.h"

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
void setRoomEnemiesNum(room *room, int enemyNum)
{
	room->enemiesNumber = enemyNum;
}

//imposta il numero di porte (stanze collegate)
void setRoomDoors(room *room, int doors)
{
	room->doors = doors;
}



//imposta i valori di una stanza
void populateRoom(room* room, int ID, int potions, int sword, bool chestplate, int enemyNumber, int doors)
{
	setRoomID(room, ID);
	setRoomPotions(room, potions);
	setRoomSword(room, sword);
	setRoomChestplate(room, chestplate);
	setRoomEnemiesNum(room, enemyNumber);
	setRoomDoors(room, doors);
}

void spawnRoom(room* room, int roomNumber)
{
	if (roomNumber == 0)
	//populateRoom(room* room, int ID, int potions, int sword, bool chestplate, int enemyNumber);
		{
			populateRoom(room, 0, 0, 0, false, 0, 2);
		}
		if (roomNumber == 1)
		{					 //ID
			populateRoom(room, 1, 1, 0, false, 1, 1);
		}
		if (roomNumber == 2)
		{
			populateRoom(room, 2, 1, 0, false, 1, 1);
		}
		if (roomNumber == 3)
		{
			populateRoom(room, 3, 1, 1, true, 2, 2);
		}
		if (roomNumber == 4)
		{
			populateRoom(room, 4, 2, 2, false, 2, 1);
		}
		if (roomNumber == 5)
		{
			populateRoom(room, 5, 2, 2, false, 2, 1);
		}
		if (roomNumber == 6)
		{
			populateRoom(room, 6, 1, 1, false, 1, 0);
		}
}

void describeRoom(room room, int ID)
{
	printf("stanza %d\n", ID);

	int potions = room.potions;
	int sword = room.sword;
	bool chestplate = room.chestplate;
	int enemiesNumber = room.enemiesNumber;

	if(potions == 0 && sword == 0 && chestplate == false && enemiesNumber == 0)
	{
		//TODO: descrizione stanza vuota
		printf("stanza è vuota :( .... mi sento solo\n");
		printf("ci sono %d porte\n", room.doors);
	}
	else
	{
		if (ID == 0)
			printf("\n\n");
		if (ID == 1)
			printf("\n\n");
		if (ID == 2)
			printf("\n\n");
		if (ID == 3)
			printf("\n\n");
		if (ID == 4)
			printf("\n\n");
		if (ID == 5)
			printf("\n\n");
		if (ID == 6)
			printf("\n\n");
		if (ID == 7)
			printf("\n\n");
		if (ID == 8)
			printf("\n\n");
		printf("Nella stanza ci sono: \n");
		if(potions != 0)
		{
			printf("%d Pozioni\n", potions);
		}
		if(sword != 0)
		{
			printf("1 spada\n");
		}
		if(chestplate != false)
		{
			//TODO: gestire in base a cosa vogliamo fare con l'armatura
			printf("Un indovinello(??)");
		}
	}


}

