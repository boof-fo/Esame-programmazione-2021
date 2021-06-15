#include "../headers/string.h"

void inserstr(char stringa1[],char stringa2[])
{
	int lun = strlen(stringa2);
	int i = 0;
	while(i < lun)
	{
		stringa1[i] = stringa2[i];
		i++;
	}
}


int check(char stringa1[],char stringa2[])
{
    int i = 0;
    int lun1,lun2;
    lun1 = strlen(stringa1);
		lun2 = strlen(stringa2);
		if(lun2 != lun1)
		{
    	return false;
    }else
		{
    	while(i < lun2)
      {
		  	if (stringa1[i] == stringa2[i])
					i++;
        else 
          return false;
      }
    }
    if(i == lun2)
      return true;
    else 
      return false;
}