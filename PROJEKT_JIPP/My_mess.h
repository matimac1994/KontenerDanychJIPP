#ifndef INCLUDE_MY_HEADER_my_mess_h
#define INCLUDE_MY_HEADER_my_mess_h


#include "stdafx.h"

enum MY_MESSAGE			//OSTRZEZENIA I BLEDY
{
	ERR_ALLOC_MEM,		//b��d alokacji pami�ci
	ERR_OPEN_FILE,		//b��d otwarcia pliku	
	ERR_WRITE_FILE,		//b��d zapisu do pliku
	ERR_READ_FILE,		//b��d odczytu z pliku
	WARN_ARR_FULL,		//tablica jest wypelniona (last > ndim)
	WARN_ARR_EMPT,		//tablica jest pusta (last = 0)
	WARN_ARR_UNKN,		//niepoprawny kod dzia�ania (interfejs)
	WARN_OUT_OF_RANGE,	//indeks po za zakresem
	WARN_BAD_INPUT,		//niepoprawne dane
	TOT_NUMB_MESS		//og�lna ilo�� wiadomo�ci
};

class My_mess
{
	static char *strmess[TOT_NUMB_MESS];	// Tablica tekstowa wiadomosci
public:
	void mess(enum MY_MESSAGE ms);    // Wywo�anie fukcji na ekran z odpowiednim komunikatem
};

#endif