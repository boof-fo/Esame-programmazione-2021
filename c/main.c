#include "../headers/main.h"
#include "../headers/comandi.h"

int main()
{
	printf("\n╔═══════════════════════════════════════════════════════════════════════════╗\n║Ti diamo il benvenuto nel nostro gioco  P I R A T E S   F O R T E S S      ║\n║un avventura ambientata in un' isola tropicale dove impersonificherai      ║\n║Jacob Smith, un giovane avventuriero con lo scopo di ritrovare un antico   ║\n║tesoro pirata, del più temuto di tutti i tempi: Il capitano Barbadura.     ║\n║considerato da molti il re di tutti i pirati dei sette mari, nel corso del ║\n║diciottesimo secolo lui e la sua ciurma accumularono una ricchezza enorme  ║\n║in gioelli e dobloni d'oro.                                                ║\n║alcuni documenti e mappe suggeriscono la presenza del famigerato tesoro in ║\n║un isola sperduta del pacifico, non presente sulle mappe convenzionali,    ║\n║totalmente inesplorata e priva di vita dove sorge una fortezza usata ai    ║\n║tempi della colonizzazione inglese del quindicesimo secolo, usata come     ║\n║rifugio dalla ciurma di Barbadura, alcune leggende narrano  che la ciurma  ║\n║sia ancora presente all'interno della fortezza sotto forma di non-morti    ║\n║affamati di carne umana e che lo spirito del capitano vegli ancora sullo   ║\n║scrigno maledetto di cui ti dovrai impossessare.                           ║\n║═══════════════════════════════════════════════════════════════════════════║\n║ Hai bisogno di istruzioni? Si o No?                                       ║\n╚═══════════════════════════════════════════════════════════════════════════╝\n");
	
	char enter = ' ';
	char answer[2];
	int exit;

	do
	{
		scanf("%s", answer);
		if(strncmp(answer, "si", sizeof(const char)*2)  == 0)
		{
			printf("\nperfetto, possiamo proseguire\n\n");
			exit = 1;
			EXIT_SUCCESS;
		}
		else if(strncmp(answer, "no",sizeof(const char)*2) == 0)
		{
			printf("\nSe non hai capito qualcosa ti basta tornarse su e rileggere, ora proseguiamo\n\n");
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
	
	do{enter = getchar();}while(enter != '\r' && enter != '\n');

	spawnWorld(&gameMap);

	enterRoom(&gameMap, 3);



	list commands, roomItems, enemies, inventoryItems, doors, attr6;
	commands.count = 0;
	roomItems.count = 0;
	enemies.count = 0;
	inventoryItems.count = 0;
	doors.count = 0;


	insert(&commands, 1, "raccogli");
	insert(&commands, 2, "attacca");
	insert(&commands, 3, "usa");
	insert(&commands, 5, "aiuto");
	insert(&commands, 4, "attraversa");
	insert(&commands, 6, "mostra");

	insert(&roomItems, 1, "pozione");
	insert(&roomItems, 2, "spada");
	insert(&roomItems, 3, "armatura");

	insert(&enemies, 1, "cuoco");
	insert(&enemies, 2, "mozzo");
	insert(&enemies, 3, "navigatore");
	insert(&enemies, 4, "timoniere");
	insert(&enemies, 5, "maestro");
	insert(&enemies, 6, "cannoniere");
	insert(&enemies, 7, "medico");
	insert(&enemies, 8, "artigliere");
	insert(&enemies, 9, "comandante");

	insert(&inventoryItems, 1, "pozione");
	insert(&inventoryItems, 2, "mappa");

	insert(&doors, 1, "porta");

	while(true)
	{
		printf("\nInserisci un comando:\n");
		parsing(commands, roomItems, enemies, inventoryItems, attr6);
	}



}