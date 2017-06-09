#include "stdafx.h"

Mcoord::Mcoord(double xx, double yy)
{
	//cout << "Mcoord: KONSTRUKTOR SPARAMETRYZOWANY\n";
	alloc();
	pcoord[0] = xx;
	pcoord[1] = yy;
}

Mcoord::Mcoord(const Mcoord & ob)
{
	//cout << "Mcoord: KONSTRUKTOR KOPIUJACY\n";
	alloc();
	if (ob.pcoord)
		memcpy_s(pcoord, 2 * sizeof(double), ob.pcoord, 2 * sizeof(double));
}

Mcoord::~Mcoord()
{
	//cout << "Mcoord: DESTRUKTOR\n";
	if (pcoord)
	{
		delete[] pcoord;
		pcoord = NULL;
	}		
}

Mcoord & Mcoord::operator=(const Mcoord & ob)
{
	if (this == &ob) return *this;

	if (pcoord)
	{
		delete[] pcoord;
		pcoord = NULL;
	}
	if (ob.pcoord)
	{
		alloc();
		memcpy_s(pcoord, 2 * sizeof(double), ob.pcoord, 2 * sizeof(double));
	}
	return *this;
}

void Mcoord::disp()
{
	if (pcoord)
		cout << "x: " << pcoord[0] << "\ty: " << pcoord[1] << endl;
	else
		cout << "NULL" << endl;
}

void Mcoord::alloc()
{
	try
	{
		if (!pcoord)
			pcoord = new double[2];
	}
	catch (bad_alloc)
	{
		cout << "\nBLAD ALOKACJI PAMIECI" << endl;
		system("pause");
		exit(1);
	}
}
