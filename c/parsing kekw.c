#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <main.h>
#define true 1
#define false 0


void inserstr(char stringa1[],char stringa2[]){
 int  lun = strlen(stringa2);
 int i= 0;
 while(i< lun ){
   stringa1[i] = stringa2[i];
   i++;
 }
}
int  ceck(char stringa1[],char stringa2[])
  {
    int i = 0;
    int lun1,lun2;
    lun1 = strlen(stringa1);
    lun2 = strlen(stringa2);
      if((lun2 > lun1) || (lun2 < lun1)){
        return false;
        }else{
          
          while(i< lun2){
            if (stringa1[i] == stringa2[i]){
              i++;
              }else{
                return false;

              }
            }
          }
          if(i == lun2){
            return true;
            }else{
            return false;
          }
  }
  

typedef struct node
{
    
    char string[20];
    int  key;


    // puntatore al nodo precedente
    struct node *prev;

    // puntatore al nodo successivo
    struct node *next;
} node;

typedef struct list
{
    // tiene traccia di quanti nodi sono presenti all'interno della lista
    int count;

    // puntatore al primo nodo della lista
    struct node *header;

    // puntatore all'ultimo nodo della lista
    struct node *tailer;
} list;

void insert(list *list, int new_key,char new_string[])
{
    // creo il nuovo nodo e gli alloco uno spazio di memoria
    node *new_node;
    new_node = malloc(sizeof(node));

    // inizializzo il nuovo nodo e gli inserisco il nuovo dato
    new_node->key= new_key;
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
node * search(list *list, char string[])
{
    node *tmp;
    tmp = list->header;

    // scorro la lista cercando value
    // ritorno l'indirizzo del primo nodo che contiene value
    // altrimenti continuo a scorrere la lista
    while (tmp != NULL)
    {

        if (ceck(tmp->string,string))
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

        if (ceck(tmp->string,string))
            return true;

        tmp = tmp->next;
    }

    // se non trovo nessun nodo contenente value, ritorno NULL
    return false;
}
void parsing(){
     char comando[20] = {0};
    char oggetto[20] = {0};
    list comandi;
    list item1,item2,item3,item4,item5,attr6; 
   
     
    
    sscanf("%[^ ]" "%[^ ]" ,comando,oggetto);
    if (search(&comandi,comando) == NULL){
      printf("frocio hai sbagliato");
    }else if (search(&comandi,comando)->key == 1){
      if(searchitem(&item1,oggetto)){
        //raccogli(oggetto)
        printf("raccogli");
        printf("errore");
      }
     
    }else if (search(&comandi,comando)->key == 2){
      if(searchitem(&item2,oggetto)){
        //attacca(oggetto)
        printf("attaca");
      }else{
        printf("errore");
      }
    }else if (search(&comandi,comando)->key == 3){
      if(searchitem(&item3,oggetto)){
        //usa(oggetto)
        printf("usa");
      }else{
        printf("errore");
      }
    }else if (search(&comandi,comando)->key == 4){
      if(searchitem(&item4,oggetto)){
        //attraversa(oggetto)
        printf("attraversa");
      }else{
        printf("errore");
      }
    }else if (search(&comandi,comando)->key == 5){
      printf("aiuto");

        //aiuto
      
    }else if(search(&comandi,comando)->key == 6){
 //////inventario
 printf("inventario");
  }else if(search(&comandi,comando)->key == 7){
    if( checkRoomEmpty(gameMap.room[getCurrentRoom(gameMap)== 1){
      printf("CI SONO ANCORA DEI NEMICI NON PUo
      I SFUGGIRE");
    }else{
      //attraversa()
    }
 
  }else{
          printf("errore");
  }
  
  }

  list comandi;
list item1,item2,item3,item4,item5,attr6; 

 insert(&comandi,1,"raccogli");
 insert(&comandi,2,"attaca");
 insert(&comandi , 3 , "usa");
 insert(&comandi , 5 , "aiuto");
 insert(&comandi , 6 , "inventario");
 insert(&comandi , 7 , "attraversa");
 insert(&item1 , 2 , "spada");
insert(&item1 , 3 , "armatura");

insert(&item2 , 1 , "cuoco");
insert(&item2 , 2 , "mozzo");
insert(&item2 , 3 , "navigatore");
insert(&item2 , 4 , "timoniere");
insert(&item2 , 5 , "maestro");
insert(&item2 , 6 , "cannoniere");
insert(&item2 , 7 , "medico");
insert(&item2 , 8 , "artigliere");
insert(&item2 , 9 , "comandante");

insert(&item3 , 1 , "pozione");
insert(&item3 , 2 , "mappa");

insert(&item4 , 1 , "porta");

int main{
  
  parsing();

}