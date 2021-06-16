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

int getEnemyID(enemy enemy)
{
	return enemy.ID;
}
int getEnemyHP(enemy enemy)
{
	return enemy.HP;
}
int getEnemyDamage(enemy enemy)
{
	return enemy.damage;
}


int attackEnemy(player *player, enemy *enemy, int damage)
{
	bool attaccato = false;
	if(enemy->HP == 0)
	{
		printf("Il nemico è già morto\n");
		return(10);
	}else
	if(enemy->HP - damage > 0)
	{
		setEnemyHP(enemy, getEnemyHP(*enemy) - damage);
		attaccato = true;
	}else
	if(enemy->HP - damage <= 0)
	{
		setEnemyHP(enemy, 0);
		attaccato = true;
	}
	if(attaccato)
	{
		printf("Nemico attaccato! nuovi HP:%d\n",enemy->HP);
		attackPlayer(player, enemy->damage);

		printf("Il nemico reagisce sferrando un colpo. Punti HP attuali: %d\n", getPlayerHP(*player));
	}
	//rilevazione morte
	if (enemy->HP <= 0)
	{
		printf("nemico ucciso X_X \n");
		return enemy->ID;
	}else
	return 10;
}

int describeEnemy(int ID)
{
	FILE *file = fopen("enemies.dat", "r");
	int count = 0;
	if ( file != NULL )
	{
			char line[512];
			while (fgets(line, sizeof line, file) != NULL)
			{   
					if (count == ID)
					{
						printf("\n%s\n", line);
						fclose(file);
						return 0;
					}
					else
						count++;
			}   
			fclose(file);
	}else
	return 2;
}
		
void spawnEnemy(enemy *enemy, int ID, int HP, int damage,int abilityID)
{
	setEnemyID(enemy, ID);
	setEnemyHP(enemy, HP);
	setEnemyDamage(enemy, damage);
	setEnemyAbility(enemy, abilityID);
	describeEnemy(ID);
	if(ID == 0)
	{
		addInventoryPotion(&enemy->inventory);
	}else
	if(ID == 1)
	{
		//letter
	}
}
