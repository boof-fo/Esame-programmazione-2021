#ifndef ENEMY_H
#define ENEMY_H

//struttura di un nemico
typedef struct{
	//tipo di nemico
	int ID;
	//punti vita del nemico
	int HP;
	//punti danno del nemico
	int damage;
	//TODO: medico si cura da solo, 
	int specialAbility;
	//descrizione nemico
	char description[120];
}enemy;

void setEnemyHP(enemy *enemy, int HP);
void setEnemyDamage(enemy *enemy, int damage);
void setEnemyAbility(enemy *enemy, int abilityID);
void setEnemyID(enemy *enemy, int ID);

//crea il nemico
void spawnEnemy(enemy *enemy, int ID, int HP, int damage,int abilityID);


#endif