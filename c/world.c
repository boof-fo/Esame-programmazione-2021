#include "../headers/world.h"


void setCurrentRoom(map *map, int new_room_ID)
{
	map->current_room = new_room_ID;
}

int getCurrentRoom(map map)
{
	return map.current_room;
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
	printf("MAPPA:\nX = posizione del giocatore\n  +++++++++\n  +       +\n  +   %c   +\n +++++++++++\n +    +    +\n + %c  +  %c +\n+++++++++++++\n+           +\n+           +\n+     %c     +\n+++++++++++++\n +    +    +\n + %c  +  %c +\n+++++++++++++\n+           +\n+           +\n+     %c     +\n+++++++++++++\n", p[6], p[4], p[5], p[3], p[1], p[2], p[0]);
}


void enterRoom(map *map, int new_room_ID)
{
	#ifdef _WIN32
		system("cls");
	#elif __linux__
		system("clear");
	#elif __APPLE__
		system("clear");
	#endif
	
	setCurrentRoom(map, new_room_ID);
	printMap(*map);
	describeRoom(map->room[new_room_ID], new_room_ID);
}


void killEnemy(map *map, int enemy_ID)
{
	if (getEnemiesConfiguration(map->room[getCurrentRoom(*map)]) == 1)
	{
		setEnemiesConfiguration(&map->room[getCurrentRoom(*map)], 0);
	}else if (getEnemiesConfiguration(map->room[getCurrentRoom(*map)]) == 2)
	{
		setEnemiesConfiguration(&map->room[getCurrentRoom(*map)], 0);
	}else if (getEnemiesConfiguration(map->room[getCurrentRoom(*map)]) == 3)
	{
		if(getEnemyID(map->room->enemy[1]) == enemy_ID)
			setEnemiesConfiguration(&map->room[getCurrentRoom(*map)], 1);
		else
			setEnemiesConfiguration(&map->room[getCurrentRoom(*map)], 2);
	}
}

