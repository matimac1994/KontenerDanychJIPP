#ifndef INCLUDE_MY_HEADER_my_mess_h
#define INCLUDE_MY_HEADER_my_mess_h


#include "stdafx.h"

enum MY_MESSAGE			//OSTRZEZENIA I BLEDY
{
	ERR_ALLOC_MEM,		//b³¹d alokacji pamiêci
	ERR_OPEN_FILE,		//b³¹d otwarcia pliku	
	ERR_WRITE_FILE,		//b³¹d zapisu do pliku
	ERR_READ_FILE,		//b³¹d odczytu z pliku
	WARN_ARR_FULL,		//tablica jest wypelniona (last > ndim)
	WARN_ARR_EMPT,		//tablica jest pusta (last = 0)
	WARN_ARR_UNKN,		//niepoprawny kod dzia³ania (interfejs)
	WARN_OUT_OF_RANGE,	//indeks po za zakresem
	WARN_BAD_INPUT,		//niepoprawne dane
	TOT_NUMB_MESS		//ogólna iloœæ wiadomoœci
};

class My_mess
{
	static char *strmess[TOT_NUMB_MESS];	// Tablica tekstowa wiadomosci
public:
	void mess(enum MY_MESSAGE ms);    // Wywo³anie fukcji na ekran z odpowiednim komunikatem
};

#endif