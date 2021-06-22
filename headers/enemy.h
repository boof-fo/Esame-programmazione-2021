#ifndef ENEMY_H
#define ENEMY_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/player.h"
#include "../headers/string.h"
#include "../headers/files.h"

//struttura di un nemico
typedef struct
{
	//tipo di nemico
	int ID;
	//punti vita del nemico
	int HP;
	//nome del nemico
	char name[20];
	//punti danno del nemico
	int damage;
	//abilità speciale del nemico 
	int special_ability;
}enemy;

//imposta/ritorna codice identificativo del nemico
void setEnemyID(enemy *enemy, int enemy_ID);
int getEnemyID(enemy enemy);
//imposta/ritorna i punti HP del nemico
void setEnemyHP(enemy *enemy, int HP);
int getEnemyHP(enemy enemy);
//imposta/ritorna i punti danno del nemico
void setEnemyDamage(enemy *enemy, int damage);
int getEnemyDamage(enemy enemy);
//imposta/ritorna abilità speciale
void setEnemyAbility(enemy *enemy, int ability_ID);
int getEnemyAbility(enemy enemy);

//crea il nemico impostando le sue statistiche
void spawnEnemy(enemy *enemy, int enemy_ID, int HP, int damage,int ability_ID);

//TODO: gestire gli errori quando viene chiamata
int describeEnemy(int enemy_ID);

//attiva l'abilità speciale del nemico
int useEnemyAbility(enemy *enemy, player *player);

//stampa le frasi dei nemici (viene usato durante il combattimento)
void enemyLines();

#endif