#ifndef INC_INTERFEJS_H
#define INC_INTERFEJS_H

#define MAX_INTERFEJS_CHAR 512

#include "My_vect.h"
#include "Node.h"
#include "My_mess.h"

enum MY_MENU				//MENU
{
	M_PUSH,					//dodaj obiekt
	M_POP,					//usuñ obiekt
	M_ERASE,				//usuñ konkretny obiekt
	M_CLEAR_ALL,			//wyczyœæ tablicê obiektów
	M_MOD,					//modyfikuj obiekt
	M_INSERT,				//wstaw obiekt w okreslone miejsce
	M_INSERT_TAB,			//wstaw tablicê obiektów w okreœlone miejsce
	M_FIND,					//znajdŸ wszystkie obiekty zgodne z podanym kluczem
	M_SAVE,					//zapisz dane na dysk
	M_READ,					//odczytaj dane z dysku
	M_DISP,					//wyœwietl dane na monitorze
	M_FINISH,				//zakoñcz prace z programem
	TOT_NUMB_MENU			//ogólna iloœæ pozycji w menu
};

enum MY_COMMANDS			//KOMENDY
{
	C_PUSH,					//dodaj obiekt
	C_PUSH_DONE,			//dodanie obiektu wykonane
	C_POP,					//usuñ obiekt
	C_ERASE,				//usuñ konretny obiekt
	C_CLEAR_ALL,			//wyczyœæ tablicê obiektów
	C_DISP,					//wyswietl tablice
	C_MOD,					//modyfikuj obiekt
	C_MOD_DONE,				//komunikat o zakonczonej modyfikacji
	C_INSERT,				//wstaw obiekt w okreslone miejsce
	C_INSERT_TAB,			//wstaw tablicê obiektów w okreœlone miejsce
	C_INSERT_TAB_NUMB,		//rozmiar wwstawianej tablicy
	C_INSERT_TAB_DONE,		//sukces dodawania tablicy
	C_FIND,					//znajdŸ wszystkie obiekty zgodne z podanym kluczem
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
	My_mess msg;		// B³êdy i ostrze¿enia
public:
	bool run;			// true - interfejs dzia³a, false - interfejs jest zamkniêty
	Interfejs();		// Konstruktor domyslny tworz¹cy menu tekstowe i komunikaty
	~Interfejs();		// Destruktor, dealokuje pamiêæ dla tablic strmenu i strcomm
	void menu();		// Wyœwietla menu na ekran
	void push();		// Dodaj obiekt
	void pop();			// Usuñ ostatni obiekt
	void erase();		// Usuñ konkretny obiekt
	void clear_all();	// Wyczyœæ ca³¹ tablicê
	void mod();			// Modyfikuj obiekt o podanym numerze
	void insert();		// Dodaj obiekt za podany indeks 
	void insert_tab();	// Dodaj tablicê obiektów za podany indeks
	void find();		// ZnajdŸ obiekt po numerze
	void save();		// Zapisz dane na dysk
	void load();		// Wczytaj dane z dysku	
	void disp();		// Wyœwietl tablicê na ekranie
	void finish();		// Zakoñcz dzia³anie programu
	void defaul();		// Wyœwietl komunikat o nieprawid³owej operacji
};

#endif
