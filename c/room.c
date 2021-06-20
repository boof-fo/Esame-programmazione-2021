#include "../headers/room.h"

//imposta identificativo
void setRoomID(room *room, int room_ID)
{
	room->ID = room_ID;
}
int getRoomID(room room)
{
	return room.ID;
}

//imposta il numero di pozioni in una stanza
void setRoomPotions(room *room, int potions_number)
{
	room->potions = potions_number;
}
int getRoomPotions(room room)
{
	return room.potions;
}

//imposta l'ID della spada in una stanza
void setRoomSword(room *room, int sword_ID)
{
	room->sword = sword_ID;
}
int getRoomSword(room room)
{
	return room.sword;
}

//presenza armatura
void setRoomChestplate(room *room, int chestplate_ID)
{
	room->chestplate = chestplate_ID;
}
int getRoomChestplate(room room)
{
	return room.chestplate;
}

//imposta il numero di nemici
void setEnemiesConfiguration(room *room, int enemies_config)
{
	room->enemies_configuration = enemies_config;
}
int getEnemiesConfiguration(room room)
{
	return room.enemies_configuration;
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
	room->sword = 0;
}


//imposta i valori di una stanza
void populateRoom(room* room, int ID, int potions, int sword, int chestplate, int enemies_config)
{
	setRoomID(room, ID);
	setRoomPotions(room, potions);
	setRoomSword(room, sword);
	setRoomChestplate(room, chestplate);
	setEnemiesConfiguration(room, enemies_config);
}


/**ritorna:
 * 0 se il nemico non esiste, 
 * 1 se il nemico è a sinistra, 
 * 2 se il nemico è a destra, 
 * 3 se il nemico è presente ma è morto
*/
int checkEnemyPresent(room room, int target_enemy_ID)
{
	int enemy_position = 0;

	//controlla se il nemico è a sinistra
	if(getEnemyID(room.enemy[0]) == target_enemy_ID)
	{//controlla se il nemico è vivo
		if(getEnemyHP(room.enemy[0]) != 0)
			enemy_position = 1;
		else
			enemy_position = 3;
	}else
	//controlla se il nemico è a destra
	if(getEnemyID(room.enemy[1]) == target_enemy_ID)
	{
		//controlla se il nemico è vivo
		if(getEnemyHP(room.enemy[1]) != 0)
			enemy_position = 2;
		else
			enemy_position = 3;
	}
	else 
	{
		//ritorna 0 se non si trova nella stanza
		enemy_position = 0;
	}
	return enemy_position;
}




void spawnRoom(room* room, int roomNumber)
{
	//populateRoom(room *room, int ID, int potions, int sword, int chestplate, int enemies_config, int doors)
	if (roomNumber == 0)
	{
		populateRoom(room, 0, 0, 0, 0, 0);
		setEnemiesConfiguration(room, 0);
		spawnEnemy(&room->enemy[0], 10, 0, 0, 0);
		spawnEnemy(&room->enemy[1], 10, 0, 0, 0);
	}else
	if (roomNumber == 1)
	{
		populateRoom(room, 1, 1, 0, 0, 1);
		setEnemiesConfiguration(room, 1);
		spawnEnemy(&room->enemy[0], 0, 30, 5, 0);
		spawnEnemy(&room->enemy[1], 10, 0, 0, 0);
	}else
	if (roomNumber == 2)
	{
		populateRoom(room, 2, 0, 0, 0, 1);
		setEnemiesConfiguration(room, 1);
		spawnEnemy(&room->enemy[0], 1, 30, 5, 0);
		spawnEnemy(&room->enemy[1], 10, 0, 0, 0);
	}else
	if (roomNumber == 3)
	{
		populateRoom(room, 3, 1, 1, 1, 3);
		setEnemiesConfiguration(room, 3);
		spawnEnemy(&room->enemy[0], 2, 35, 7, 0);
		spawnEnemy(&room->enemy[1], 3, 35, 7, 0);
	}else
	if (roomNumber == 4)
	{
		populateRoom(room, 4, 0, 2, 0, 3);
		setEnemiesConfiguration(room, 3);
		spawnEnemy(&room->enemy[0], 4, 60, 15, 0);
		spawnEnemy(&room->enemy[1], 5, 60, 15, 0);
	}else
	if (roomNumber == 5)
	{
		populateRoom(room, 5, 2, 2, 0, 3);
		setEnemiesConfiguration(room, 3);
		spawnEnemy(&room->enemy[0], 6, 60, 15, 0);
		spawnEnemy(&room->enemy[1], 7, 75, 15, 0);
	}else
	if (roomNumber == 6)
	{
		populateRoom(room, 6, 1, 1, 0, 1);
		setEnemiesConfiguration(room, 1);
		spawnEnemy(&room->enemy[0], 8, 150, 19, 0);
		spawnEnemy(&room->enemy[1], 10, 0, 0, 0);
	}
}

void describeRoom(room room, int ID)
{

	int potions = getRoomPotions(room);
	int sword = getRoomSword(room);
	int chestplate = getRoomChestplate(room);
	
	FILE *file = fopen("describeRoom.dat", "r");
		int count = 0;
		if ( file != NULL )
		{
				char line[512];
				while (fgets(line, sizeof line, file) != NULL)
				{   
						if (count == ID)
						{
							printf("\n%s\n", line);
							fclose(file);
							return 0;
						}
						else
							count++;
				}   
				fclose(file);
	
		printf("\nNella stanza: \n");
	if(potions != 0)
	{
		if(potions == 1)
			printf("1 pozione da raccogliere\n");
		else
			printf("%d pozioni da raccogliere\n", potions);
	}
	else
	{
		printf("Nessuna pozione da raccogliere\n");
	}
	if(sword != 0)
	{
		if(sword == 1)
		{
			printf("C'è una spada ricurva\n");
		}	
		else if(sword == 2)
		{
			printf("C'è un' alabarda.\n");
		}
	}	//TODO: controlla stanza 3 e stampa presenza chestplate
	describeEnemy(getEnemyID(room.enemy[0]));
	describeEnemy(getEnemyID(room.enemy[1]));
}
