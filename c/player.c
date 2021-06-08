#include"../headers/player.h"

void setPlayerHP(player *player, int HP){
	player->HP = HP;
}


void setPlayerDamage(player *player, int damage)
{
	player->damage = damage;
}
void setPlayerProtection(player *player, int protectionPoints)
{
	player->protection = protectionPoints;
}

void setSword(player *player, int swordType)
{
	//TODO: mettere i valori definitivi
	int newDamage;
	if (swordType == 1)
		newDamage = 0;
	else if (swordType == 2)
		newDamage = 0;
	setPlayerDamage(player, newDamage);
	setInventorySword(&player->inventory, swordType);
}

void setChestplate(player *player)
{
	//TODO: mettere i valori definitivi
	setPlayerProtection(player, 30);
	setInventoryChestplate(&player->inventory);
}


int getPlayerHP(player player)
{
	return player.HP;
}
int getPlayerDamage(player player)
{
	return player.damage;
}



void spawnPlayer(player *player){
	setPlayerHP(player, 100);
	//TODO: danno iniziale
	setPlayerDamage(player, 10);
	spawnInventory(&player->inventory);
}

void attackPlayer(player *player, int damage)
{
	setPlayerHP(player, getPlayerHP(*player) - damage);
	//rilevazione morte
	if (getPlayerHP(*player) <= 0)
	{
		printf("\nAspetta... Ma che succede? ti sei accasciato a terra e sei privo di forze. La tua avventura finisce qui sei morto.\n");
		exit(0);
	}
	
}

void usePotion(player *player)
{
	if(getInventoryPotions(player->inventory) > 0)
	{
		if(getPlayerHP(*player) < 100)
		{
			removeInventoryPotion(&player->inventory);
			setPlayerHP(player, getPlayerHP(*player) + 50);
			printf("\nHai bevuto la pozione, ti senti molto pù in forze ora ");
			printf("adesso hai %d punti vita\n", getPlayerHP(*player));
		}
		else
		{
			printf("Non puoi bere la pozione, hai già i punti vita al massimo.\n");
		}
	}
	else
		printf("Non hai pozioni\n");
}