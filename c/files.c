#include "../headers/files.h"

void readFile(char *filename)
{
  int c;
	FILE *file;
    file = fopen(filename, "r");
    if (file)
    {
      while ((c = getc(file)) != EOF)
        putchar(c);
        fclose(file);
    }
	printf("\n");
}

void readFileLine(char *filename, int lineNum)
{
	FILE *file = fopen(filename, "r");
	int count = 0;
	if ( file != NULL )
	{
		char line[512];
		while (fgets(line, sizeof line, file) != NULL)
		{   
			if (count == lineNum)
			{
				printf("%s\n", line);
				fclose(file);
				return;
			}
			else
				count++;
		}   
		fclose(file);
	}
}

void readFileRandomLine(char *filename)
{
	srand(time(NULL));
	int selection = rand() % 10 + 1;
	FILE *file = fopen(filename, "r");
	int count = 0;
	if ( file != NULL )
	{
		char line[512];
		while (fgets(line, sizeof line, file) != NULL)
		{
			if (count == selection)
			{
				printf("\n%s\n", line);
				fclose(file);
				return;
			}
			else
				count++;
		}
		fclose(file);
	}
	return;
}