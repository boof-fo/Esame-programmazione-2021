#include <stdio.h>
#include <stdlib.h>

#include "enemy.h"
#include "map.h"
#include "player.h"
#include "inventory.h"


int main(){
	//genera la mappa di gioco
	map map;
	spawnMap(&map);
	
	//genera giocatore
	player player;
	spawnPlayer(&player);
	
}