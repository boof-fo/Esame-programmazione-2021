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
	player->damage = 0;
	
	spawnInventory(&player->inventory);
}

