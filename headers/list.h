#ifndef LIST_H
#define LIST_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/string.h"

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

void insert(list *list, int new_key,char new_string[]);

node *search(list *list, char string[]);

#endif