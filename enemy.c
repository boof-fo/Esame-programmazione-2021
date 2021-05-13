#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0

#include "enemy.h"

void setID(enemy *enemy, int ID)
{
	enemy->ID = ID;
}

void setHP(enemy *enemy, int HP)
{
	enemy->HP = HP;
}

void setDamage(enemy *enemy, int damage)
{
	enemy->damage = damage;
}

void setAbility(enemy *enemy, int abilityID)
{
	enemy->specialAbility = abilityID;
}

void spawnEnemy(enemy *enemy, int ID, int HP, int damage,int abilityID)
{
	setID(enemy, ID);
	setHP(enemy, HP);
	setDamage(enemy, damage);
	setAbility(enemy, abilityID);
}