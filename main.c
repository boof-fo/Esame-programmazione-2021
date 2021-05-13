#include <stdio.h>
#include <stdlib.h>

#include "enemy.h"
#include "map.h"

int main(){
	//mappa dichiarata in map.h
	map map;

	generateMap(&map);
	
	int i = 0;
	while (i < 7)
	{
		if (map.room[i].enemiesNumber == 1)
		printf("1,\n");
		i++;
	}
}