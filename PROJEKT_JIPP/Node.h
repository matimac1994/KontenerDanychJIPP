#ifndef INC_NODE_H
#define INC_NODE_H

#include "stdafx.h"

class Node : public Mcoord
{
	int numb;			// Numer wierzcho³ka
	char str[512];		// Nazwa wierzcho³ka

public:
	Node() : Mcoord(), numb(0), str("") {}			// Konstruktor domyslny
	Node(int nb, char *st, double xx, double yy);	// Konstruktor sparametryzowany
	Node(const Node &ob);							// Konstruktor kopiuj¹cy
	void disp();									// Metoda wyœwietlaj¹ca dane

	Node & operator = (const Node &ob);		// Przeci¹¿ony operator=
	bool operator == (const Node &ob);		// Przeci¹¿ony operator==
	bool operator == (const int ob);		// Przeci¹¿ony operator==
	friend ostream & operator << (ostream &os, const Node &right);	// Przeci¹¿ony operator<< dla prostego odczytu
	friend istream & operator >> (istream &is, Node &right);		// Przeci¹¿ony operator>> dla prostego wczytywania danych
	friend ifstream & operator >> (ifstream &strm, Node & ob);		// Przeci¹¿ony operator>> dla odcztania z pliku
	friend ofstream & operator << (ofstream &strm, Node * ob);		// Przeci¹¿ony operator>> dla zapisu do pliku
};

#endif
