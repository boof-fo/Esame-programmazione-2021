#include "../headers/parsing.h"

void parsing(list commands,list item1, list item2, list item3, list item4, list item5)
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
    if(getEnemiesConfiguration(game_map.room[getCurrentRoom(game_map)]) != 0)
     printf("Prima di raccogliere oggetti devi aver sconfitto tutti i nemici nella stanza.\n"); 
    else
    if(search(&item1,oggetto)->key == 1)
    {
      takePotion(&game_player, &game_map.room[getCurrentRoom(game_map)]);
    }else
    if(search(&item1,oggetto)->key == 2)
    {
      takeSword(&game_player, &game_map.room[getCurrentRoom(game_map)]);
    }
    else 
    if(search(&item1,oggetto)->key == 3)
    {
      takeChestplate(&game_player, &game_map.room[getCurrentRoom(game_map)]);
    }else
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
        enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 0);
    }else

    if(search(&item2,oggetto)->key == 2)
    {
      enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 1);
    }else 

    if(search(&item2,oggetto)->key == 3)
    {
      enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 2);
    }else

    if(search(&item2,oggetto)->key == 4)
    {
      enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 3);
    }else

    if(search(&item2,oggetto)->key == 5)
    {
      enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 4);
    }else

    if(search(&item2,oggetto)->key == 6)
    {
      enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 5);
    }else

    if(search(&item2,oggetto)->key == 7)
    {
      enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 6);
    }else

    if(search(&item2,oggetto)->key == 8)
    {
      enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 7);
    }else

    if(search(&item2,oggetto)->key == 9)
    {
      enemyIsPresent = checkEnemyPresent(game_map.room[getCurrentRoom(game_map)], 8);
      
    }else
    {
      printf("il nemico non esiste\n");
    }


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
    else
    {
      printf("Nessun nemico con quel nome nella stanza\n");
    }


    if(deadEnemyID != 10)
    {
      killEnemy(&game_map, deadEnemyID);
      deadEnemyID = 10;
      if(getEnemiesConfiguration(game_map.room[getCurrentRoom(game_map)]) == 0)
      {
        printf("Hai ucciso tutti i nemici in questa stanza...\n");
        if(getCurrentRoom(game_map) == 3)
        {
         answerPuzzle(&game_map); 
        }
      }
    }
  }else 


  if (search(&commands,comando)->key == 3)
  {
    if(search(&item3,oggetto)->key == 1)
    {
      usePotion(&game_player);
    }else
    if(search(&item3,oggetto)->key == 2)
    {
      printMap(game_map);
    }else{
      printf("errore3");
    }
  }else 
  

  if (search(&commands,comando)->key == 4)
  {
    if(search(&item5, oggetto)->key== 1)
    {
      walkThroughDoor(&game_map);
    }
    
  }else
  
  if (search(&commands,comando)->key == 5) 
  { 
    int selection;
    if(search(&item5, oggetto)->key== 0)
    {
      help();
    }else
    if(search(&item5, oggetto)->key== 1)
    {
      selection=1;

    }else
    if(search(&item5, oggetto)->key== 2)
    {
      selection=2;

    }else
    if(search(&item5, oggetto)->key== 3)
    {
      selection=3;

    }else
    if(search(&item5, oggetto)->key== 4)
    {
      selection=4;

    }else
    if(search(&item5, oggetto)->key== 5)
    {
      selection=5;
    }else
    if(search(&item5, oggetto)->key== 6)
    {
      selection=6;

    }else
    if(search(&item5, oggetto)->key== 7)
    {
      selection=7;

    }else
    {
      printf("non ho capito, potresti ripetere?");

    }
    helpSelect(selection);
  
  }else
  if(search(&commands,comando)->key == 6 && search(&item4,oggetto)->key == 1)
  {
    showInventory(game_player);
  }else
  {
    printf("\nNon ho capito, potresti ripetere?");
  }
}
