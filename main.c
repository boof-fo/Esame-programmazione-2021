#include <stdio.h>
#include <stdlib.h>

#include "player.h"
#include "enemy.h"
#include "map.h"


int main(){
	//genera la mappa di gioco
	map map;
	spawnMap(&map);
	
	//genera giocatore
	player player;
	spawnPlayer(&player);
	
	printf("benvenuto nel giokino :)\n");

	describeRoom(map.room, player.currentRoom);
	printMap(0);

	
}