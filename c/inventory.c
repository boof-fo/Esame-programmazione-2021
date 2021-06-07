#include"../headers/inventory.h"

void setInventoryPotions(inventory *inventory, int newValue)
{
	inventory->potions = newValue;
}

void setInventorySword(inventory *inventory, int newValue)
{
	inventory->sword = newValue;
}

void setInventoryChestplate(inventory *inventory)
{
	inventory->sword = true;
}


int getInventoryPotions(inventory inventory)
{
	return inventory.potions;
}
int getInventorySword(inventory inventory)
{
	return inventory.sword;
}
bool getInventoryChestplate(inventory inventory)
{
	return inventory.chestplate;
}



void setInventory(inventory *inventory, int potions, int swordType, int chestplate)
{
	inventory->potions = potions;
	inventory->sword = swordType;
	inventory->chestplate = chestplate;
}

void spawnInventory(inventory *inventory)
{
	setInventory(inventory, 0, 0, 0);
}


void takePotion(inventory *inventory, room *room)
{
	if (getRoomPotions(*room) > 0)
	{
		removeRoomPotion(room);
		//TODO: funzione aggiungi pozione
		setInventoryPotions(inventory, getInventoryPotions(*inventory) + 1);
		printf("\nHai raccolto una pozione curativa,Un intruglio a base di erbe medicinali sative, composto secondo un'antica ricetta degli alchimisti del tuo regno, ristabilisce i punti vitali anche se Il sapore non è il massimo.\n");
	}
	else
		printf("Non ci sono pozioni. Buona fortuna :)\n");
}
void takeSword(inventory *inventory, room *room)
{
	if (getRoomSword(*room) == 0)
	{
		printf("Non ci sono spade nella stanza. ¯\\_(ツ)_/¯\n");
		
	}
	 else if (getRoomSword(*room) == 1)
	 {
		removeRoomSword(room);
		inventory->sword = getRoomSword(*room);
		printf("\nHai raccolto una spada ricurva molto veloce ed affilata, riesce a penetrare nella carne putrefatta dei tuoi nemici con molta facilità\n");
	 }
	 else if (getRoomSword(*room) == 2)
	{
		removeRoomSword(room);
		inventory->sword = getRoomSword(*room);
		printf("\nHai raccolto un alabarda, arma da distruzione di massa per eccellenza, non troverai equipaggiamento migliore di questo, perciò fattelo bastare\n");
	}	
}
void takeChestplate(inventory *inventory, room *room)
{
	if (getRoomChestplate(*room) > 0)
	{
		removeRoomChestplate(room);
		inventory->chesteplate += 1;
		printf("\nHai raccolto una pesante armatura abbandonata da un cavaliere sconosciuto, è un pochino arrugginita ma dovrebbe riuscire a deviare qualche colpo\n");
	}
	else
		printf("Non ci sono armature nella stanza. ¯\\_(ツ)_/¯\n");
}

void removeInventoryPotion(inventory *inventory)
{
	inventory->potions = inventory->potions++;
}



void showInventory(inventory inventory)
{

	printf("\nINVENTARIO:\nPozioni: %d\n", getInventoryPotions(inventory));

	printf("Tipo di spada: ");
	if(getInventorySword(inventory) == 0)
	{
		printf("Spada semplice\nPunti danno attacco normale: 10\n");
	}else if(getInventorySword(inventory) == 1)
	{
		printf("Spada ricurva\n Punti danno attacco normale: 20\n Punti danno attacco caricato: 45\n");
	}else if(getInventorySword(inventory) == 2)
	{
		printf("Alabarda\n Punti danno attacco normale: 30\n Punti danno attacco caricato: 65\n");
	}

	printf("Armatura1: ");
	if(getInventoryChestplate(inventory) == false)
	{
		printf("Non presente\n");
	}else
	{
		printf("Presente, Protezione dal danno aumentata del 15%%\n");
	}
}