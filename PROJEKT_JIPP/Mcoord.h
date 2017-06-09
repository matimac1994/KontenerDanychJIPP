#ifndef INC_MCOORD_H
#define INC_MCOORD_H

#include "stdafx.h"

class Mcoord
{
protected:
	double *pcoord;			//pcoord[0] - x, pcoord[1] - y
public:
	Mcoord() : pcoord(NULL) 
	{ 
		alloc();
		//cout << "Mcoord: KONSTRUKTOR DOMYSLNY\n"; 
	}
	Mcoord(double xx, double yy);				// Konstruktor sparametryzowany
	Mcoord(const Mcoord &ob);					// Konstruktor kopiuj¹cy
	~Mcoord();									// Destruktor
	Mcoord & operator = (const Mcoord &ob);		// Przeci¹¿ony operator przypisania
	void disp();								// Funkcja wyœwietlaj¹ca
protected:
	void alloc();								// Metoda alokuje pamiêæ 
};


#endif

