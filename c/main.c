#include "../headers/main.h"
#include "../headers/comandi.h"

int main()
{
	list commands, items, enemies, inventoryItems, doors, utilities, actions;
	commands.count = 0;
	items.count = 0;
	enemies.count = 0;
	inventoryItems.count = 0;
	doors.count = 0;
	utilities.count = 0;
	actions.count= 0;

	insert(&commands, 1, "raccogli");
	insert(&commands, 2, "attacca");
	insert(&commands, 3, "usa");
	insert(&commands, 5, "aiuto");
	insert(&commands, 4, "attraversa");
	insert(&commands, 6, "mostra");
	insert(&commands, 7, "guarda");

	insert(&items, 1, "pozione");
	insert(&items, 2, "spada");
	insert(&items, 3, "armatura");

	insert(&enemies, 1, "cuoco");
	insert(&enemies, 2, "mozzo");
	insert(&enemies, 3, "navigatore");
	insert(&enemies, 4, "timoniere");
	insert(&enemies, 5, "maestro");
	insert(&enemies, 6, "cannoniere");
	insert(&enemies, 7, "medico");
	insert(&enemies, 8, "artigliere");
	insert(&enemies, 9, "capitano");

	insert(&inventoryItems, 1, "pozione");
	insert(&inventoryItems, 2, "mappa");

	insert(&doors, 1, "porta");
	
	insert(&utilities, 1, "inventario");
	insert(&utilities, 2, "comandi");

	insert(&actions, 0, "comandi");
	insert(&actions, 1, "raccogli");
	insert(&actions, 2, "attacca");
	insert(&actions, 3, "usa");
	insert(&actions, 5, "aiuto");
	insert(&actions, 4, "attraversa");
	insert(&actions, 6, "mostra");
	insert(&actions, 7, "guarda");
	
	printf("\n╔═══════════════════════════════════════════════════════════════════════════╗\n║Ti diamo il benvenuto nel nostro gioco  P I R A T E S   F O R T E S S      ║\n║un avventura ambientata in un' isola tropicale dove impersonificherai      ║\n║Jacob Smith, un giovane avventuriero con lo scopo di ritrovare un antico   ║\n║tesoro pirata, del più temuto di tutti i tempi: Il capitano Barbadura,     ║\n║considerato da molti il re di tutti i pirati dei sette mari, nel corso del ║\n║diciottesimo secolo lui e la sua ciurma accumularono una ricchezza enorme  ║\n║in gioelli e dobloni d'oro.                                                ║\n║Alcuni documenti e mappe suggeriscono la presenza del famigerato tesoro in ║\n║un'isola sperduta del pacifico, non presente sulle mappe convenzionali,    ║\n║totalmente inesplorata e priva di vita dove sorge una fortezza usata ai    ║\n║tempi della colonizzazione inglese del quindicesimo secolo come rifugio    ║\n║dalla ciurma di Barbadura, alcune leggende narrano  che la ciurma sia      ║\n║ancora presente all'interno della fortezza sotto forma di non-morti        ║\n║affamati di carne umana e che lo spirito del capitano vegli ancora sullo   ║\n║scrigno maledetto di cui ti dovrai impossessare.                           ║\n║═══════════════════════════════════════════════════════════════════════════║\n║ Hai bisogno di istruzioni? Si o No?                                       ║\n╚═══════════════════════════════════════════════════════════════════════════╝\n");
	
	char enter = 'a';
	char answer[2];
	int exit;

	do
	{
		scanf("%s", answer);
		if(strncmp(answer, "si", sizeof(const char)*2)  == 0)
		{
			help();
			printf("\n\n\nPremi invio per continuare...\n");
			fflush(stdin);
			enter = getchar();
			exit = 1;
		}
		else if(strncmp(answer, "no",sizeof(const char)*2) == 0)
		{//TODO: comando help
			printf("\nPerfetto, possiamo proseguire. Premi invio per continuare...\n\n");
			fflush(stdin);
			enter = getchar();
			exit = 1;
		}else
		{
			printf("\nrisposta non corretta, potresti ripetere rispondendo si o no?\n");
		}
	}while(exit!=1 && enter != '\n');
	
	//imposta valori di default 
	spawnPlayer(&game_player);

	spawnWorld(&game_map);

	enterRoom(&game_map, 0);


	while(true)
	{
		printf("\nInserisci un comando:\n");
		parsing(commands, items, enemies, inventoryItems, utilities);
	}

}