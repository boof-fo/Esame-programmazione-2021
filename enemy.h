#ifndef ENEMY_H
#define ENEMY_H

#include <stdio.h>
#include <stdlib.h>


typedef struct{
	//tipo di nemico
	int ID;
	//punti vita del nemico
	int HP;
	//punti danno del nemico
	int damage;
	//TODO: non so
	int specialAbility;
}enemy;

#endif