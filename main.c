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
	//imposta valori di default 
	spawnPlayer(&player);
	//azzera i valori dell'inventario
	spawnInventory(&player.inventory);
	
	printf("benvenuto nel giokino :)\n");

	setCurrentRoom(&map, &player, 3);
	showInventory(player.inventory);
}