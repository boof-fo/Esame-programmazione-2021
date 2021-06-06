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
void setEnemiesConfiguration(room *room, int enemyConfig)
{
	room->enemiesConfiguration = enemyConfig;
}

//imposta il numero di porte (stanze collegate)
void setRoomDoors(room *room, int doors)
{
	room->doors = doors;
}

void removeRoomPotion(room *room)
{
	room->potions -= 1;
}
void removeRoomSword(room *room)
{
	room->sword = 0;
}
void removeRoomChestplate(room *room)
{
	room->sword = false;
}



int getRoomPotions(room room)
{
	return room.potions;
}
int getRoomSword(room room)
{
	return room.sword;
}
int getEnemiesConfiguration(room room)
{
	return room.enemiesConfiguration;
}



//imposta i valori di una stanza
void populateRoom(room* room, int ID, int potions, int sword, bool chestplate, int enemiesConfig, int doors)
{
	setRoomID(room, ID);
	setRoomPotions(room, potions);
	setRoomSword(room, sword);
	setRoomChestplate(room, chestplate);
	setEnemiesConfiguration(room, enemiesConfig);
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
	int enemiesConfiguration = room.enemiesConfiguration;

	if(potions == 0 && sword == 0 && chestplate == false && enemiesConfiguration == 0)
	{
		//TODO: descrizione stanza vuota
		printf("\nl'ingresso della fortezza appare come una stanza vuota e silenziosa,l'unica fonte di luce è quella che penetra dalla porta principale, ma una volta chiusa l'unica fonte di luce saranno delle fiaccole sui muri che ardono di una fiamma blu apparentemente inestinguibile, non ci sono oggetti ne nemici, goditi questi ultimi atti di tranquillità perchè da qui in poi non sarà più così\n");
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
		if(chestplate == true)
		{
			//TODO: gestire in base a cosa vogliamo fare con l'armatura
			printf("Un indovinello? bo non so");
		}
	}


}

