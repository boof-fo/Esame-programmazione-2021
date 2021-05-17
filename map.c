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

void describeRoom(room room, int ID)
{
	printf("stanza %d", ID);

	
	int potions = room.potions;
	int sword = room.sword;
	bool chestplate = room.chestplate;
	int enemiesNumber = room.enemiesNumber;

	if(potions == 0 && sword == 0 && chestplate == false && enemiesNumber == 0)
	{
		//TODO: descrizione stanza 0
		printf("stanza è vuota :( .... mi sento solo\n");
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
			printf("\nIl medico di bordo è un uomo saggio, e sarà anche anziano, ma non farlo arrabbiare perché il suo bisturi è tagliente\n");
		if (ID == 7)
			printf("\n\n");
		if (ID == 8)
			printf("\n“Dov’è la mia nave pirata?” è una domanda che il comandante si chiede spesso, ma in realtà non fa niente: i fantasmi non possono avere la patente nautica.\n");
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

void spawnMap(map *map)
{
	spawnRoom(&map->room, 0);
}

void printMap(player player)
{
	int roomNumber = player.currentRoom;
	char p[7] = {' ', ' ', ' ',' ',' ',' ',' '};
	p[roomNumber] = 'X';
	printf("MAPPA:\nX = posizione del giocatore\n  +++++++++\n  +       +\n  +   %c   +\n +++++++++++\n +    +    +\n + %c  +  %c +\n+++++++++++++\n+           +\n+           +\n+     %c     +\n+++++++++++++\n +    +    +\n + %c  +  %c +\n+++++++++++++\n+           +\n+           +\n+     %c     +\n+++++++++++++\n", p[6], p[5], p[4], p[3], p[2], p[1], p[0]);
}

void setCurrentRoom(map map, player *player, int newRoom)
{
	player->currentRoom = newRoom;
	printMap(*player);
	describeRoom(map.room, newRoom);
}
