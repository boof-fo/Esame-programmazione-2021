#include "../headers/comandi.h"

void parsing(list commands,list item1, list item2, list item3, list attr6)
{
  char comando[20] = {0, };
  char oggetto[20] = {0, };
  fflush(stdin);
  scanf("%s" "%s" ,comando, oggetto);


  if (search(&commands,comando) == NULL)
  {
    printf("Non conosco questo comando\n");
  }else 


  if (search(&commands,comando)->key == 1)
  {
    if(getEnemiesConfiguration(gameMap.room[getCurrentRoom(gameMap)]) != 0)
     printf("prima di raccogliere gli oggetti da terra devi aver sconfitto tutti i nemici nella stanza.\n"); 
    else
    if(search(&item1,oggetto)->key == 1)
    {
      takePotion(&gamePlayer, &gameMap.room[gameMap.currentRoom]);
    }else
    if(search(&item1,oggetto)->key == 2)
    {
      takeSword(&gamePlayer, &gameMap.room[getCurrentRoom(gameMap)]);
    }
    else 
    if(search(&item1,oggetto)->key == 3)
    {
      takeChestplate(&gamePlayer, &gameMap.room[getCurrentRoom(gameMap)]);
    }
    else
    {
      printf("oggetto errato\n");
    }
  }else 


  if (search(&commands,comando)->key == 2)
  {
    int deadEnemyID = 10;
    int enemyIsPresent = 0;

    if(search(&item2,oggetto)->key == 1)
    {
      //checkEnemyPresent ritorna 0 se non ci sono nemici, 1 se il nemico è a sinistra, 2 se il nemico è a destra
        enemyIsPresent = checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 0);
        if(enemyIsPresent == 1)
        {
          deadEnemyID = attackEnemy(&gamePlayer, &gameMap.room[getCurrentRoom(gameMap)].enemy[0], getPlayerDamage(gamePlayer));
        }else
        if(enemyIsPresent == 3)
        {
          printf("Il nemico è già morto\n");
        }
        else
        {
          printf("Nessun nemico con quel nome nella stanza\n");
        }
    }else

    if(search(&item2,oggetto)->key == 2)
    {
      enemyIsPresent = checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 1);
      if(enemyIsPresent == 1)
      {
        deadEnemyID = attackEnemy(&gamePlayer, &gameMap.room[getCurrentRoom(gameMap)].enemy[0], getPlayerDamage(gamePlayer));
      }else
      if(enemyIsPresent == 3)
      {
        printf("Il nemico è già morto\n");
      }
      else
      {
        printf("Nessun nemico con quel nome nella stanza\n");
      }
    }else 

    if(search(&item2,oggetto)->key == 3)
    {
      enemyIsPresent = checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 2);
      if(enemyIsPresent == 1)
      {
        deadEnemyID = attackEnemy(&gamePlayer, &gameMap.room[getCurrentRoom(gameMap)].enemy[0], getPlayerDamage(gamePlayer));
      }else
      if(enemyIsPresent == 3)
      {
        printf("Il nemico è già morto\n");
      }
      else
      {
        printf("Nessun nemico con quel nome nella stanza\n");
      }
    }else

    if(search(&item2,oggetto)->key == 4)
    {
      enemyIsPresent = checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 3);
      if(enemyIsPresent == 2)
      {
        deadEnemyID = attackEnemy(&gamePlayer, &gameMap.room[getCurrentRoom(gameMap)].enemy[1], getPlayerDamage(gamePlayer));
      }else
      if(enemyIsPresent == 3)
      {
        printf("Il nemico è già morto\n");
      }
      else
      {
        printf("Nessun nemico con quel nome nella stanza\n");
      }
    }else

    if(search(&item2,oggetto)->key == 5)
    {
      enemyIsPresent = checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 4);
      if(enemyIsPresent == 1)
      {
        deadEnemyID = attackEnemy(&gamePlayer, &gameMap.room[getCurrentRoom(gameMap)].enemy[0], getPlayerDamage(gamePlayer));
      }else
      if(enemyIsPresent == 3)
      {
        printf("Il nemico è già morto\n");
      }
      else
      {
        printf("Nessun nemico con quel nome nella stanza\n");
      }
    }else

    if(search(&item2,oggetto)->key == 6)
    {
      enemyIsPresent = checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 5);
      if(enemyIsPresent == 2)
      {
        deadEnemyID = attackEnemy(&gamePlayer, &gameMap.room[getCurrentRoom(gameMap)].enemy[1], getPlayerDamage(gamePlayer));
      }else
      if(enemyIsPresent == 3)
      {
        printf("Il nemico è già morto\n");
      }
      else
      {
        printf("Nessun nemico con quel nome nella stanza\n");
      }
    }else

    if(search(&item2,oggetto)->key == 7)
    {
      enemyIsPresent = checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 6);
      if(enemyIsPresent == 1)
      {
        deadEnemyID = attackEnemy(&gamePlayer, &gameMap.room[getCurrentRoom(gameMap)].enemy[0], getPlayerDamage(gamePlayer));
      }else
      if(enemyIsPresent == 3)
      {
        printf("Il nemico è già morto\n");
      }
      else
      {
        printf("Nessun nemico con quel nome nella stanza\n");
      }
    }else

    if(search(&item2,oggetto)->key == 8)
    {
      enemyIsPresent = checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 7);
      if(enemyIsPresent == 2)
      {
        deadEnemyID = attackEnemy(&gamePlayer, &gameMap.room[getCurrentRoom(gameMap)].enemy[1], getPlayerDamage(gamePlayer));
      }else
      {
        printf("Nessun nemico con quel nome nella stanza\n");
      }
    }else

    if(search(&item2,oggetto)->key == 9)
    {
      enemyIsPresent = checkEnemyPresent(gameMap.room[getCurrentRoom(gameMap)], 8);
      if(enemyIsPresent == 1)
      {
        deadEnemyID = attackEnemy(&gamePlayer, &gameMap.room[getCurrentRoom(gameMap)].enemy[0], getPlayerDamage(gamePlayer));
      }else
      {
        printf("Nessun nemico con quel nome nella stanza\n");
      }
    }else
    {
      printf("il nemico non esiste\n");
    }
    if(deadEnemyID != 10)
    {
      killEnemy(&gameMap, deadEnemyID);
      deadEnemyID = 10;
      if(getEnemiesConfiguration(gameMap.room[getCurrentRoom(gameMap)]) == 0)
      {
        printf("Hai ucciso tutti i nemici in questa stanza...\n");
        if(getCurrentRoom(gameMap) == 3)
        {
         answerPuzzle(&gameMap); 
        }
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
    //TODO: CONTROLLO SE CI SONO NEMICI VIVI e se ci sono porte
    //ALLORA 
    attraversa(&gameMap);
    
  }else
  
  if (search(&commands,comando)->key == 5) //help TODO: stampare solo la descrizione del comando richiesto, Aiuto attacca- aiuto usa.
  {
    aiuto();
  }else
  if(search(&commands,comando)->key == 6)
  {
    showInventory(gamePlayer);
  }
}
