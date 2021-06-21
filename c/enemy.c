#include "../headers/enemy.h"

void setEnemyID(enemy *enemy, int enemy_ID)
{
	enemy->ID = enemy_ID;
}
int getEnemyID(enemy enemy)
{
	return enemy.ID;
}

void setEnemyHP(enemy *enemy, int HP)
{
	enemy->HP = HP;
}
int getEnemyHP(enemy enemy)
{
	return enemy.HP;
}

void setEnemyDamage(enemy *enemy, int damage)
{
	enemy->damage = damage;
}
int getEnemyDamage(enemy enemy)
{
	return enemy.damage;
}

void setEnemyAbility(enemy *enemy, int ability_ID)
{
	enemy->special_ability = ability_ID;
}
int getEnemyAbility(enemy enemy)
{
	return enemy.special_ability;
}


void spawnEnemy(enemy *enemy, int enemy_ID, int HP, int damage,int ability_ID)
{
	setEnemyID(enemy, enemy_ID);
	setEnemyHP(enemy, HP);
	setEnemyDamage(enemy, damage);
	setEnemyAbility(enemy, ability_ID);
}


int describeEnemy(int enemy_ID)
{//se l'ID è uguale a 10 significa che non c'è alcun nemico
	if(enemy_ID == 10)
	{
		return 1;
	}else
	{
		FILE *file = fopen("enemies.dat", "r");
		int count = 0;
		if ( file != NULL )
		{
			char line[1024];
			while (fgets(line, sizeof line, file) != NULL)
			{   
					if (count == enemy_ID)
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
		

int useEnemyAbility(enemy *enemy, player *player)
{
	int playerSkipsTurn = 0;
	int ability = getEnemyAbility(*enemy);
	if(ability != 0)
	{
		if(getEnemyHP(*enemy) <= 20 && ability == 1)
		{
			setEnemyHP(enemy, getEnemyHP(*enemy) + 5);
			printf("Il cuoco risce a mangiare uno strano peperoncino e sembra sia meno stanco. \nI suoi punti vita aumentano di 5 HP.\n");
			ability = 0;
		}else
		if(getEnemyHP(*enemy) <= 20 && ability == 2)
		{
			attackPlayer(player, getEnemyDamage(*enemy));
			printf("Con la sua velocità, il mozzo, sferra due colpi consecutivi.\nPunti HP attuali: %d\n", getPlayerHP(*player));
			ability = 0;
		}else
		if(getEnemyHP(*enemy) <= 20 && ability == 3)
		{
			printf("Il navigatore si nasconde nell'ambiente lugubre e il colpo va a vuoto\n");
			//la funzione ritorna 1 se il giocatore salta il suo turno d'attacco
			playerSkipsTurn = 1;
			ability = 0;
		}else
		if(getEnemyHP(*enemy) <= 25 && ability == 6)
		{
			setEnemyHP(enemy, getEnemyHP(*enemy) + 15);
			printf("Il medico beve un sorso di pozione e guadagna 15 HP.\n");
			ability = 0;
		}else
		if(getEnemyHP(*enemy) <= 60 && ability == 8)
		{
			addInventoryPotion(&player->inventory);
			printf("Il Comandante prova a bere una pozione curativa, ma il tuo colpo lo ha colto di sorpresa e gli ha fatto scivolare la pozione ai tuoi piedi.\n Hai raccolto una pozione curativa.\n");
			ability += 1;
		}else
		if(getEnemyHP(*enemy) <= 30 && ability == 9 )
		{
			setEnemyHP(enemy, getEnemyHP(*enemy) + 20);
			printf("Compare una luce accecante e il comandante rinvigorisce.\nI suoi punti vita aumentano di 20 HP\n");
			ability = 0;
		}
		setEnemyAbility(enemy, ability);
	}
	return playerSkipsTurn;
}

int enemyLines()
{
	srand(time(NULL));
	int selection = rand() % 10 + 1;
	FILE *file = fopen("enemyLines.dat", "r");
	int count = 0;
	if ( file != NULL )
	{
		char line[512];
		while (fgets(line, sizeof line, file) != NULL)
		{
			if (count == selection)
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