#include "stdafx.h"
#include "Interfejs.h"

Interfejs::Interfejs()
{
	run = true;

	try
	{
		strmenu = new string[TOT_NUMB_MENU];
	}
	catch (bad_alloc)
	{
		cout << "\nBLAD ALOKACJI strmenu\n";
		system("pause");
		exit(1);
	}
	strmenu[M_PUSH] = "\n0  - Dodaj obiekt.\n";
	strmenu[M_POP] = "1  - Usun obiekt.\n";
	strmenu[M_ERASE] = "2  - Usun konkretny obiekt.\n";
	strmenu[M_CLEAR_ALL] = "3  - Wyczysc tablice obiektow.\n";
	strmenu[M_MOD] = "4  - Modyfikuj obiekt.\n";
	strmenu[M_INSERT] = "5  - Wstaw obiekt w okreslone miejsce.\n";
	strmenu[M_INSERT_TAB] = "6  - Wstaw tablice obiektow w okreslone miejsce.\n";
	strmenu[M_FIND] = "7  - Znajdz wszystkie obiekty zgodne z podanym kluczem.\n";
	strmenu[M_SAVE] = "8  - Zapisz dane na dysk.\n";
	strmenu[M_READ] = "9  - Odczytaj dane z dysku.\n";
	strmenu[M_DISP] = "10 - Wyswietl dane na monitorze.\n";
	strmenu[M_FINISH] = "11 - Zakoncz prace z programem.\n";
	try
	{
		strcomm = new string[TOT_NUMB_COMM];
	}
	catch (bad_alloc)
	{
		cout << "\nBLAD ALOKACJI strcomm\n";
		system("pause");
		exit(1);
	}
	strcomm[C_PUSH] = "\nPodaj nr. wierzcholka, nazwe, zmienna X i Y.\n";
	strcomm[C_PUSH_DONE] = "\nDodano obiekt.\n";
	strcomm[C_POP] = "\nUsuniento obiekt.\n";
	strcomm[C_ERASE] = "\nPodaj dane usuwanego obiektu.\n";
	strcomm[C_CLEAR_ALL] = "\nWyczyszczono tablice obiektow.\n";
	strcomm[C_DISP] = "\nZawartosc tablicy.\n";
	strcomm[C_MOD] = "\nPodaj modyfikowany obiekt.\n";
	strcomm[C_MOD_DONE] = "\nObiekt zostal zmodyfikowany.\n";
	strcomm[C_INSERT] = "\nPodaj indeks za ktory ma byc wstawiony obiekt.\n";
	strcomm[C_INSERT_TAB] = "\nPodaj indeks za ktory ma byc wstawiona tablica obiektow.\n";
	strcomm[C_INSERT_TAB_NUMB] = "\nPodaj ilosc elementow wstawianej tablicy\n";
	strcomm[C_INSERT_TAB_DONE] = "\nDodano tablice obiektow\n";
	strcomm[C_FIND] = "\nPodaj klucz do wyszukiwania obiektow.\n";
	strcomm[C_FOUND] = "\nZnalezione obiekty:\n";
	strcomm[C_SAVE] = "\nZapisano dane na dysku.\n";
	strcomm[C_READ] = "\nOdczytano dane z dysku.\n";

}

Interfejs::~Interfejs()
{
	if (!strmenu)
		delete[] strmenu;
	strmenu = NULL;
	if (!strcomm)
		delete[] strcomm;
	strcomm = NULL;
}

void Interfejs::menu()
{
	int i;
	for (i = 0; i<TOT_NUMB_MENU; i++)
	{
		cout << strmenu[i];
	}
}

void Interfejs::push()
{
	Node ob;
	cout << strcomm[C_PUSH];
	cin >> ob;
	vect.push(ob);
	cout << strcomm[C_PUSH_DONE];
}

void Interfejs::pop()
{
	if (vect.empty())
	{
		cout << endl;
		msg.mess(WARN_ARR_EMPT);
	}
	else
	{
		Node *ptr = NULL;
		ptr = vect.pop();
		cout << strcomm[C_POP];
	}	
}

void Interfejs::erase()
{
	if (vect.empty())
	{
		cout << endl;
		msg.mess(WARN_ARR_EMPT);
		return;
	}
	cout << strcomm[C_ERASE];
	Node tmp_ob;
	cin >> tmp_ob;
	vect.erase(tmp_ob);
}

void Interfejs::clear_all()
{
	if (vect.empty())
	{
		cout << endl;
		msg.mess(WARN_ARR_EMPT);
	}
	else
	{
		vect.clear_all();
		cout << strcomm[C_CLEAR_ALL];
	}	
}

void Interfejs::mod()
{
	if (vect.empty())
	{
		cout << endl;
		msg.mess(WARN_ARR_EMPT);
		return;
	}
	size_t n;
	cout << strcomm[C_MOD];
	cin >> n;
	if (n < vect.get_last())
	{
		cin >> vect[n];
		cout << strcomm[C_MOD_DONE];
	}
	else
	{
		cout << endl;
		msg.mess(WARN_OUT_OF_RANGE);
	}
}

void Interfejs::insert()
{
	if (vect.empty())
	{
		cout << endl;
		msg.mess(WARN_ARR_EMPT);
		return;
	}
	
	cout << strcomm[C_INSERT];
	size_t ind;
	cin >> ind;
	if (ind < 0 || ind >= vect.get_last())
	{
		msg.mess(WARN_OUT_OF_RANGE);
	}
	else
	{
		cout << strcomm[C_PUSH];
		cin >> obiekt;
		vect.insert(obiekt, ind);
		cout << strcomm[C_PUSH_DONE];
	}
}

void Interfejs::insert_tab()
{
	if (vect.empty())
	{
		cout << endl;
		msg.mess(WARN_ARR_EMPT);
		return;
	}
	size_t numb;
	size_t ind;
	Node *ptr;
	cout << strcomm[C_INSERT_TAB];
	cin >> ind;
	if (ind < 0 || ind >= vect.get_last())
	{
		msg.mess(WARN_OUT_OF_RANGE);
		return;
	}
	cout << strcomm[C_INSERT_TAB_NUMB];
	cin >> numb;
	if (numb <= 0)
	{
		msg.mess(WARN_BAD_INPUT);
		return;
	}
	
	try
	{
		ptr = new Node[numb];
	}
	catch (bad_alloc)
	{
		msg.mess(ERR_ALLOC_MEM);
		return;
	}
	size_t i;
	for (i = 0; i < numb; ++i)
	{
		cout << "\nPodaj element nr: " << i << endl;
		cin >> ptr[i];
	}
	vect.insert(*ptr, ind, numb);
	cout << strcomm[C_INSERT_TAB_DONE];

	if (ptr)
		delete[] ptr;
	ptr = NULL;
}

void Interfejs::find()
{
	if (vect.empty())
	{
		cout << endl;
		msg.mess(WARN_ARR_EMPT);
		return;
	}
	int klucz;
	cout << strcomm[C_FIND];
	while (!(cin >> klucz))
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		msg.mess(WARN_BAD_INPUT);
	}
	//system("cls");
	Node *tmp_ptr = vect.get_begin();
	cout << strcomm[C_FOUND];
	while (tmp_ptr)
	{
		tmp_ptr = ::Find(tmp_ptr, vect.get_end(), klucz);
		if (tmp_ptr)
		{
			cout << *tmp_ptr << endl;
			tmp_ptr++;
		}
	}
	cout << endl;
}

void Interfejs::save()
{
	if (vect.empty())
	{
		cout << endl;
		msg.mess(WARN_ARR_EMPT);
		return;
	}
	vect.save();
	cout << strcomm[C_SAVE];
}

void Interfejs::load()
{
	vect.load();
	cout << strcomm[C_READ];
}

void Interfejs::disp()
{
	if (vect.empty())
	{
		cout << endl;
		msg.mess(WARN_ARR_EMPT);
	}
	else
	{
		cout << strcomm[C_DISP] << endl;
		vect.disp();
	}
	
}

void Interfejs::finish()
{
	run = false;
}

void Interfejs::defaul()
{
	msg.mess(WARN_ARR_UNKN);
}
