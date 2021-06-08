#include "../headers/room.h"

//imposta identificativo
void setRoomID(room *room, int ID)
{
	room->ID = ID;
}
//imposta il numero di pozioni in una stanza
void setRoomPotions(room *room, int num)
{
	room->potions = num;
}
//imposta l'ID della spada in una stanza
void setRoomSword(room *room, int num)
{
	room->sword = num;
}
//presenza armatura
void setRoomChestplate(room *room, bool plate)
{
	room->chestplate = plate;
}
//imposta il numero di nemici
void setEnemiesConfiguration(room *room, int enemyConfig)
{
	room->enemiesConfiguration = enemyConfig;
}

//imposta il numero di porte (stanze collegate)
void setRoomDoors(room *room, int doors)
{
	room->doors = doors;
}

void removeRoomPotion(room *room)
{
	room->potions -= 1;
}
void removeRoomSword(room *room)
{
	room->sword = 0;
}
void removeRoomChestplate(room *room)
{
	room->sword = false;
}


int getRoomID(room room)
{
	return room.ID;
}
int getRoomPotions(room room)
{
	return room.potions;
}
int getRoomSword(room room)
{
	return room.sword;
}
int getRoomChestplate(room room)
{
	return room.chestplate;
}
int getEnemiesConfiguration(room room)
{
	return room.enemiesConfiguration;
}
int getRoomDoors(room room)
{
	return room.doors;
}


int checkEnemyPresent(room room, int targetEnemyID)
{
	if(getEnemiesConfiguration(room) != 0)
	{
		if(getEnemyID(room.enemy[0]) == targetEnemyID)
			return 1;
		else
		if(getEnemyID(room.enemy[1]) == targetEnemyID)
			return 2;
		else return 0;
	}else
	return 0;
}
int checkRoomEmpty(room room)
{
	if(room.enemiesConfiguration == 0)
		return 0;
	else
		return 1;
}

//imposta i valori di una stanza
void populateRoom(room* room, int ID, int potions, int sword, bool chestplate, int enemiesConfig, int doors)
{
	setRoomID(room, ID);
	setRoomPotions(room, potions);
	setRoomSword(room, sword);
	setRoomChestplate(room, chestplate);
	setEnemiesConfiguration(room, enemiesConfig);
	setRoomDoors(room, doors);
}

void spawnRoom(room* room, int roomNumber)
{
if (roomNumber == 0)
	//populateRoom(room* room, int ID, int potions, int sword, bool chestplate, int enemyConfiguration);
		{
			populateRoom(room, 0, 0, 0, false, 0, 2);
		}
		if (roomNumber == 1)
		{
			populateRoom(room, 1, 1, 0, false, 1, 1);
		}
		if (roomNumber == 2)
		{
			populateRoom(room, 2, 0, 0, false, 1, 1);
		}
		if (roomNumber == 3)
		{
			populateRoom(room, 3, 1, 1, true, 3, 2);
		}
		if (roomNumber == 4)
		{
			populateRoom(room, 4, 0, 2, false, 3, 1);
		}
		if (roomNumber == 5)
		{
			populateRoom(room, 5, 2, 2, false, 3, 1);
		}
		if (roomNumber == 6)
		{
			populateRoom(room, 6, 1, 1, false, 1, 1);
		}
}

void describeRoom(room room, int ID)
{
	printf("stanza %d\n", ID);

	int potions = room.potions;
	int sword = room.sword;
	bool chestplate = room.chestplate;
	int enemiesConfiguration = room.enemiesConfiguration;

	if(potions == 0 && sword == 0 && chestplate == false && enemiesConfiguration == 0)
	{
		//TODO: descrizione stanza vuota
		printf("\nstanza vuota\n");
		printf("ci sono %d porte\n", room.doors);
	}
	else
	{
		if (ID == 0)
			printf("\nl'ingresso della fortezza appare come una stanza vuota e silenziosa,l'unica fonte di luce è quella che penetra dalla porta principale, ma una volta chiusa l'unica fonte di luce saranno delle fiaccole sui muri che ardono di una fiamma blu apparentemente inestinguibile, non ci sono oggetti ne nemici, goditi questi ultimi atti di tranquillità perchè da qui in poi non sarà più così\n");
		if (ID == 1)
			printf("\nLa cucina appare come un luogo buio e maleodorante, ci sono macchie di cibo ovunque e stoviglie rotte per terra, su uno dei tanti scaffali è presente una pozione curativa che potrebbe tornarti utile dopo il combattimento. All'improvviso senti qualcosa muoversi lentamente verso di te e il pavimento tremare ad ogni suo passo, è il Cuoco! il tuo primo nemico. \n");
		if (ID == 2)
			printf("\nLa sala da pranzo appare come una stanza buia con un lungo tavolo da pranzo di legno, le sedie ormai rotte e sparse per la stanza sono inutilizzabili e insieme a pezzi di bottiglie di vetro e di piatti rotti ricoprono interamente il pavimento, all'improvviso senti dei passi rumorosi che frantumano i detriti avanzare verso di te, si tratta del Mozzo! presto affrontalo.\n");
		if (ID == 3)
			printf("\nIl salone è la stanza più grande della fortezza e anche la più misteriosa, qui è dove si svolgevano le attività quotidiane della ciurma e dove trascorrevano la maggior parte del tempo, ci sono delle panche ormai distrutte con delle librerie vuote ed impolverate, ci sono delle piccole finestelle da cui la luce penetra lievemente creando un sottile fascio di luce che colpisce la statua di un gargoyle, sembrerebbe coprire l'entrata di un passaggio segreto, cosa si celerà dall'altra parte? in una delle librerie è presente una spada ricurva e una pozione, ma prima di poterle raccogliere dovrai affrontare il Navigatore e Il timoniere.\n")
		if (ID == 4)
			printf("\nL'armeria è una stanza angusta e stretta con un forte odore di polvere da sparo nell'aria, accostati lungo i muri ci sono dei mobiletti per riporre le armi ormai vuoti da tanto tempo, negli angoli della stanza sono presenti dei barili di legno pieni dove prima era conservata la polvere da sparo e i proiettili dei cannoni, all'improvviso nella stanza fanno irruzione due nemici: Il Maestro d'Armi e Il Cannoniere!\n");
		if (ID == 5)
			printf("\nL'infermeria è la stanza più piccola della fortezza, è rimasto solo una brandina e qualche teca di vetro dove prima venivano conservate le medicine e i sieri,\n");
		if (ID == 6)
			printf("\n\n");
		if (ID == 7)
			printf("\n\n");
		if (ID == 8)
			printf("\n\n");
		printf("Nella stanza: \n");
		if(potions != 0)
		{
			printf("ci sono:%d Pozioni da raccogliere\n", potions);
		}
		else
		{
			printf("sembrerebbe non ci siano pozioni da raccogliere.\n")
		}
		if(sword != 0)
		{
			if(sword == 1)
			{
				printf("c'è una spada ricurva\n");
			}	
			else if(sword == 2)
			{
				printf("c'è un' alabarda.\n");
			}
		
		}
		
	}	


}

void PuzzleRoom(room room, int ID)
{
//La statua del gargoyle si è attivata e ti sta parlando:'Scende da una nave prima di ogni marinaio e di ogni passeggero. Cos’è? risolvi l'idnovinello e avrai un premio.'\n");
		//risposta:L'ancora
}