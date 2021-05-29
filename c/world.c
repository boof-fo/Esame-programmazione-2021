#include "../headers/world.h"

void printMap(player player)
{
	char p[7] = {' ', ' ', ' ',' ',' ',' ',' '};
	p[player.currentRoom] = 'X';
	printf("MAPPA:\nX = posizione del giocatore\n  +++++++++\n  +       +\n  +   %c   +\n +++++++++++\n +    +    +\n + %c  +  %c +\n+++++++++++++\n+           +\n+           +\n+     %c     +\n+++++++++++++\n +    +    +\n + %c  +  %c +\n+++++++++++++\n+           +\n+           +\n+     %c     +\n+++++++++++++\n", p[6], p[5], p[4], p[3], p[2], p[1], p[0]);
}

void setCurrentRoom(map *map, player *player, int newID)
{
	player->currentRoom = newID;
	spawnRoom(&map->room, newID);
	printMap(*player);
	describeRoom(map->room, newID);
	//imposta i valosi dei nemici e stampa descrizione
	if (newID == 0)
	{
		spawnEnemy(&map->enemy[0], 0, 0, 0, 0);
		spawnEnemy(&map->enemy[1], 0, 0, 0, 0);
	}
	if (newID == 1)
	{
		spawnEnemy(&map->enemy[0], 0, 30, 5, 0);
	}
	if (newID == 2)
	{
		spawnEnemy(&map->enemy[0], 1, 30, 5, 0);
	}
	if (newID == 3)
	{
		spawnEnemy(&map->enemy[0], 2, 35, 7, 0);
		spawnEnemy(&map->enemy[1], 3, 35, 7, 0);
	}
	if (newID == 4)
	{
		spawnEnemy(&map->enemy[0], 4, 60, 15, 0);
		spawnEnemy(&map->enemy[1], 5, 60, 15, 0);
	}
	if (newID == 5)
	{
		spawnEnemy(&map->enemy[0], 6, 60, 15, 0);
		spawnEnemy(&map->enemy[1], 7, 75, 15, 0);
	}
	if (newID == 6)
	{
		spawnEnemy(&map->enemy[0], 8, 150, 19, 0);
	}
}



void killEnemy(map *map, int enemyID)
{
	if (getEnemiesConfiguration(map->room) == 1)
	{
		//poveretto, salutava sempre
		setEnemiesConfiguration(&map->room, 0);
	}else if (getEnemiesConfiguration(map->room) == 2)
	{
		setEnemiesConfiguration(&map->room, 0);
	}else if (getEnemiesConfiguration(map->room) == 3)
	{
		if(map->enemy[1].ID == enemyID)
			setEnemiesConfiguration(&map->room, 1);
		else
			setEnemiesConfiguration(&map->room, 2);
	}
}

void help()
{
	printf("\nnon so aiutarti, scusami :(\n");
}

void exitGame()
{
	exit(0);
}