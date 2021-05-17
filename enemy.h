#ifndef ENEMY_H
#define ENEMY_H

#include <stdio.h>

//struttura di un nemico
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

void setEnemyHP(enemy *enemy, int HP);
void setEnemyDamage(enemy *enemy, int damage);
void setEnemyAbility(enemy *enemy, int abilityID);
void setEnemyID(enemy *enemy, int ID);
void printDescription(enemy enemy);

//crea il nemico
void spawnEnemy(enemy *enemy, int ID, int HP, int damage,int abilityID);


#endif