#ifndef ENEMY_H
#define ENEMY_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/player.h"
#include "../headers/inventory.h"
#include "../headers/string.h"

typedef int bool;
#define true 1
#define false 0

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
}enemy;

void setEnemyHP(enemy *enemy, int HP);
void setEnemyDamage(enemy *enemy, int damage);
void setEnemyAbility(enemy *enemy, int abilityID);
void setEnemyID(enemy *enemy, int ID);

int getEnemyID(enemy enemy);
int getEnemyHP(enemy enemy);
int getEnemyDamage(enemy enemy);

int attackEnemy(player *player, enemy *enemy, int damage);

//TODO: gestire gli errori quando viene chiamata
int describeEnemy(int ID);

//crea il nemico impostando le sue statistiche
void spawnEnemy(enemy *enemy, int ID, int HP, int damage,int abilityID);

#endif