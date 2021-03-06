#ifndef INC_NODE_H
#define INC_NODE_H

#include "stdafx.h"

class Node : public Mcoord
{
	int numb;			// Numer wierzchołka
	char str[512];		// Nazwa wierzchołka

public:
	Node() : Mcoord(), numb(0), str("") {}			// Konstruktor domyslny
	Node(int nb, char *st, double xx, double yy);	// Konstruktor sparametryzowany
	Node(const Node &ob);							// Konstruktor kopiujący
	void disp();									// Metoda wyświetlająca dane

	Node & operator = (const Node &ob);		// Przeciążony operator=
	bool operator == (const Node &ob);		// Przeciążony operator==
	bool operator == (const int ob);		// Przeciążony operator==
	friend ostream & operator << (ostream &os, const Node &right);	// Przeciążony operator<< dla prostego odczytu
	friend istream & operator >> (istream &is, Node &right);		// Przeciążony operator>> dla prostego wczytywania danych
	friend ifstream & operator >> (ifstream &strm, Node & ob);		// Przeciążony operator>> dla odcztania z pliku
	friend ofstream & operator << (ofstream &strm, Node * ob);		// Przeciążony operator>> dla zapisu do pliku
};

#endif
