#include <stdio.h>
#include <stdlib.h>

#include "../headers/world.h"
#include "../headers/player.h"
#include "../headers/enemy.h"


int main(){
	//genera la mappa di gioco
	map map;
	
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