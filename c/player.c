#include"../headers/player.h"

//imposta/ritorna i punti vita del giocatore
void setPlayerHP(player *player, int health_points){
	player->HP = health_points;
}
int getPlayerHP(player player)
{
	return player.HP;
}
//imposta/ritorna i punti danno del giocatore
void setPlayerDamage(player *player, int damage_points)
{
	player->damage = damage_points;
}
int getPlayerDamage(player player)
{
	return player.damage;
}
//imposta/ritorna i punti protezione del giocatore
void setPlayerProtection(player *player, int protection_points)
{
	player->protection = protection_points;
}
int getPlayerProtection(player player)
{
	return player.protection;
}

//Applica/rimuovi gli effetti di una spada
void giveSwordEffects(player *player)
{
	if(getInventorySword(player->inventory) == 3)
		raisePlayerProtection(player);
}
void removeSwordEffects(player *player)
{
	if(getInventorySword(player->inventory) == 3)
		lowerPlayerProtection(player);
}

//imposta una spada con i suoi punti danno ed i suoi effetti
void setPlayerSword(player *player, int sword_ID)
{
	//rimuovi eventuali effetti della spada
	removeSwordEffects(player);
	//TODO: mettere i valori definitivi
	int new_damage;
	if (sword_ID == 1)
	{
		new_damage = 20;
	}else 
	if (sword_ID == 2)
	{
		new_damage = 30;
	}else 
	if (sword_ID == 3)
	{
		new_damage = 30;
	}
	setPlayerDamage(player, new_damage);
	setInventorySword(&player->inventory, sword_ID);
	//applica eventuali effetti della spada
	giveSwordEffects(player);
}
int getPlayerSword(player player)
{
	return player.inventory.sword;
}

//imposta i valori predefiniti
void spawnPlayer(player *player){
	setPlayerHP(player, 100);
	//TODO: danno iniziale
	setPlayerDamage(player, 10);
	//azzera i valori dell'inventario
	spawnInventory(&player->inventory);
}

//mostra il contenuto dell'inventario
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
