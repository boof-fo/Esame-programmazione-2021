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

void setEnemyDescription(enemy *enemy)
{
	if(enemy->ID == 0)
	{
		strncpy(enemy->description, "a", 120);
	}
	if(enemy->ID == 1)
	{
		strncpy(enemy->description, "z", 120);
	}
}

void printEnemyDescription(enemy enemy)
{
	int i = 0;
	while(i < 120)
	{
		printf("%c", enemy.description[i]);
		i += 1;
	}	
}

void enemyReceiveDamage(enemy *enemy, int damage)
{
	enemy->HP -= damage;
	//rilevazione morte
	if (enemy->HP <= 0)
	{
		printf("nemico ucciso X_X \n");
	}
}

void spawnEnemy(enemy *enemy, int ID, int HP, int damage,int abilityID)
{
	setEnemyID(enemy, ID);
	setEnemyHP(enemy, HP);
	setEnemyDamage(enemy, damage);
	setEnemyAbility(enemy, abilityID);
	enemy->description = malloc(sizeof(char)*120);
	setEnemyDescription(enemy);
}