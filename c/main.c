#include "../headers/main.h"
#include "../headers/parsing.h"

int main()
{
	list commands, items, enemies, inventoryItems, utilities, actions, doors, look;
	commands.count = 0;
	items.count = 0;
	enemies.count = 0;
	inventoryItems.count = 0;
	doors.count = 0;
	utilities.count = 0;
	actions.count = 0;
	look.count = 0;

	insert(&commands, 1, "raccogli");
	insert(&commands, 2, "attacca");
	insert(&commands, 3, "usa");
	insert(&commands, 4, "mostra");
	insert(&commands, 5, "aiuto");
	insert(&commands, 6, "attraversa");
	insert(&commands, 7, "guarda");

	insert(&items, 1, "pozione");
	insert(&items, 2, "spada");
	insert(&items, 3, "armatura");
	insert(&items, 4, "mappa");
	insert(&items, 5, "tesoro");

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

	insert(&utilities, 1, "inventario");
	
	insert(&actions, 1, "comandi");
	insert(&actions, 2, "raccogli");
	insert(&actions, 3, "attacca");
	insert(&actions, 4, "usa");
	insert(&actions, 5, "aiuto");
	insert(&actions, 6, "attraversa");
	insert(&actions, 7, "mostra");
	insert(&actions, 8, "guarda");

	insert(&doors, 1, "porta");

	insert(&look, 1, "stanza");

	printf("\n╔═══════════════════════════════════════════════════════════════════════════╗\n║Ti diamo il benvenuto nel nostro gioco  P I R A T E S   F O R T E S S      ║\n║un avventura ambientata in un' isola tropicale dove impersonificherai      ║\n║Jacob Smith, un giovane avventuriero con lo scopo di ritrovare un antico   ║\n║tesoro pirata, del più temuto di tutti i tempi: Il capitano Barbadura,     ║\n║considerato da molti il re di tutti i pirati dei sette mari, nel corso del ║\n║diciottesimo secolo lui e la sua ciurma accumularono una ricchezza enorme  ║\n║in gioelli e dobloni d'oro.                                                ║\n║Alcuni documenti e mappe suggeriscono la presenza del famigerato tesoro in ║\n║un'isola sperduta del pacifico, non presente sulle mappe convenzionali,    ║\n║totalmente inesplorata e priva di vita dove sorge una fortezza usata ai    ║\n║tempi della colonizzazione inglese del quindicesimo secolo come rifugio    ║\n║dalla ciurma di Barbadura, alcune leggende narrano  che la ciurma sia      ║\n║ancora presente all'interno della fortezza sotto forma di non-morti        ║\n║affamati di carne umana e che lo spirito del capitano vegli ancora sullo   ║\n║scrigno maledetto di cui ti dovrai impossessare.                           ║\n║═══════════════════════════════════════════════════════════════════════════║\n║ Hai bisogno di istruzioni? Si o No?                                       ║\n╚═══════════════════════════════════════════════════════════════════════════╝\n");
	
	int exit = 0;
	char answer[2];
	do
	{
		scanf("%s", answer);
		if(strncmp(answer, "si", sizeof(const char)*2)  == 0)
		{
			help();
			printf("\nPerfetto, possiamo continuare...\n");
			exit = 1;
		}
		else if(strncmp(answer, "no",sizeof(const char)*2) == 0)
		{
			exit = 1;
			printf("\nPerfetto, possiamo continuare...\n");
		}else
		{
			printf("\nRisposta non corretta, potresti ripetere rispondendo si o no?\n");
		}
	}while(exit != 1);
	enterToContinue();
	
	
	//imposta valori di default 
	spawnPlayer(&game_player);

	spawnWorld(&game_map);

	enterRoom(&game_map, game_player, 0);


	while(true)
	{
		printf("\nInserisci un comando:\n");
		//list commands, items, enemies, inventoryItems, doors, utilities, actions, look;
		parsing(commands, items, enemies, inventoryItems, utilities, actions, doors, look);
	}

}