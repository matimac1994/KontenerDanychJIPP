#ifndef INC_NODE_H
#define INC_NODE_H

#include "stdafx.h"

class Node : public Mcoord
{
	int numb;			// Numer wierzcho�ka
	char str[512];		// Nazwa wierzcho�ka

public:
	Node() : Mcoord(), numb(0), str("") {}			// Konstruktor domyslny
	Node(int nb, char *st, double xx, double yy);	// Konstruktor sparametryzowany
	Node(const Node &ob);							// Konstruktor kopiuj�cy
	void disp();									// Metoda wy�wietlaj�ca dane

	Node & operator = (const Node &ob);		// Przeci��ony operator=
	bool operator == (const Node &ob);		// Przeci��ony operator==
	bool operator == (const int ob);		// Przeci��ony operator==
	friend ostream & operator << (ostream &os, const Node &right);	// Przeci��ony operator<< dla prostego odczytu
	friend istream & operator >> (istream &is, Node &right);		// Przeci��ony operator>> dla prostego wczytywania danych
	friend ifstream & operator >> (ifstream &strm, Node & ob);		// Przeci��ony operator>> dla odcztania z pliku
	friend ofstream & operator << (ofstream &strm, Node * ob);		// Przeci��ony operator>> dla zapisu do pliku
};

#endif
