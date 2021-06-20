#include "../headers/actions.h"

void answerPuzzle(map *map)
{
  printf("\nLa statua del gargoyle si è attivata e ti sta parlando:'Scende da una nave prima di ogni marinaio e di ogni passeggero. Cos’è? risolvi l'idnovinello e avrai un premio. Se non riesci a trovare la risposta corretta scrivi \"esci\" per uscire'\n");	
  char answer[20];
  scanf("%s",answer);
  if (check(answer,"ancora") || check(answer,"l'ancora"))
  {
    printf("Risposta esatta. tieni l'armatura\n*un vecchio pezzo di armtura compare sul pavimento*\n");
    setRoomChestplate(&map->room[getCurrentRoom(*map)], 1);
  }else 
  if (check(answer,"esci"))
    return;
  else
  {
    printf("Risposta errata!\n");
  }
}
//stampa i comandi e le loro funzionalità
void help()
{
    int c;
    FILE *file;
    file = fopen("help.dat", "r");
    if (file)
    {
      while ((c = getc(file)) != EOF)
        putchar(c);
        fclose(file);
    }
}
//stampa un comando e la sua funzionalità
void helpSelect(int selections)
{
FILE *file = fopen("helpselect.dat", "r");
int count = 0;
		if ( file != NULL )
		{
				char line[512];
				while (fgets(line, sizeof line, file) != NULL)
				{   
						if (count == selections)
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
void walkThroughDoor(map *map)
{
  if(getEnemiesConfiguration(map->room[getCurrentRoom(*map)]))
  {
    printf("Prima di continuare devi sconfiggere i nemici nella stanza attuale\n");
  }else
  {
    int currentRoom = getCurrentRoom(*map);
    char answer[20];
    if(currentRoom == 0 || currentRoom == 3 )
    {
      printf("\nCi sono due porte... vuoi attraversare la porta destra o la porta sinistra?\n");
      scanf("%s",answer);
      if (check(answer,"destra"))
      {
        currentRoom += 1;
      }else 
      if(check(answer, "sinistra"))
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
		printf("\nAspetta... Ma che succede? ti sei accasciato a terra e sei privo di forze. La tua avventura finisce qui, sei morto.\n");
		exit(0);
	}
}

int attackEnemy(player *player, enemy *enemy, int damage)
{
	bool attaccato = false;
  int attacked_enemy_ID = 10;
	//controllo per vedere se il nemico è già morto
	if(getEnemyHP(*enemy) == 0)
	{
		printf("Il nemico è già morto\n");
	}else
	if(getEnemyHP(*enemy) - damage > 0)
	{
		setEnemyHP(enemy, getEnemyHP(*enemy) - damage);
		attaccato = true;
	}else//se il nemico morirà con il prossimo colpo, imposta gli HP a 0
	{
		setEnemyHP(enemy, 0);
		attaccato = true;
	}
	//se un nemico è stato attaccato allora manda un colpo di risposta al giocatore e mostra i nuovi punti vita.
	if(attaccato)
	{
		printf("Nemico attaccato! nuovi HP:%d\n", getEnemyHP(*enemy));
		attackPlayer(player, getEnemyDamage(*enemy));

		printf("Il nemico reagisce sferrando un colpo. Punti HP attuali: %d\n", getPlayerHP(*player));

		//rilevazione morte
		if (enemy->HP <= 0)
		{
			printf("nemico ucciso X_X \n");
			attacked_enemy_ID = getEnemyID(*enemy);
		}
	}
	return attacked_enemy_ID;
}