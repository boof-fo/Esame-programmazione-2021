#include "../headers/main.h"
#include "../headers/comandi.h"


int main(){
	printf("\nTi diamo il benvenuto nel nostro gioco: Pirates Fortress, un avventura testuale ambientata in un' isola tropicale dove inpersonificherai Jacob Smith,\nun giovane avventuriero con lo scopo di ritrovare un antico tesoro pirata, ma non di un pirata qualsiasi, bensì del più temuto di tutti i tempi: Il capitano Barbadura,\nconsiderato da molti il re di tutti i pirati dei sette mari, nel corso del diciottesimo secolo lui e la sua spietata ciurma hanno accumulato una ricchezza spropositata in gioelli e dobloni d'oro\n,alcuni documenti e mappe suggeriscono la presenza del famigerato tesoro in un isola sperduta del pacifico, non presente sulle mappe convenzionali, totalmente inesplorata e priva di vita\ndove sorge una fortezza usata ai tempi della colonizzazione inglese del quindicesimo secolo, usata come rifugio dalla ciurma di Barbadura, alcune leggende narrano\nche la ciurma sia ancora presente all'interno della fortezza sotto forma di non-morti affamati di carne umana e che lo spirito del capitano vegli ancora sullo scrigno maledetto.\n");
	
	char enter = ' ';
	char answer[2];
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
		printf("\nrisposta non corretta, potresti ripetere rispondendo Si o No?\n");
	}while(exit!=1);
	
	//imposta valori di default 
	spawnPlayer(&gamePlayer);
	//azzera i valori dell'inventario
	spawnInventory(&gamePlayer.inventory);
	
	while (enter != '\r' && enter != '\n') { enter = getchar(); }


	enterRoom(&gameMap, 3);
	

	showInventory(gamePlayer.inventory);



	list commands, roomItems, enemies, inventoryItems, doors, puzzle, attr6;
	commands.count = 0;
	roomItems.count = 0;
	enemies.count = 0;
	inventoryItems.count = 0;
	doors.count = 0;
	puzzle.count = 0;

	insert(&commands, 1, "raccogli");
	insert(&commands, 2, "attacca");
	insert(&commands, 3, "usa");
	insert(&commands, 5, "aiuto");
	insert(&commands, 6, "inventario");

	insert(&roomItems, 1, "pozione");
	insert(&roomItems, 2, "spada");
	insert(&roomItems, 3, "armatura");

	insert(&enemies, 1, "cuoco");
	insert(&enemies, 2, "mozzo");
	insert(&enemies, 3, "navigatore");
	insert(&enemies, 4, "timoniere");
	insert(&enemies, 5, "maestro");
	insert(&enemies, 6, "cannoniere");
	insert(&enemies, 8, "artigliere");
	insert(&enemies, 9, "comandante");

	insert(&inventoryItems, 1, "pozione");
	insert(&inventoryItems, 2, "mappa");

	insert(&doors, 1, "porta");

	while(true)
	{
		printf("\nInserisci un comando:\n");
		parsing(commands, roomItems, enemies, inventoryItems, doors, puzzle, attr6);
	}
}