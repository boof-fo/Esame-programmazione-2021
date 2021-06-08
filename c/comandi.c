#include "../headers/comandi.h"

void inserstr(char stringa1[],char stringa2[])
{
	int lun = strlen(stringa2);
	int i = 0;
	while(i < lun)
	{
		stringa1[i] = stringa2[i];
		i++;
	}
}


int check(char stringa1[],char stringa2[])
{
    int i = 0;
    int lun1,lun2;
    lun1 = strlen(stringa1);
		lun2 = strlen(stringa2);
		if(lun2 != lun1)
		{
    	return false;
    }else
		{
    	while(i < lun2)
      {
		  	if (stringa1[i] == stringa2[i])
					i++;
        else 
          return false;
      }
    }
    if(i == lun2)
      return true;
    else 
      return false;
}


void insert(list *list, int new_key,char new_string[])
{
    // creo il nuovo nodo e gli alloco uno spazio di memoria
    node *new_node;
    new_node = malloc(sizeof(node));
    // inizializzo il nuovo nodo e gli inserisco il nuovo dato
    new_node->key = new_key;
    inserstr(new_node->string ,new_string);
    new_node->next = NULL;
    // inserisco il nodo all'interno della lista: due casi possibili
    // CASO 1: la lista e' vuota (count e' 0)
    // il nuovo nodo fara' sia da header che da tailer
    if (list->count == 0)
    {
        new_node->prev = NULL;
        list->header = list->tailer = new_node;
    }
    // CASO 2: la lista contiene gia' almeno un elemento
    // aggancio il nuovo nodo alla fine della lista
    // dopo l'inserimento, il nuovo nodo sara' quindi il tailer della lista
    else
    {
        new_node->prev = list->tailer;
        list->tailer->next = new_node;
        list->tailer = new_node;
    }
    // aumento il contatore dei nodi della lista
    list->count++;
}


node *search(list *list, char string[])
{
    node *tmp;
    tmp = list->header;
    // scorro la lista cercando value
    // ritorno l'indirizzo del primo nodo che contiene value
    // altrimenti continuo a scorrere la lista
    while (tmp != NULL)
    {
        if (check(tmp->string,string))
            return tmp;
        tmp = tmp->next;
    }
    // se non trovo nessun nodo contenente value, ritorno NULL
    return NULL;
}


void parsing(list commands,list item1, list item2, list item3, list attr6)
{
  char comando[20] = {0, };
  char oggetto[20] = {0, };
  fflush(stdin);
  scanf("%s" "%s" ,comando, oggetto);


  if (search(&commands,comando) == NULL)
  {
    printf("Comando errato\n");
  }else 


  if (search(&commands,comando)->key == 1)
  {
    if(search(&item1,oggetto)->key == 1)
    {
      takePotion(&gamePlayer.inventory, &gameMap.room[gameMap.currentRoom]);
    }else
    if(search(&item1,oggetto)->key == 2)
    {
      takeSword(&gamePlayer.inventory, &gameMap.room[getCurrentRoom(gameMap)]);
    }
    else 
    if(search(&item1,oggetto)->key == 3)
    {
      takeChestplate(&gamePlayer.inventory, &gameMap.room[getCurrentRoom(gameMap)]);
    }
    else
    {
      printf("oggetto errato\n");
    }
  }else 


  if (search(&commands,comando)->key == 2)
  {
    int deadEnemyID = 0;
    char enter = 'a';
  	char answer[2];
	  int exit;
    if(search(&item2,oggetto)->key == 1)
    {
      //ritorna 0 se non ci sono nemici, 1 se il nemico è a sinistra, 2 se il nemico è a destra
      if(checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 0) == 1)
      {
        deadEnemyID = attackEnemy(&gameMap.room[getCurrentRoom(gameMap)].enemy[0], getPlayerDamage(gamePlayer));
      }else
      {
        printf("Nessun nemico con quel nome nella stanza\n");
      }
    }else
    if(search(&item2,oggetto)->key == 2)
    {
      if(checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 1) == 1)
      {
        deadEnemyID = attackEnemy(&gameMap.room[getCurrentRoom(gameMap)].enemy[0], getPlayerDamage(gamePlayer));
      }else
      {
        printf("Nessun nemico con quel nome nella stanza\n");
      }
    }else 
    if(search(&item2,oggetto)->key == 3)
    {
      if(checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 2) == 1)
      {
        deadEnemyID = attackEnemy(&gameMap.room[getCurrentRoom(gameMap)].enemy[0], getPlayerDamage(gamePlayer));
      }else
      {
        printf("Nessun nemico con quel nome nella stanza\n");
      }
    }else
    if(search(&item2,oggetto)->key == 4)
    {
      if(checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 3) == 2)
      {
        deadEnemyID = attackEnemy(&gameMap.room[getCurrentRoom(gameMap)].enemy[1], getPlayerDamage(gamePlayer));
      }
      else
      {
        printf("Nessun nemico con quel nome nella stanza\n");
      }
    }else
    if(search(&item2,oggetto)->key == 5)
    {
      if(checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 4) == 1)
      {
        deadEnemyID = attackEnemy(&gameMap.room[getCurrentRoom(gameMap)].enemy[0], getPlayerDamage(gamePlayer));
      }else
      {
        printf("Nessun nemico con quel nome nella stanza5\n");
      }
    }else
    if(search(&item2,oggetto)->key == 6)
    {
      if(checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 5) == 2)
      {
        deadEnemyID = attackEnemy(&gameMap.room[getCurrentRoom(gameMap)].enemy[1], getPlayerDamage(gamePlayer));
      }else
      {
        printf("Nessun nemico con quel nome nella stanza\n");
      }
    }else
    if(search(&item2,oggetto)->key == 7)
    {
      if(checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 6) == 1)
      {
        deadEnemyID = attackEnemy(&gameMap.room[getCurrentRoom(gameMap)].enemy[0], getPlayerDamage(gamePlayer));
      }else
      {
        printf("Nessun nemico con quel nome nella stanza\n");
      }
    }else
    if(search(&item2,oggetto)->key == 8)
    {
      if(checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 7) == 2)
      {
        deadEnemyID = attackEnemy(&gameMap.room[getCurrentRoom(gameMap)].enemy[1], getPlayerDamage(gamePlayer));
      }else
      {
        printf("Nessun nemico con quel nome nella stanza\n");
      }
    }else
    if(search(&item2,oggetto)->key == 9)
    {
      if(checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 8) == 1)
      {
        deadEnemyID = attackEnemy(&gameMap.room[getCurrentRoom(gameMap)].enemy[0], getPlayerDamage(gamePlayer));
      }else
      {
        printf("Nessun nemico con quel nome nella stanza\n");
      }
    }else
    {
      printf("oggetto errato\n");
    }
    if(deadEnemyID != 0)
    {
      killEnemy(&gameMap, deadEnemyID);
      if(checkRoomEmpty(gameMap.room[getCurrentRoom(gameMap)]) == 0)
      {
        printf("Hai ucciso tutti i nemici in questa stanza...\n");
        //TODO: INSERIRE FUNZIONE PUZZLE
        while (enter != '\r' && enter != '\n') { enter = getchar(); }
      }
    }
  }else 
  

  if (search(&commands,comando)->key == 3)
  {
    if(search(&item3,oggetto)->key == 1)
    {
      usePotion(&gamePlayer);
    }else
    if(search(&item3,oggetto)->key == 2)
    {
      printMap(gameMap);
    }else{
      printf("errore3");
    }
  }else 
  

  if (search(&commands,comando)->key == 4)
  {
     //TODO: CONTROLLO SE CI SONO NEMICI VIVI 
     //ALLORA 
     //attraversa();
     
  }
  
  if (search(&commands,comando)->key == 5)
  {
    printf("aiuto");
  }else 

  if(search(&commands,comando)->key == 6)
  {
    showInventory(gamePlayer.inventory);
  }
}

void attraversa(){
  int currentRoom = getCurrentRoom(gameMap);
  char risposta[20];
  if(currentRoom == 0 || currentRoom == 3 )
  {
    printf("ci sono due porte");
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
  }
  enterRoom(&gameMap, currentRoom);
}

