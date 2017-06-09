#include "stdafx.h"

Node::Node(int nb, char * st, double xx, double yy) : Mcoord(xx,yy), numb(nb)
{
	//cout << "Node: KONSTRUKTOR SPARAMETRYZOWANY\n";
	strcpy_s(str, st);
}

Node::Node(const Node & ob) : Mcoord(ob), numb(ob.numb)
{
	//cout << "Node: KONSTRUKTOR KOPIUJACY\n";
	strcpy_s(str, ob.str);
}

void Node::disp()
{
	cout << "Nr: " << numb << "\tNazwa: " << str;
	cout << "\t";
	Mcoord::disp();
}

Node & Node::operator = (const Node & ob)
{
	Mcoord::operator=(ob);
	numb = ob.numb;								
	strcpy_s(str, strlen(ob.str) + 1, ob.str);
	return *this;								// By mo¿liwe by³o przypisanie kaskadowe np. a = b = c
}

bool Node::operator == (const Node & ob)
{
	return (pcoord[0] == ob.pcoord[0] && pcoord[1] == ob.pcoord[1] && numb == ob.numb);
}

bool Node::operator == (const int ob)
{
	return (numb == ob);
}

ostream & operator << (ostream & os, const Node & right)
{
	if (right.pcoord)
		os << "Nr: " << right.numb << "\tNazwa: " << right.str << "\tx: " << right.pcoord[0] << "\ty: " << right.pcoord[1];
	else
		os << "Nr: " << right.numb << "\tNazwa: " << right.str << "\tNULL";
	return os;
}

istream & operator >> (istream & is, Node & right)
{
	right.alloc();
	cout << "Nr:\t";
	while (!(is >> right.numb))
	{
		cout << "\nPodaj liczbe int!\n";
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Nr:\t";
	}
	cout << "Nazwa:\t";
	is >> right.str;
	cout << "x:\t";
	while (!(is >> right.pcoord[0]))
	{
		cout << "\nPodaj liczbe int!\n";
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "x:\t";
	}
	cout << "y:\t";
	while (!(is >> right.pcoord[1]))
	{
		cout << "\nPodaj liczbe int!\n";
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "y:\t";
	}
	return is;

}

ifstream & operator >> (ifstream & strm, Node & ob)
{
	strm.read(reinterpret_cast<char *>(&ob.numb), sizeof(ob.numb));
	strm.read(ob.str, sizeof(ob.str));
	strm.read(reinterpret_cast<char *>(&ob.pcoord[0]), sizeof(double));
	strm.read(reinterpret_cast<char *>(&ob.pcoord[1]), sizeof(double));
	if (strm.bad())
	{
		My_mess msg;
		msg.mess(ERR_READ_FILE);
	}
	return strm;
}

ofstream & operator << (ofstream & strm, Node * ob)
{
	strm.write(reinterpret_cast<const char *>(&ob->numb), sizeof(ob->numb));
	strm.write(ob->str, sizeof(ob->str));
	strm.write(reinterpret_cast<const char *>(&ob->pcoord[0]), sizeof(double));
	strm.write(reinterpret_cast<const char *>(&ob->pcoord[1]), sizeof(double));
	if (strm.bad())
	{
		My_mess msg;
		msg.mess(ERR_WRITE_FILE);
	}
	return strm;
}
