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



int describeEnemy(int ID)
{
	//se l'ID è uguale a 10 significa che non c'è alcun nemico
	if(ID == 10)
	{
		return 1;
	}else
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
		}
	}
}
		
void spawnEnemy(enemy *enemy, int ID, int HP, int damage,int abilityID)
{
	setEnemyID(enemy, ID);
	setEnemyHP(enemy, HP);
	setEnemyDamage(enemy, damage);
	setEnemyAbility(enemy, abilityID);
}
