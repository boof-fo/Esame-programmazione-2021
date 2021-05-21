#ifndef ENEMY_H
#define ENEMY_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//struttura di un nemico
typedef struct{
	//tipo di nemico
	int ID;
	//punti vita del nemico
	int HP;
	//punti danno del nemico
	int damage;
	//TODO: medico si cura da solo, 
	int specialAbility;
	//descrizione nemico
	char* description;
}enemy;

void setEnemyHP(enemy *enemy, int HP);
void setEnemyDamage(enemy *enemy, int damage);
void setEnemyAbility(enemy *enemy, int abilityID);
void setEnemyID(enemy *enemy, int ID);
void setEnemyDescription(enemy *enemy);

void printEnemyDescription(enemy enemy);

void enemyReceiveDamage(enemy *enemy, int damage);


//crea il nemico
void spawnEnemy(enemy *enemy, int ID, int HP, int damage,int abilityID);


#endif
