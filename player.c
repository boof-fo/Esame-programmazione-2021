#include"player.h"

void setPlayerHP(player *player, int HP){
	player->HP = HP;
}

void setPlayerDamage(player *player, int damage)
{
	player->damage = damage;
}

void spawnPlayer(player *player){
	player->HP = 100;
	//TODO: danno iniziale
	player->damage = 0;
	player->currentRoom = 0;
	spawnInventory(&player->inventory);
}

int getPlayerHP(player player)
{
	return player.HP;
}


void playerReceiveDamage(player *player, int damage)
{
	setPlayerHP(getPlayerHP(player) -= damage);
	//rilevazione morte
	if (getPlayerHP(player) <= 0)
	{
		printf("6 morto X_X \n");
	}
}