#ifndef INC_INTERFEJS_H
#define INC_INTERFEJS_H

#define MAX_INTERFEJS_CHAR 512

#include "My_vect.h"
#include "Node.h"
#include "My_mess.h"

enum MY_MENU				//MENU
{
	M_PUSH,					//dodaj obiekt
	M_POP,					//usu� obiekt
	M_ERASE,				//usu� konkretny obiekt
	M_CLEAR_ALL,			//wyczy�� tablic� obiekt�w
	M_MOD,					//modyfikuj obiekt
	M_INSERT,				//wstaw obiekt w okreslone miejsce
	M_INSERT_TAB,			//wstaw tablic� obiekt�w w okre�lone miejsce
	M_FIND,					//znajd� wszystkie obiekty zgodne z podanym kluczem
	M_SAVE,					//zapisz dane na dysk
	M_READ,					//odczytaj dane z dysku
	M_DISP,					//wy�wietl dane na monitorze
	M_FINISH,				//zako�cz prace z programem
	TOT_NUMB_MENU			//og�lna ilo�� pozycji w menu
};

enum MY_COMMANDS			//KOMENDY
{
	C_PUSH,					//dodaj obiekt
	C_PUSH_DONE,			//dodanie obiektu wykonane
	C_POP,					//usu� obiekt
	C_ERASE,				//usu� konretny obiekt
	C_CLEAR_ALL,			//wyczy�� tablic� obiekt�w
	C_DISP,					//wyswietl tablice
	C_MOD,					//modyfikuj obiekt
	C_MOD_DONE,				//komunikat o zakonczonej modyfikacji
	C_INSERT,				//wstaw obiekt w okreslone miejsce
	C_INSERT_TAB,			//wstaw tablic� obiekt�w w okre�lone miejsce
	C_INSERT_TAB_NUMB,		//rozmiar wwstawianej tablicy
	C_INSERT_TAB_DONE,		//sukces dodawania tablicy
	C_FIND,					//znajd� wszystkie obiekty zgodne z podanym kluczem
	C_FOUND,				//znaleziono obiekty
	C_SAVE,					//zapisz dane na dysk
	C_READ,					//odczytaj dane z dysku
	TOT_NUMB_COMM
};

class Interfejs
{
private:
	My_vect<Node> vect;	// Obiekt typu My_vect
	Node obiekt;		// Obiekt typu Node
	string *strmenu;	// Tablica tekstowa menu
	string *strcomm;	// Tablica tekstowa komend
	My_mess msg;		// B��dy i ostrze�enia
public:
	bool run;			// true - interfejs dzia�a, false - interfejs jest zamkni�ty
	Interfejs();		// Konstruktor domyslny tworz�cy menu tekstowe i komunikaty
	~Interfejs();		// Destruktor, dealokuje pami�� dla tablic strmenu i strcomm
	void menu();		// Wy�wietla menu na ekran
	void push();		// Dodaj obiekt
	void pop();			// Usu� ostatni obiekt
	void erase();		// Usu� konkretny obiekt
	void clear_all();	// Wyczy�� ca�� tablic�
	void mod();			// Modyfikuj obiekt o podanym numerze
	void insert();		// Dodaj obiekt za podany indeks 
	void insert_tab();	// Dodaj tablic� obiekt�w za podany indeks
	void find();		// Znajd� obiekt po numerze
	void save();		// Zapisz dane na dysk
	void load();		// Wczytaj dane z dysku	
	void disp();		// Wy�wietl tablic� na ekranie
	void finish();		// Zako�cz dzia�anie programu
	void defaul();		// Wy�wietl komunikat o nieprawid�owej operacji
};

#endif
