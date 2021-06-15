#ifndef COMANDI_H
#define COMANDI_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0

#include "../headers/string.h"
#include "../headers/actions.h"
#include "../headers/world.h"
#include "../headers/room.h"
#include "../headers/inventory.h"
#include "../headers/player.h"
#include "../headers/enemy.h"

typedef struct node
{
	char string[20];
	int  key;

	// puntatore al nodo precedente
	struct node *prev;
	//puntatore al nodo successivo
	struct node *next;
}node;

typedef struct list
{
    // tiene traccia di quanti nodi sono presenti all'interno della lista
		int count;
    // puntatore al primo nodo della lista
    struct node *header;
    // puntatore all'ultimo nodo della lista
    struct node *tailer;
}list;

void inserstr(char stringa1[],char stringa2[]);

int check(char stringa1[],char stringa2[]);

void insert(list *list, int new_key,char new_string[]);

node *search(list *list, char string[]);

void parsing(list commands,list item1, list item2, list item3, list attr6);



#endif