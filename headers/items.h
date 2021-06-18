#ifndef ITEMS_H
#define ITEMS_H
//TODO: sex
int printLetter(int ID)
{
	//TODO: numero corretto
	if(ID > 100)
	{
		return 1;
	}
	FILE *file = fopen("letters.dat", "r");
	int count = 0;
	if ( file != NULL )
	{
			char line[256];
			while (fgets(line, sizeof line, file) != NULL)
			{   
					if (count == ID)
					{
						printf("%s\n", line);
						fclose(file);
						return 0;
					}
					else
						count++;
			}   
			fclose(file);
	}
	return 2;
}

#endif