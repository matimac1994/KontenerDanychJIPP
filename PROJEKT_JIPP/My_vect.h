#ifndef INC_MY_VECT_H
#define INC_MY_VECT_H

#include "stdafx.h"
#include "My_mess.h"

template <typename T> class My_vect
{
	T *dat;											// WskaŸnik do tablicy typu ogólnego T
	size_t ndim;									// Iloœæ elementów, na jak¹ zosta³a zaalokowana pamiêæ dla tablicy
	size_t last;									// Indeks który wskazuje na pierwszy wolny element tablicy
	My_mess msg;									// Do obslugi bledow i ostrzezen

public:
	My_vect(size_t dim);							// Alokuje pamiec dla tablicy dat na dim elementow
	My_vect();										// Alokuje pamiec na 1 element i ustawia last = 0
	My_vect(const My_vect<T> &ob);					// Konstruktor kopiuj¹cy
	~My_vect();										// Zwalnia pamiêæ

	T *get_begin() { return dat; }					// Zwraca wskaŸnik do dat[0]
	T *get_end() { return & dat[last]; }			// Zwraca wskaŸnik na pierwszy wolny element

	void init(size_t dim);
	void push(const T & ob);						// Dodaje obiekt typu T w pierwsz¹ woln¹ pozycjê i zwiêksza last o jedynkê
	T *pop();										// Dekrementuje last i zwraca ostatni element tablicy
	void insert(const T & ob, size_t ind);			// Wstawia element ob w tablicê dat po elemencia dat[ind]
	void insert(const T & tab_ob, size_t ind, size_t numb);			// Wstawia tablicê elementów tab_ob w tablicê dat po elemencie dat[ind], gdzie numb - iloœæ elementów w tablicy tab_ob
	void erase(const T & ob);		// Usuwa element *ob z tablicy dat o przesuwa elementy tablicy tak, aby po usuniêciu elementy by³y umieszczone w sposób ci¹g³y (metoda "pakuje" tablicê)
	void clear_all();				// Czyœci tablicê ze wszystkich elementów
	void disp();
	bool empty() { return (last <= 0); }			//0 jestli pusta 1 jesli cos jest
	size_t get_last() { return last; }				//Zwraca last
	T & operator[](size_t i);
	void save();									//Zapisuje dane do pliku binarnego
	void load();									//Odczytuje dane z pliku binarnego
private:
	void realloc();		// Jeœli last >= ndim - zwiêksza ndim i realokuje pamiêæ
};

// Alokuje pamiec dla tablicy dat na dim elementow
template<typename T>
My_vect<T>::My_vect(size_t dim)
{
	try
	{
		if (!dat)
		{
			ndim = dim;
			dat = new T[ndim];
			last = 0;
		}
			
	}
	catch (bad_alloc)
	{
		msg.mess(ERR_ALLOC_MEM);
		system("pause");
		exit(1);
	}
}

// Alokuje pamiec na 1 element i ustawia last = 0
template<typename T>
My_vect<T>::My_vect()
{
	try
	{
		if (!dat)
		{
			dat = new T[1];
			ndim = 1;
			last = 0;
		}

	}
	catch (bad_alloc)
	{
		msg.mess(ERR_ALLOC_MEM);
		system("pause");
		exit(1);
	}
}

template<typename T>
My_vect<T>::My_vect(const My_vect<T>& ob)
{
	if (ob.dat != NULL)
	{
		try
		{
			if (!dat)
			{
				ndim = ob.ndim;
				dat = new T[ndim];
				last = ob.last;
			}
		}
		catch (bad_alloc)
		{
			msg.mess(ERR_ALLOC_MEM);
			system("pause");
			exit(1);
		}
		for (size_t i = 0; i < last; ++i)
			dat[i] = ob.dat[i];
	}	
}

// Zwalnia pamiêæ
template<typename T>
My_vect<T>::~My_vect()
{
	if (dat)
	{
		delete[] dat;
		last = 0;
	}
	dat = NULL;
}

template<typename T>
void My_vect<T>::init(size_t dim)
{
	try
	{
		if (!dat)
		{
			ndim = dim;
			dat = new T[ndim];
			last = 0;
		}

	}
	catch (bad_alloc)
	{
		msg.mess(ERR_ALLOC_MEM);
		system("pause");
		exit(1);
	}
}

// Dodaje obiekt typu T w pierwsz¹ woln¹ pozycjê i zwiêksza last o jedynkê
template<typename T>
void My_vect<T>::push(const T & ob)
{
	if (last >= ndim)
		realloc();
	dat[last++] = ob;
}

// Dekrementuje last i zwraca ostatni element tablicy
template<typename T>
T * My_vect<T>::pop()
{
	if (last > 0)
		return &dat[--last];
	else 
		return NULL;
}

// Wstawia element ob w tablicê dat po elemencia dat[ind]
template<typename T>
void My_vect<T>::insert(const T & ob, size_t ind)
{
	if (ind >= last)
	{
		msg.mess(WARN_OUT_OF_RANGE);
		return;
	}		
	if (last+1 >= ndim)
		realloc();
	for (size_t j = last; j > ind+1; j--)
	{
		dat[j] = dat[j - 1];
	}
	last++;
	dat[ind + 1] = ob;
}

// Wstawia tablicê elementów tab_ob w tablicê dat po elemencie dat[ind], gdzie numb - iloœæ elementów w tablicy tab_ob
template<typename T>
void My_vect<T>::insert(const T & tab_ob, size_t ind, size_t numb)
{
	if (ind >= last)
	{
		msg.mess(WARN_OUT_OF_RANGE);
		return;
	}
	while ((last+numb) >= ndim) 
		realloc();
	size_t i;
	for (i = (last - 1); i > ind; i--)
		dat[i + numb] = dat[i];
	for (i = 0; i < numb; i++)
		dat[i + ind + 1] = (&tab_ob)[i];
	last += numb;
}

// Usuwa element *ob z tablicy dat o przesuwa elementy tablicy tak, aby po usuniêciu elementy by³y umieszczone w sposób ci¹g³y (metoda "pakuje" tablicê)
template<typename T>
void My_vect<T>::erase(const T & ob)
{
	for (size_t i = 0; i < last; ++i)
	{
		if (dat[i] == ob)
		{
			for (size_t j = i; j < last-1; ++j)
			{
				dat[j] = dat[j + 1];
			}
			--last;
			cout << "\nUsunieto obiekt.\n";
			return;
		}
	}
}

template<typename T>
void My_vect<T>::clear_all()
{
	if (last)
	{
		last = 0;
		ndim = 1;
	}
}

template<typename T>
void My_vect<T>::disp()
{
	for (size_t i = 0; i < last; ++i)
		cout << dat[i] << "\n";
}

template<typename T>
T & My_vect<T>::operator[](size_t i)
{
	if (i<0 || i >= last)
	{
		msg.mess(WARN_OUT_OF_RANGE);
		system("pause");
		exit(1);
	}
	else return dat[i];
}

template<typename T>
void My_vect<T>::save()
{
	ofstream out;
	size_t i;
	out.open("file.dat", ios::binary);
	if (!out.is_open())
		msg.mess(ERR_OPEN_FILE);
	out.seekp(0);

	for (i = 0; i < last; ++i)
	{
		out << &dat[i];
		if (out.eof())
			break;
	}
	out.close();		
}

template<typename T>
void My_vect<T>::load()
{
	ifstream in;
	in.open("file.dat", ios::binary);
	if (!in.is_open())
		msg.mess(ERR_OPEN_FILE);
	in.seekg(0);
	T tmp;
	last = 0;
	while (1)
	{
		in >> tmp;
		if (in.eof())
			break;
		push(tmp);
	}
	in.close();
}

// Jeœli last >= ndim - zwiêksza ndim i realokuje pamiêæ
template<typename T>
inline void My_vect<T>::realloc()
{
	T *tmp;
	try
	{
		tmp = new T[2 * ndim];
	}
	catch (bad_alloc)
	{
		msg.mess(WARN_OUT_OF_RANGE);
		system("pause");
		exit(1);
	}
	for (size_t i = 0; i < ndim; ++i)
	{
		tmp[i] = dat[i];
	}
	delete[] dat;
	dat = tmp;
	ndim *= 2;
}

template<typename T, typename Key>
T * Find(const T * p_begin, const T * p_end, const Key & k)
{
	Node *p_tmp = const_cast<T *>(p_begin);
	while (1)
	{
		if (p_tmp >= p_end)
			return NULL;
		if (*p_tmp == k)
			return p_tmp;
		p_tmp++;
	}
}


#endif