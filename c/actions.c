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
  if(getEnemiesConfiguration(gameMap.room[getCurrentRoom(gameMap)]))
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