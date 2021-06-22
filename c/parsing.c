#include "../headers/parsing.h"

//Funzione che gestisce gli errori
void error(int errorCode)
{
  if(errorCode == 1)
    printf("Non ho capito bene, potresti ripetere?\n");
  else
  if(errorCode == 2)
    printf("Prima di raccogliere oggetti devi aver sconfitto tutti i nemici nella stanza.\n"); 
  else
  if(errorCode == 3)
    printf("Non ho capito che cosa dovrei raccogliere.\n"); 
  else
  if(errorCode == 4)
    printf("Nessun nemico con quel nome nella stanza\n");
  else
  if(errorCode == 5)
    printf("Non ho capito che cosa dovrei usare.\n"); 
  else
  if(errorCode == 6)
    printf("Non ho capito, forse intendevi 'attraversa porta'?\n"); 
  else
  if(errorCode == 7)
    printf("Non ho capito, forse intendevi 'mostra inventario'?\n"); 
  else
  if(errorCode == 8)
    printf("Non ho capito, forse intendevi 'guarda stanza'?\n"); 
  else
  if(errorCode == 9)
    printf("Su cosa hai bisogno di aiuto? Puoi scrivere 'aiuto comandi' per una lista dei comandi o 'aiuto' seguito da un comando per avere una spiegazione più dettagliata\n"); 
  else
    printf("Errore\n"); 
}

void parsing(list commands,list item1, list item2, list item3, list  item4, list item5, list item6, list item7)
{
  //prende verb e nominal da input
  char verb[20] = {0, };
  char nominal[20] = {0, };
  fflush(stdin);
  scanf("%s" "%s" ,verb, nominal);

  //verb non riconosciuto
  if (search(&commands,verb) == NULL)
  {
    error(1);
  }else 

  //verb RACCOGLI
  if (search(&commands,verb)->key == 1)
  {
    //errore: i nemici nella stanza sono ancora vivi
    if(getEnemiesConfiguration(game_map.room[getCurrentRoom(game_map)]) != 0)
      error(2);
    else
    //errore: l'nominal da raccogliere non esiste
    if(search(&item1,nominal) == NULL)
    {
      error(3);
    }else
    //raccogli pozione
    if(search(&item1,nominal)->key == 1)
    {
      takePotion(&game_player, &game_map.room[getCurrentRoom(game_map)]);
    }else
    //raccogli spada
    if(search(&item1,nominal)->key == 2)
    {
      takeSword(&game_player, &game_map.room[getCurrentRoom(game_map)]);
    }
    else 
    //raccogli armatura
    if(search(&item1,nominal)->key == 3)
    {
      takeChestplate(&game_player, &game_map.room[getCurrentRoom(game_map)]);
    }
    else 
    //raccogli mappa
    if(search(&item1,nominal)->key == 4)
    {
      takeMap(&game_map, &game_player);
    }else
    //raccogli mappa
    if(search(&item1,nominal)->key == 5)
    {
      takeTreasure(&game_map, &game_player);
    }
  }else 

  //verb ATTACCA
  if (search(&commands,verb)->key == 2)
  {
    int deadEnemyID = 10;
    int enemyIsPresent = 0;

    //errore nemico non riconosciuto
    if(search(&item2,nominal) == NULL)
    {
      error(4);
    }else
    //attacca cuoco
    if(search(&item2,nominal)->key == 1)
    {
      //checkEnemyPresent ritorna 0 se non ci sono nemici, 1 se il nemico è a sinistra, 2 se il nemico è a destra, 3 se il nemico è morto
      enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 0);
    }else
    //attacca mozzo
    if(search(&item2,nominal)->key == 2)
    {
      enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 1);
    }else 
    //attacca navigatore
    if(search(&item2,nominal)->key == 3)
    {
      enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 2);
    }else
    //attacca timoniere
    if(search(&item2,nominal)->key == 4)
    {
      enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 3);
    }else
    //attacca maestro
    if(search(&item2,nominal)->key == 5)
    {
      enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 4);
    }else
    //attacca cannoniere
    if(search(&item2,nominal)->key == 6)
    {
      enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 5);
    }else
    //attacca medico
    if(search(&item2,nominal)->key == 7)
    {
      enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 6);
    }else
    //attacca artigliere
    if(search(&item2,nominal)->key == 8)
    {
      enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 7);
    }else
    //attacca capitano
    if(search(&item2,nominal)->key == 9)
    {
      enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 8);
    }

    //controlla la posizione del nemico e lo attacca se non è già morto
    if(enemyIsPresent == 1)
    {
      deadEnemyID = attackEnemy(&game_player, &game_map.room[getCurrentRoom(game_map)].enemy[0]);
    }else
    if(enemyIsPresent == 2)
    {
      deadEnemyID = attackEnemy(&game_player, &game_map.room[getCurrentRoom(game_map)].enemy[1]);
    }else
    if(enemyIsPresent == 3)
    {
      printf("Il nemico è già morto\n");
    }

    //ammazza nemico se è morto
    if(deadEnemyID != 10)
    {
      killEnemy(&game_map, deadEnemyID);
      deadEnemyID = 10;
      if(getEnemiesConfiguration(game_map.room[getCurrentRoom(game_map)]) == 0)
      {
        printf("Hai ucciso tutti i nemici in questa stanza...\n");
        //indovinello in stanza 3
        if(getCurrentRoom(game_map) == 3)
        {
         answerPuzzle(&game_map); 
        }
      }
    }
  }else 

  //verb usa
  if (search(&commands,verb)->key == 3)
  {
    //controlla l'nominal
    if(search(&item3,nominal) == NULL)
    {
      error(5);
    }else
    //usa pozione
    if(search(&item3,nominal)->key == 1)
    {
      usePotion(&game_player);
    }else
    //usa mappa
    if(search(&item3,nominal)->key == 2)
    {
      printMap(game_map, game_player.inventory);
    }
  }else 


  //verb mostra
  if(search(&commands,verb)->key == 4)
  {
    //nominal errato
    if(search(&item4,nominal) == NULL)
    {
      error(7);
    }else
    //mostra inventario
    if(search(&item4,nominal)->key == 1)
    {
      showInventory(game_player);
    }
  }else

 
  //verb aiuto
  if (search(&commands,verb)->key == 5) 
  { 
    int selection;
    //selezione errata
    if(search(&item5, nominal) == NULL)
    {
      error(9);
      selection = 20;
    }else
    if(search(&item5, nominal)->key== 1)
    {
      help();
      selection = 20;
    }else
    if(search(&item5, nominal)->key== 2)
    {
      selection = 0;
    }else
    if(search(&item5, nominal)->key== 3)
    {
      selection = 1;
    }else
    if(search(&item5, nominal)->key== 4)
    {
      selection = 2;
    }else
    if(search(&item5, nominal)->key== 5)
    {
      selection = 3;
    }else
    if(search(&item5, nominal)->key== 6)
    {
      selection = 4;
    }else
    if(search(&item5, nominal)->key== 7)
    {
      selection = 5;
    }else
    if(search(&item5, nominal)->key== 8)
    {
      selection = 6;
    }

    if(selection != 20)
      helpSelect(selection);
  }else

  //verb attraversa
  if (search(&commands,verb)->key == 6)
  {
    //nominal errato
    if(search(&item6, nominal) == NULL)
    {
      error(6);
    }else
    //attraversa porta
    if(search(&item6, nominal)->key == 1)
    {
      walkThroughDoor(&game_map, game_player);
    }
  }else

  //verb guarda
  if (search(&commands,verb)->key == 7)
  {
    //nominal errato
    if(search(&item7,nominal) == NULL)
      error(8);
    else
    //guarda stanza
    if(search(&item7,nominal)->key == 1)
    {
      printf("\n\n");
      describeRoom(game_map.room[getCurrentRoom(game_map)]);
      printf("\n");
    }
  }
}
