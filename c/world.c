#include "../headers/world.h"


void setCurrentRoom(map *map, int newRoom)
{
	map->currentRoom = newRoom;
}

int getCurrentRoom(map map)
{
	return map.currentRoom;
}


void spawnWorld(map *map)
{
	int i = 0;
	while(i < 8)
	{
		spawnRoom(&map->room[i], i);
		i++;
	}
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
	printMap(*map);
	describeRoom(map->room[newID], newID);
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

