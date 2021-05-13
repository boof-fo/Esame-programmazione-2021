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
	//descrizione che viene visualizzata approcciando il nemico
	char descrizione[50];
}enemy;

void setHP(enemy *enemy, int HP);
void setDamage(enemy *enemy, int damage);
void setAbility(enemy *enemy, int abilityID);
void setID(enemy *enemy, int ID);

//crea il nemico
void spawnEnemy(enemy *enemy, int ID, int HP, int damage,int abilityID);


#endif