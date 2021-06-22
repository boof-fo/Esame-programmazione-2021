#include"../headers/player.h"

char enter='a';
char answer[2];

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

void raisePlayerProtection(player *player)
{
	setPlayerProtection(player, getPlayerProtection(*player) + 10);
}
void lowerPlayerProtection(player *player)
{
	setPlayerProtection(player, getPlayerProtection(*player) - 10);
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
		new_damage = 25;
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
void spawnPlayer(player *player)
{
	setPlayerHP(player, 100);
	setPlayerDamage(player, 100);
	//azzera i valori dell'inventario
	spawnInventory(&player->inventory);
	setInventoryTreasure(&player->inventory, false);
	setInventoryMap(&player->inventory, false);
}

//mostra il contenuto dell'inventario
void showInventory(player player)
{
	printf("\nPunti vita: %d \n", getPlayerHP(player));
	printf("INVENTARIO:\nPozioni: %d\nDescrizione: Un intruglio a base di erbe medicinali sative, composto secondo un'antica ricetta degli alchimisti del tuo regno, ristabilisce i punti vitali anche se Il sapore non è il massimo.", getInventoryPotions(player.inventory));

	printf("Tipo di spada: ");
	if(getInventorySword(player.inventory) == 0)
	{
		printf("Spada semplice\nDescrizione: Un giorno qualcuno disse “il migliore amico dell’avventuriero è un’ affidabile spada di ferro”. Una classica spada piatta usata in dotazione dai soldati semplici, un'arma non troppo sofisticata ma meglio di niente.");
	}else 
	if(getInventorySword(player.inventory) == 1)
	{
		printf("Spada ricurva\nDescrizione: Una spada ricurva molto veloce ed affilata, riesce penetrare nella carne putrefatta dei tuoi nemici con molta facilità");
	}else 
	if(getInventorySword(player.inventory) == 2)
	{
		printf("Alabarda\nDescrizione: Arma da distruzione di massa per eccellenza, non troverai equipaggiamento migliore di questo, perciò fattelo bastare!");
	}
	printf("\n   Punti danno attuali: %d\n", getPlayerDamage(player));

	printf("Armatura: ");
	if(getInventoryChestplate(player.inventory) == 0)
	{
		printf("Non presente\n");
	}else
	{
		printf("Presente\nDescrizione:una pesante armatura abbandonata da un cavaliere sconosciuto, è un pochino arrugginita ma dovrebbe riuscire a deviare qualche colpo.");
	}
	if(getPlayerProtection(player) > 0)
	{
		printf("\n   Punti protezione attuali: %d\n", getPlayerProtection(player));
	}
}


void attackPlayer(player *player, int damage)
{
	//riduzione del danno in base ai punti protezione
	float protection = (float)getPlayerProtection(*player);
	protection = protection/5;
	damage -= protection;

	setPlayerHP(player, getPlayerHP(*player) - damage);
	//rilevazione morte
	if (getPlayerHP(*player) <= 0)
	{
		printf("\nAspetta... Ma che succede? ti sei accasciato a terra e sei privo di forze, sarai usato come mangime per pesci.\nPremi INVIO per continuare...\n");
		fflush(stdin);
		enter = getchar();
		
		#ifdef _WIN32
		system("cls");
		#elif __linux__
		system("clear");
		#elif __APPLE__
		system("clear");
		#endif
		
		printf(" #####     #    #     # #######    ####### #     # ####### ######\n#     #   # #   ##   ## #          #     # #     # #       #     #\n#        #   #  # # # # #          #     # #     # #       #     #\n#  #### #     # #  #  # #####      #     # #     # #####   ######\n#     # ####### #     # #          #     #  #   #  #       #   #\n#     # #     # #     # #          #     #   # #   #       #    # \n #####  #     # #     # #######    #######    #    ####### #     #\n ");
		printf("\n\n\nLa tua avventura finisce qui.\nPremi INVIO per uscire...");
		fflush(stdin);
		enter = getchar();
		exit(0);

	
	}
}