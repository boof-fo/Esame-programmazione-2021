#include "enemy.h"

void setEnemyID(enemy *enemy, int ID)
{
	enemy->ID = ID;
}

void setEnemyHP(enemy *enemy, int HP)
{
	enemy->HP = HP;
}

void setEnemyDamage(enemy *enemy, int damage)
{
	enemy->damage = damage;
}

void setEnemyAbility(enemy *enemy, int abilityID)
{
	enemy->specialAbility = abilityID;
}


void printDescription(enemy enemy)
{
	printf("\nC'È UN CATTIVONE\n");
	int ID = enemy.ID;
	if (ID == 0)
		printf("\nnemico 0\n");
	if (ID == 1)
		printf("\nnemico 0\n");
	if (ID == 2)
		printf("\nnemico 0\n");
	if (ID == 3)
		printf("\nnemico 0\n");
	if (ID == 4)
		printf("\nnemico 0\n");
	if (ID == 5)
		printf("\nnemico 0\n");
	if (ID == 6)
		printf("\nnemico 0\n");
	if (ID == 7)
		printf("\nnemico 0\n");
	if (ID == 8)
		printf("\nnemico 0\n");
	if (ID == 9)
		printf("\nnemico 0\n");
}

void spawnEnemy(enemy *enemy, int ID, int HP, int damage,int abilityID)
{
	setEnemyID(enemy, ID);
	setEnemyHP(enemy, HP);
	setEnemyDamage(enemy, damage);
	setEnemyAbility(enemy, abilityID);
}

