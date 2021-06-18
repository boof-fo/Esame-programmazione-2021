#include "../headers/actions.h"

void answerPuzzle(map *map)
{
  printf("\nLa statua del gargoyle si è attivata e ti sta parlando:'Scende da una nave prima di ogni marinaio e di ogni passeggero. Cos’è? risolvi l'idnovinello e avrai un premio. Se non riesci a trovare la risposta corretta scrivi \"esci\" per uscire'\n");	
  char risposta[20];
  scanf("%s",risposta);
  if (check(risposta,"ancora") || check(risposta,"l'ancora"))
  {
    printf("Risposta esatta. tieni l'armatura\n*un vecchio pezzo di armtura compare sul pavimento*\n");
    setRoomChestplate(&map->room[getCurrentRoom(*map)], 1);
  }else 
  if (check(risposta,"esci"))
    return;
  else
  {
    printf("no\n");
  }
}

void aiuto()
{
    int c;
    FILE *file;
    file = fopen("comandi.txt", "r");
    if (file)
    {
      while ((c = getc(file)) != EOF)
        putchar(c);
        fclose(file);
    }
}

void attraversa(map *map)
{
  if(getEnemiesConfiguration(map->room[getCurrentRoom(*map)]))
  {
    printf("Prima di continuare devi sconfiggere i nemici nella stanza attuale\n");
    return;
  }
  int currentRoom = getCurrentRoom(*map);
  char risposta[20];
  if(currentRoom == 0 || currentRoom == 3 )
  {
    printf("\nCi sono due porte... vuoi attraversare la porta destra o la porta sinistra?\n");
    scanf("%s",risposta);
    if (check(risposta,"destra"))
    {
      currentRoom += 1;
    }else 
    if(check(risposta, "sinistra"))
    {
      currentRoom += 2;
    }
  }else 
  if ( currentRoom == 1 || currentRoom == 4)
  {
    currentRoom += 2;
  }else 
  if (currentRoom == 2 || currentRoom == 5)
  {
      currentRoom += 1;
  }else 
  if (currentRoom == 6 )
  {
    //TODO: inventarsi o un finale alternativo o il finale
    printf("the end :P\n");
    exit(0);
  }
  enterRoom(map, currentRoom);
}


void takePotion(player *player, room *room)
{
	if (getRoomPotions(*room) > 0)
	{
		removeRoomPotion(room);
		addInventoryPotion(&player->inventory);
		printf("\nHai raccolto una pozione curativa,Un intruglio a base di erbe medicinali sative, composto secondo un'antica ricetta degli alchimisti del tuo regno, ristabilisce i punti vitali anche se Il sapore non è il massimo.\n");
	}
	else
		printf("Non ci sono pozioni. Buona fortuna :)\n");
}
//TODO: danni corretti
void takeSword(player *player, room *room)
{
	if (getRoomSword(*room) == 0)
	{
		printf("Non ci sono spade nella stanza. ¯\\_(ツ)_/¯\n");
	}
	else 
	{
		removeSwordEffects(player);
		if (getRoomSword(*room) == 1)
		{
			printf("\nHai raccolto una spada ricurva molto veloce ed affilata, riesce a penetrare nella carne putrefatta dei tuoi nemici con molta facilità\n");
			setPlayerSword(player, 1);
		}else 
		if (getRoomSword(*room) == 2)
		{
			printf("\nHai raccolto un alabarda, arma da distruzione di massa per eccellenza, non troverai equipaggiamento migliore di questo, perciò fattelo bastare\n");
			setPlayerSword(player, 2);
		}else
		if (getRoomSword(*room) == 3)
		{
			printf("\nSpada magica protettiva\n");
			setPlayerSword(player, 3);
		}		
		removeRoomSword(room);
		giveSwordEffects(player);
	}
}
void takeChestplate(player *player, room *room)
{
	int chestplate = getRoomChestplate(*room);
	if (chestplate == 0)
		printf("Non ci sono armature nella stanza. ¯\\_(ツ)_/¯\n");
	else
	{
		int currentProtection = getPlayerProtection(*player);
		//TODO: tipi di armatura
		setInventoryChestplate(&player->inventory, chestplate);
		if(chestplate == 1)
		{
			printf("\nHai raccolto un pesante pezzo di armatura abbandonata da un cavaliere sconosciuto, è un pochino arrugginita ma dovrebbe riuscire a deviare qualche colpo\n");
			currentProtection += 10;
		}else
		if(chestplate == 2)
		{
			printf("\narmatura stilosa che ti fa il culo grosso\n");
			currentProtection += 20;
		}
		//TODO: valori sensati
		setPlayerProtection(player, currentProtection);
	}
}

void usePotion(player *player)
{
	if(getInventoryPotions(player->inventory) > 0)
	{
		if(getPlayerHP(*player) < 100)
		{
			removeInventoryPotion(&player->inventory);
			if(getPlayerHP(*player) + 40 > 100)
			{
				setPlayerHP(player, 100);	
			}else
			{
				setPlayerHP(player, getPlayerHP(*player) + 40);
			}
			printf("Hai bevuto la pozione, ti senti molto pù in forze ora \n");
			printf("Adesso hai %d punti vita\n", getPlayerHP(*player));
		}
		else
		{
			printf("Non puoi bere la pozione, hai già i punti vita al massimo.\n");
		}
	}
	else
		printf("Brutte notizie mio caro amico, non hai più pozioni\n");
}