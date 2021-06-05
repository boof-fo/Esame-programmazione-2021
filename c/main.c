#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/world.h"
#include "../headers/player.h"
#include "../headers/enemy.h"
#include "../headers/comandi.h"

char enter = ' ';
char answer[];

int main(){
	printf("\nTi diamo il benvenuto nel nostro gioco: Pirates Fortress, un avventura testuale ambientata in un' isola tropicale dove inpersonificherai Jacob Smith,\nun giovane avventuriero con lo scopo di ritrovare un antico tesoro pirata, ma non di un pirata qualsiasi, bensì del più temuto di tutti i tempi: Il capitano Barbadura,\nconsiderato da molti il re di tutti i pirati dei sette mari, nel corso del diciottesimo secolo lui e la sua spietata ciurma hanno accumulato una ricchezza spropositata in gioelli e dobloni d'oro\n,alcuni documenti e mappe suggeriscono la presenza del famigerato tesoro in un isola sperduta del pacifico, non presente sulle mappe convenzionali, totalmente inesplorata e priva di vita\ndove sorge una fortezza usata ai tempi della colonizzazione inglese del quindicesimo secolo, usata come rifugio dalla ciurma di Barbadura, alcune leggende narrano\nche la ciurma sia ancora presente all'interno della fortezza sotto forma di non-morti affamati di carne umana e che lo spirito del capitano vegli ancora sullo scrigno maledetto.\n");
	
	int exit;

	do
	{
		printf("\nhai compreso bene? si o no \n");
		scanf("%s", answer);
		if(strncmp(answer, "si", sizeof(const char)*2)  == 0)
	{
		printf("\nperfetto, possiamo proseguire\n\n");
		exit = 1;
		EXIT_SUCCESS;
	}
	else if(strncmp(answer, "no",sizeof(const char)*2) == 0)
	{
		printf("\ne non hai capito qualcosa ti basta tornarse su e rileggere, ora proseguiamo\n\n");
		exit = 1;
		EXIT_SUCCESS;
	}
	if (exit != 1)
	printf("\nrisposta non corretta, potresti ripetere rispondendo SI o NO?\n");
		
		
	}
	while(exit!=1);
	
	
	//genera la mappa di gioco
	map map;
	
	//genera giocatore
	player player;
	//imposta valori di default 
	spawnPlayer(&player);
	//azzera i valori dell'inventario
	spawnInventory(&player.inventory);
	
	while (enter != '\r' && enter != '\n') { enter = getchar(); }

	enterRoom(&map, &map.room[6], 6);
	

	showInventory(player.inventory);

	list comandi, item1,item2,item3,item4,item5,attr6;
	comandi.count = 0;
	item1.count = 0;
	item2.count = 0;
	item3.count = 0;
	item4.count = 0;
	item5.count = 0;
	insert(&comandi, 1, "raccogli");
	insert(&comandi, 2, "attacca");
	insert(&comandi, 3, "usa");
	insert(&comandi, 5, "aiuto");
	insert(&comandi, 6, "inventario");
	insert(&item1, 2, "spada");
	insert(&item1, 3, "armatura");
	insert(&item2, 1, "cuoco");
	insert(&item2, 2, "mozzo");
	insert(&item2, 3, "navigatore");
	insert(&item2, 4, "timoniere");
	insert(&item2, 5, "maestro");
	insert(&item2, 6, "cannoniere");
	insert(&item2, 7, "medico");
	insert(&item2, 8, "artigliere");
	insert(&item2, 9, "comandante");
	insert(&item3, 1, "pozione");
	insert(&item3, 2, "mappa");
	insert(&item4, 1, "porta");
	printf("\nInserisci un comando:\n");
	parsing(comandi,item1, item2, item3, item4, item5, attr6);
}