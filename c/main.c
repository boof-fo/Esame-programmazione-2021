#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/world.h"
#include "../headers/player.h"
#include "../headers/enemy.h"

char enter;
char answer[];


int main(){
	printf("\nTi diamo il benvenuto nel nostro gioco: Pirates Fortress, un avventura testuale ambientata in un' isola tropicale dove inpersonificherai Jacob Smith,\n
		un giovane avventuriero con lo scopo di ritrovare un antico tesoro pirata, ma non di un pirata qualsiasi, bensì del più temuto di tutti i tempi: Il capitano Barbadura,\n		
		considerato da molti il re di tutti i pirati dei sette mari, nel corso del diciottesimo secolo lui e la sua spietata ciurma hanno accumulato una ricchezza spropositata in gioelli e dobloni d'oro\n,
		alcuni documenti e mappe suggeriscono la presenza del famigerato tesoro in un isola sperduta del pacifico, non presente sulle mappe convenzionali, totalmente inesplorata e priva di vita\n
		 dove sorge una fortezza usata ai tempi della colonizzazione inglese del quindicesimo secolo, usata come rifugio dalla ciurma di Barbadura, alcune leggende narrano\n
		 che la ciurma sia ancora presente all'interno della fortezza sotto forma di non-morti affamati di carne umana e che lo spirito del capitano vegli ancora sullo scrigno maledetto.\n")
	printf("\nhai compreso bene? si o no \n")
	
	scanf("%s", answer);

	if(stricmp(answer, "yes") == 0)
	{
		printf("\nperfetto possiamo proseguire");
		EXIT_SUCCESS
	}
	else if(tricmp(answer, "no") == 0))
	{
		printf("\nse non hai capito qualcosa ti basta tornare su e rileggere, ora proseguiamo");
	}
	else 
	{
		//TODO: tornare indietro alla domanda se non si risponde si o no
	}
	
	//genera la mappa di gioco
	map map;
	
	//genera giocatore
	player player;
	//imposta valori di default 
	spawnPlayer(&player);
	//azzera i valori dell'inventario
	spawnInventory(&player.inventory);
	
	while (enter != '\r' && enter != '\n') { enter = getchar(); }
	printf("benvenuto nel giokino :)\n");

	enterRoom(&map, &map.room[6], 6);
	

	showInventory(player.inventory);
}