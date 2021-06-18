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

void setPlayerSword(player *player, int swordType)
{
	//TODO: mettere i valori definitivi
	int newDamage;
	if (swordType == 1)
	{
		newDamage = 20;
	}else 
	if (swordType == 2)
	{
		newDamage = 30;
	}else 
	if (swordType == 3)
	{
		newDamage = 30;

	}
	setPlayerDamage(player, newDamage);
	setInventorySword(&player->inventory, swordType);
}



int getPlayerHP(player player)
{
	return player.HP;
}
int getPlayerDamage(player player)
{
	return player.damage;
}
int getPlayerProtection(player player)
{
	return player.protection;
}
int getPlayerSword(player player)
{
	return player.inventory.sword;
}




void spawnPlayer(player *player){
	setPlayerHP(player, 100);
	//TODO: danno iniziale
	setPlayerDamage(player, 10);
	spawnInventory(&player->inventory);
}


void attackPlayer(player *player, int damage)
{
	float protection = (float)getPlayerProtection(*player);
	protection = protection/5;
	damage -= protection;
	setPlayerHP(player, getPlayerHP(*player) - damage);
	//rilevazione morte
	if (getPlayerHP(*player) <= 0)
	{
		printf("\nAspetta... Ma che succede? ti sei accasciato a terra e sei privo di forze. La tua avventura finisce qui, sei morto.\n");
		exit(0);
	}
	
}





void giveSwordEffects(player *player)
{
	if(getInventorySword(player->inventory) == 3)
	{
		raisePlayerProtection(player);
	}
}
void removeSwordEffects(player *player)
{
	if(getInventorySword(player->inventory) == 3)
	{
		lowerPlayerProtection(player);
	}
}

void raisePlayerProtection(player *player)
{
	setPlayerProtection(player, getPlayerProtection(*player) + 10);
}
void lowerPlayerProtection(player *player)
{
	setPlayerProtection(player, getPlayerProtection(*player) - 10);
}

void showInventory(player player)
{
	printf("\nPunti vita: %d \n", getPlayerHP(player));
	printf("INVENTARIO:\nPozioni: %d\n", getInventoryPotions(player.inventory));

	printf("Tipo di spada: ");
	if(getInventorySword(player.inventory) == 0)
	{
		printf("Spada semplice");
	}else 
	if(getInventorySword(player.inventory) == 1)
	{
		printf("Spada ricurva");
	}else 
	if(getInventorySword(player.inventory) == 2)
	{
		printf("Alabarda");
	}
	printf("\n   Punti danno attuali: %d\n", getPlayerDamage(player));

	printf("Armatura: ");
	if(getInventoryChestplate(player.inventory) == 0)
	{
		printf("Non presente\n");
	}else
	{//TODO: tipi di armatura
		printf("Presente\n");
	}
	if(getPlayerProtection(player) > 0)
	{
		printf("\n   Punti protezione attuali: %d\n", getPlayerProtection(player));
	}
}
