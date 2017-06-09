#include "stdafx.h"
#include "My_mess.h"

char *My_mess::strmess[] =
{
	"E  Blad z alokacja pamieci",				//ERR_ALLOC_MEM
	"E  Blad otwarcia pliku",					//ERR_OPEN_FILE
	"E  Blad zapisu pliku",						//ERR_WRITE_FILE
	"E  Blad odczytu pliku",					//ERR_READ_FILE
	"W  Tablica jest pelna",					//WARN_ARR_FULL
	"W  Tablica jest pusta",					//WARN_ARR_EMPT
	"W  Niepoprawny kod operacji",				//WARN_ARR_UNKN
	"W  Indeks jest po za zakresem tablicy",	//WARN_OUT_OF_RANGE
	"W  Niepoprawne dane"						//WARN_BAD_INPUT	
};

void My_mess::mess(enum MY_MESSAGE ms)
{
	if (strmess[ms][0] == 'E')
	{
		cout << "ERROR: " << &strmess[ms][1] << endl;
		system("pause");
		exit(1);
	}
	else if (strmess[ms][0] == 'W')
	{
		cout << "WARNING: " << &strmess[ms][1] << endl;
	}
}