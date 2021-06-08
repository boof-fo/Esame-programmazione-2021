#include "../headers/enemy.h"

void setEnemyID(enemy *enemy, int ID)
{
	enemy->ID = ID;
}

void setEnemyHP(enemy *enemy, int HP)
{
	enemy->HP = HP;
}

void setEnemyDamage(enemy *enemy, int damage)
{
	enemy->damage = damage;
}

void setEnemyAbility(enemy *enemy, int abilityID)
{
	enemy->specialAbility = abilityID;
}

int getEnemyID(enemy enemy)
{
	return enemy.ID;
}
int getEnemyHP(enemy enemy)
{
	return enemy.HP;
}
int getEnemyDamage(enemy enemy)
{
	return enemy.damage;
}


int attackEnemy(player *player, enemy *enemy, int damage)
{
	bool attaccato = false;
	if(enemy->HP == 0)
	{
		printf("Il nemico è già morto\n");
		return 0;
	}
	if(enemy->HP - damage > 0)
	{
		setEnemyHP(enemy, getEnemyHP(*enemy) - damage);
		attaccato = true;
	}else
	if(enemy->HP - damage <= 0)
	{
		setEnemyHP(enemy, 0);
		attaccato = true;
	}
	if(attaccato)
	{
		printf("Nemico attaccato! nuovi HP:%d\n",enemy->HP);
		attackPlayer(player, enemy->damage);
	}
	//rilevazione morte
	if (enemy->HP <= 0)
	{
		printf("nemico ucciso X_X \n");
		return enemy->ID;
	}else
	return 10;
}

void describeEnemy(int ID)
{
	if (ID == 0)
		printf("\nIl cuoco è un nemico corpulento ma privo di armatura, indossa un grembiule lercio di cibo e una retina per capelli, nonostante non ne sia rimasto neanche uno in testa e metà del cranio sia aperto in due lasciando scorgere una parte di cervello che a ogni suo passo fuoriesce e cade sul pavimento, la sua arma è un innocuo mestolo di legno capace di nuocere scarsi danni all'avversario, è molto lento negli attacchi e non possiede alcuna tecnica di combattimento.\n");
	if (ID == 1)
		printf("\nIl mozzo è il membro della ciurma più giovane, o almeno lo era! visto che ormai quello che rimane del suo corpo ha più di 200 anni, è di corporatura esile e slanciata praticamente ossa e... ossa, ormai la pelle è ridotta brandelli, è molto agile e capace di scagliare attacchi veloci a discapito della potenza d'attacco, capace di infliggere scarsi danni con la sua daga di ferro, ma comunque meglio non sottovalutarlo troppo!\n");
	if (ID == 2)
		printf("\nIl Navigatore è il nemico apparentemente meno aggressivo, una figura minuta e priva di armi, ma con la sua astuzia e sfruttando l’ambiente circostante riuscirà ad opporsi al passaggio del giocatore.\n");
	if (ID == 3)
		printf("\nil timoniere ha giurato fedeltà al suo capitano, niente l’avrebbe smosso dal suo timone durante le lunghe giornate di navigazione, e niente lo convincerà a lasciarvi passare senza prima combattere con la sua spada ricurva.\n");
	if (ID == 4)
		printf("\nIl Navigatore è il nemico apparentemente meno aggressivo, un semplice cadetto armato di una spada semplice, ma con la sua astuzia e sfruttando l’ambiente circostante riuscirà ad opporsi al passaggio del giocatore\n");
	if (ID == 5)
		printf("\nil timoniere ha giurato fedeltà al suo capitano, niente l’avrebbe smosso dal suo timone durante le lunghe giornate di navigazione, e niente lo convincerà a lasciarvi passare senza prima combattere con la sua spada ricurva.\n");
	if (ID == 6)
		printf("\nIl medico di bordo è un uomo saggio, e sarà anche anziano,ma non farlo arrabbiare perché il suo bisturi è tagliente e lui sa dove tagliere.\n");
	if (ID == 7)
		printf("\nL’artigliere capo è il braccio destro del comandante, è il membro più temibile e letale, è stato addestrato da quando era piccolo dal comandante stesso, una vera e propria macchina da guerra, dotato di due spade ricurve e di una forza sovrumana, possiede una spessa corazza di ferro difficilmente penetrabile.\n");
	if (ID == 8)
		printf("\nSi sono narrate tante leggende sul capitano Barbadura, il più temibile dei pirati, o almeno quando era in vita, di lui non è rimasto molto ma ciò non gli impedirà di impedirti di impossessarti del suo tesoro.\n“Dov’è la mia nave pirata?” è una domanda che il comandante si chiede spesso, ma in realtà non fa niente: i fantasmi non possono avere la patente nautica.\n");
}

void spawnEnemy(enemy *enemy, int ID, int HP, int damage,int abilityID)
{
	setEnemyID(enemy, ID);
	setEnemyHP(enemy, HP);
	setEnemyDamage(enemy, damage);
	setEnemyAbility(enemy, abilityID);
	describeEnemy(ID);
}
