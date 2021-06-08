#include "../headers/world.h"


void setCurrentRoom(map *map, int newRoom)
{
	map->currentRoom = newRoom;
}

int getCurrentRoom(map map)
{
	return map.currentRoom;
}


void printMap(map map)
{
	char p[7] = {' ', ' ', ' ',' ',' ',' ',' '};
	p[getCurrentRoom(map)] = 'X';
	printf("MAPPA:\nX = posizione del giocatore\n  +++++++++\n  +       +\n  +   %c   +\n +++++++++++\n +    +    +\n + %c  +  %c +\n+++++++++++++\n+           +\n+           +\n+     %c     +\n+++++++++++++\n +    +    +\n + %c  +  %c +\n+++++++++++++\n+           +\n+           +\n+     %c     +\n+++++++++++++\n", p[6], p[5], p[4], p[3], p[2], p[1], p[0]);
}


void enterRoom(map *map, int newID)
{
	#ifdef _WIN32
		system("cls");
	#elif __linux__
		system("clear");
	#elif __APPLE__
		system("clear");
	#endif
	
	setCurrentRoom(map, newID);
	spawnRoom(&map->room[newID], newID);
	printMap(*map);
	describeRoom(map->room[newID], newID);
	//imposta i valori dei nemici e stampa descrizione
	if (newID == 0)
	{
		setEnemiesConfiguration(map->room, 0);
		spawnEnemy(&map->room[newID].enemy[0], 10, 0, 0, 0);
		spawnEnemy(&map->room[newID].enemy[1], 10, 0, 0, 0);
	}
	if (newID == 1)
	{
		setEnemiesConfiguration(map->room, 1);
		spawnEnemy(&map->room[newID].enemy[0], 0, 30, 5, 0);
	}
	if (newID == 2)
	{
		setEnemiesConfiguration(map->room, 1);
		spawnEnemy(&map->room[newID].enemy[0], 1, 30, 5, 0);
	}
	if (newID == 3)
	{
		setEnemiesConfiguration(map->room, 3);
		spawnEnemy(&map->room[newID].enemy[0], 2, 35, 7, 0);
		spawnEnemy(&map->room[newID].enemy[1], 3, 35, 7, 0);
	}
	if (newID == 4)
	{
		setEnemiesConfiguration(map->room, 3);
		spawnEnemy(&map->room[newID].enemy[0], 4, 60, 15, 0);
		spawnEnemy(&map->room[newID].enemy[1], 5, 60, 15, 0);
	}
	if (newID == 5)
	{
		setEnemiesConfiguration(map->room, 3);
		spawnEnemy(&map->room[newID].enemy[0], 6, 60, 15, 0);
		spawnEnemy(&map->room[newID].enemy[1], 7, 75, 15, 0);
	}
	if (newID == 6)
	{
		setEnemiesConfiguration(map->room, 1);
		spawnEnemy(&map->room[newID].enemy[0], 8, 150, 19, 0);
	}
}



void killEnemy(map *map, int enemyID)
{
	if (getEnemiesConfiguration(map->room[map->currentRoom]) == 1)
	{
		setEnemiesConfiguration(&map->room[map->currentRoom], 0);
	}else if (getEnemiesConfiguration(map->room[map->currentRoom]) == 2)
	{
		setEnemiesConfiguration(&map->room[map->currentRoom], 0);
	}else if (getEnemiesConfiguration(map->room[map->currentRoom]) == 3)
	{
		if(getEnemyID(map->room->enemy[1]) == enemyID)
			setEnemiesConfiguration(&map->room[map->currentRoom], 1);
		else
			setEnemiesConfiguration(&map->room[map->currentRoom], 2);
	}
}

void help()
{
	//TODO: SCRIVERE I PRINTF BELLINI 
	printf("\nnon so aiutarti, scusami :(\n");
}

void exitGame()
{
	exit(0);
}