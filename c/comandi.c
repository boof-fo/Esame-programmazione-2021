#include "../headers/comandi.h"
#include "../headers/main.h"

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
				{
					i++;
				}else return false;
      }
    }
    if(i == lun2)
    {
    	return true;
    }else return false;
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


int searchitem(list *list, char string[])
{
    node *tmp;
    tmp = list->header;
    // scorro la lista cercando value
    // ritorno l'indirizzo del primo nodo che contiene value
    // altrimenti continuo a scorrere la lista
    while (tmp != NULL)
    {
        if (check(tmp->string,string))
            return true;
        tmp = tmp->next;
    }
    // se non trovo nessun nodo contenente value, ritorno NULL
    return false;
}


void parsing(list comandi,list item1, list item2, list item3, list item4, list item5, list attr6)
{
  char comando[20] = {0, };
  char oggetto[20] = {0, };
  fflush(stdin);
  scanf("%s" "%s" ,comando, oggetto);


  if (search(&comandi,comando) == NULL)
  {
    printf("Comando errato\n");
  }else 


  if (search(&comandi,comando)->key == 1)
  {
    if(searchitem(&item1,oggetto))
    {
      if(check(oggetto, "pozione"))
        {
          takePotion(&gamePlayer.inventory, &gameMap.room[gameMap.currentRoom]);
        }
        else
        if(check(oggetto, "spada"))
        {
          
        }
        else 
        if(check(oggetto, "armatura"))
        {
          
        }
        else
        {
          printf("oggetto errato\n");
        }
    }
  }else 


  if (search(&comandi,comando)->key == 2)
  {
    if(searchitem(&item2,oggetto))
    {
      //attacca(oggetto)
      printf("attacca");
    }else{
      printf("errore2");
    }
  }else 
  

  if (search(&comandi,comando)->key == 3)
  {
    if(searchitem(&item3,oggetto))
    {
      //usa(oggetto)
      printf("usa");
    }else{
      printf("errore3");
    }
  }else 
  

  if (search(&comandi,comando)->key == 4)
  {
    if(searchitem(&item4,oggetto))
    {
      //attraversa(oggetto)
      printf("attraversa");
    }else
      printf("errore4");
  }else 
  
  
  if (search(&comandi,comando)->key == 5)
  {
    printf("aiuto");
      //aiuto
  }else 


  if(search(&comandi,comando)->key == 7)
  {
    //stampa l'inventario
    
  }else
  {
    printf("errore5");
  }
}


