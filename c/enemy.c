#include "../headers/enemy.h"

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


int enemyReceiveDamage(enemy *enemy, int damage)
{
	enemy->HP -= damage;
	//rilevazione morte
	if (enemy->HP <= 0)
	{
		printf("nemico ucciso X_X \n");
		return enemy->ID;
	}
	return 0;
}

void describeEnemy(int ID)
{
	if (ID == 0)
		printf("\n\n");
	if (ID == 1)
		printf("\n\n");
	if (ID == 2)
		printf("\n\n");
	if (ID == 3)
		printf("\n\n");
	if (ID == 4)
		printf("\n\n");
	if (ID == 5)
		printf("\n\n");
	if (ID == 6)
		printf("\nIl medico di bordo è un uomo saggio, e sarà anche anziano,ma non farlo arrabbiare perché il suo bisturi è tagliente\n");
	if (ID == 7)
		printf("\n\n");
	if (ID == 8)
		printf("\n“Dov’è la mia nave pirata?” è una domanda che il comandante si chiede spesso, ma in realtà non fa niente: i fantasmi non possono avere la patente nautica.\n");
}


void spawnEnemy(enemy *enemy, int ID, int HP, int damage,int abilityID)
{
	setEnemyID(enemy, ID);
	setEnemyHP(enemy, HP);
	setEnemyDamage(enemy, damage);
	setEnemyAbility(enemy, abilityID);
	describeEnemy(ID);
}
