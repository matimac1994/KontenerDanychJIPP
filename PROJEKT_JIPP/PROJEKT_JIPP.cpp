#include "stdafx.h"

int main()
{
	Interfejs interf;
	My_mess message;
	int znak = 0;

	while (interf.run)
	{
		interf.menu();
		cout << "\nTwoj wybor:\t ";
		while (!(cin >> znak) || znak < 0 || znak > 11)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("cls");
			message.mess(WARN_ARR_UNKN);
			interf.menu();
			cout << "\nTwoj wybor:\t ";
		}
		switch (znak)
		{
		case 0:
			system("cls");
			interf.push();
			break;
		case 1:
			system("cls");
			interf.pop();
			break;
		case 2:
			system("cls");
			interf.erase();
			break;
		case 3:
			system("cls");
			interf.clear_all();
			break;
		case 4:
			system("cls");
			interf.mod();
			break;
		case 5:
			system("cls");
			interf.insert();
			break;
		case 6:
			system("cls");
			interf.insert_tab();
			break;
		case 7:
			system("cls");
			interf.find();
			break;
		case 8:
			system("cls");
			interf.save();
			break;
		case 9:
			system("cls");
			interf.load();
			break;
		case 10:
			system("cls");
			interf.disp();
			break;
		case 11:
			system("cls");
			interf.finish();
			break;
		default:
			system("cls");
			interf.defaul();

			system("PAUSE");
			return 0;
		}
	}
}

