#include"../headers/player.h"

void setPlayerHP(player *player, int HP){
	player->HP = HP;
}

void setPlayerDamage(player *player, int damage)
{
	player->damage = damage;
}

int getPlayerHP(player player)
{
	return player.HP;
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



void spawnPlayer(player *player){
	setPlayerHP(player, 100);
	//TODO: danno iniziale
	setPlayerDamage(player, 10);
	spawnInventory(&player->inventory);
}

void playerReceiveDamage(player *player, int damage)
{
	setPlayerHP(player, getPlayerHP(*player) - damage);
	//rilevazione morte
	if (getPlayerHP(*player) <= 0)
	{
		printf("6 morto X_X \n");
	}
}

void usePotion(player *player)
{
	if(getInventoryPotions > 0)
	{
		if(player->HP < 100)
		{
			removeInventoryPotion(&player->inventory);
			player->HP += 50;
			printf("Pozione usata\n");
		}
		else
		{
			printf("Pozione non utilizzata: hai già 100 HP\n");
		}
	}
	else
		printf("Non hai pozioni\n");
}