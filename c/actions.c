#include "../headers/actions.h"

void answerPuzzle(map *map)
{
  printf("\nLa statua del gargoyle si è attivata e ti sta parlando:'Scende da una nave prima di ogni marinaio e di ogni passeggero. Cos’è? risolvi l'idnovinello e avrai un premio. Se non riesci a trovare la risposta corretta scrivi \"esci\" per proseguire.'\nRisposta: ");
  char answer[20];
  scanf("%s",answer);
  if (check(answer,"ancora") || check(answer,"l'ancora"))
  {
    printf("Risposta esatta. tieni l'armatura.\n*un vecchio pezzo di armtura compare sul pavimento*\n");
    setRoomChestplate(&map->room[getCurrentRoom(*map)], 1);
  }else 
  if (check(answer,"esci"))
    return;
  else
  {
    printf("Risposta errata!\n");
  }
}
//stampa la lista dei comandi 
void help()
{
    readFile("help.dat");
}

//stampa un comando e la sua funzionalità
void helpSelect(int selection)
{
	readFileLine("helpSelect.dat", selection);
}

void walkThroughDoor(map *map, player player)
{
	bool last_room = false;
  if(getEnemiesConfiguration(map->room[getCurrentRoom(*map)]))
  {
    printf("Prima di continuare devi sconfiggere i nemici nella stanza attuale.\n");
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
        currentRoom += 2;
      }else 
      if(check(answer, "sinistra"))
      {
        currentRoom += 1;
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
      if(treasureIsPresent(player.inventory) != true)
			{
				printf("Prima di continuare devi raccogliere il tesoro.\n");
				last_room = true;
			}else
			{
				ending();
			}
    }
		if(last_room == false)
    enterRoom(map, player, currentRoom);
  }
}


void takePotion(player *player, room *room)
{
	if (getRoomPotions(*room) > 0)
	{
		removeRoomPotion(room);
		addInventoryPotion(&player->inventory);
		printf("Hai raccolto una pozione curativa, un intruglio a base di erbe medicinali sative, composto secondo un'antica ricetta degli alchimisti del tuo regno, ristabilisce i punti vitali anche se Il sapore non è il massimo.\n");
	}
	else
		printf("Non ci sono pozioni nella stanza.\n");
}

void takeSword(player *player, room *room)
{
	if (getRoomSword(*room) == 0)
	{
		printf("Non ci sono spade nella stanza.\n");
	}
	else 
	{
		if (getRoomSword(*room) == 1)
		{
			printf("Hai raccolto una spada ricurva molto veloce ed affilata, riesce a penetrare nella carne putrefatta dei tuoi nemici con molta facilità.\n");
			setPlayerSword(player, 1);
		}else 
		if (getRoomSword(*room) == 2)
		{
			printf("Hai raccolto un alabarda, arma da distruzione di massa per eccellenza, non troverai equipaggiamento migliore di questo, perciò fattelo bastare.\n");
			setPlayerSword(player, 2);
		}else
		if (getRoomSword(*room) == 3)
		{
			printf("Hai raccolto una spada magica protettiva. La peculiarità di questa spada è la difesa, in quanto aumenta i punti difesa di chi la brandisce attraverso un incatesimo magico, a discapito del danno.\n");
			setPlayerSword(player, 3);
		}		
		removeRoomSword(room);
	}
}
void takeChestplate(player *player, room *room)
{
	int chestplate = getRoomChestplate(*room);
	if (chestplate == 0)
		printf("Non ci sono armature nella stanza.\n");
	else
	{
		setRoomChestplate(room, 0);
		setInventoryChestplate(&player->inventory, chestplate);
		if(chestplate == 1)
		{
			printf("Hai raccolto un pesante pezzo di armatura abbandonata da un cavaliere sconosciuto, è un pochino arrugginita ma dovrebbe riuscire a deviare qualche colpo.\n");
			raisePlayerProtection(player);
		}
	}
}
void takeMap(map *map, player *player)
{
	if(getRoomMap(map->room[getCurrentRoom(*map)]) == true)
	{
		setInventoryMap(&player->inventory, true);
		setRoomMap(&map->room[getCurrentRoom(*map)], false);
		printf("Hai raccolto una vecchia mappa, è una semplice planimetria della fortezza abbandonata, disegnata a mano da qualche viandante ignoto.\n");
	}else
	if(getCurrentRoom(*map) == 0)
	{
		printf("Hai già raccolto la mappa.\n");
	}else
		printf("Non c'è alcuna mappa in questa stanza.\n");
}
void takeTreasure(map *map, player *player)
{
	if(getRoomTreasure(map->room[getCurrentRoom(*map)]) == true)
	{
		setInventoryTreasure(&player->inventory, true);
		setRoomTreasure(&map->room[getCurrentRoom(*map)], false);
		readFile("treasure.dat");
		printf("Congratulazioni, sei riuscito a sconfiggere la ciurma di pirati e a raccogliere il tesoro! Si è aperta una porta nascosta nel muro, attraversala per uscire dalla fortezza.\n");
	}else
	if(getCurrentRoom(*map) == 6)
	{
		printf("Hai già raccolto il tesoro.\n");
	}else
		printf("Non c'è alcun tesoro in questa stanza.\n");
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
			printf("Hai bevuto la pozione, ti senti molto pù in forze ora.\n");
			printf("Adesso hai %d punti vita.\n", getPlayerHP(*player));
		}
		else
		{
			printf("Non puoi bere la pozione, hai già i punti vita al massimo.\n");
		}
	}
	else
		printf("Brutte notizie mio caro amico, non hai più pozioni.\n");
}



int attackEnemy(player *player, enemy *enemy)
{
	int damage = getPlayerDamage(*player);
	bool attaccato = false;
	//10 come ID viene interpretato come "nessun nemico"
  int attacked_enemy_ID = 10;
	//controllo per vedere se il nemico è già morto
	if(getEnemyHP(*enemy) == 0)
	{
		printf("Il nemico è già morto.\n");
	}else
	if(getEnemyHP(*enemy) - damage > 0)
	{
		//la funzione useEnemyAbility ritorna 1 se il giocatore salta il suo turno d'attacco
		if(useEnemyAbility(enemy, player) != 1)
		{
			setEnemyHP(enemy, getEnemyHP(*enemy) - damage);
			attaccato = true;
		}else
		{
			setEnemyHP(enemy, getEnemyHP(*enemy) - damage);
			printf("Il nemico sferra un colpo. Punti HP attuali: %d\n", getPlayerHP(*player));
		}
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
			printf("Nemico ucciso.\n");
			attacked_enemy_ID = getEnemyID(*enemy);
			if(getEnemyID(*enemy) == 8)
			//ultima frase del capitano
			printf("Capitano Barbadura: 'Il mio amato tesoro, La mia ciurma... La mia fortezza, tutto in fumo per colpa tua.'\n");
		}else
			//frasi dette dai nemici
			if(getEnemyID(*enemy) == 8)
				readFileRandomLine("captainLines.dat");
			else
				readFileRandomLine("enemyLines.dat");
	}
	return attacked_enemy_ID;
}