#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include "Employee.h"

using namespace std;

int main()
{
	vector <Employee*> listaPracownikow;
	listaPracownikow.push_back(new HRMS("11", "jakub", "be", "CEO", "dev", 6000));
	listaPracownikow.push_back(new HRMS("12", "jacek", "ka", "VCEO", "tech", 5000));
	listaPracownikow.push_back(new HRMS("13", "zbysiu", "ce", "worker", "dev", 6000));
	listaPracownikow.push_back(new HRMS("14", "karol", "pe", "worker", "dev", 5000));
	listaPracownikow.push_back(new HRMS("15", "piwo", "paliwo", "worker", "dev", 6000));
	listaPracownikow.push_back(new HRMS("16", "jan", "wu", "worker", "tech", 5000));
	listaPracownikow.push_back(new HRMS("17", "pelc", "jot", "worker", "tech", 6000));
	listaPracownikow.push_back(new HRMS("18", "monika", "be", "worker", "rec", 5000));
	listaPracownikow.push_back(new HRMS("19", "jakis", "typ", "worker", "rec", 6000));
	listaPracownikow.push_back(new HRMS("20", "jakas", "typiara", "worker", "rec", 5000));

	unsigned int choise;

	do
	{
		cout << "Zarzadzanie zespolem: " << endl;
		cout << "Dodaj nowego pracownika - nacisnij 1." << endl;
		cout << "Wypisz liste pracownikow wraz z zarobkami - nacisnij 2." << endl;
		cout << "Zmien zarobki pracownika - nacisnij 3." << endl;

		do
		{
			cin.clear();
			cin.sync();
			cin >> choise;
		} while (!cin.good());
		cout << endl;

		switch (choise)
		{
		case 1 :
			listaPracownikow.push_back(new HRMS());
			break;
		case 2 :
		{
			for (int i = 0; i < listaPracownikow.size(); i++)
				listaPracownikow[i]->printSalaries();
			break;
		}
		case 3 :
		{
			cout << "Podaj ID pracownika i nowa pensje: ";
			double sal = 0;
			string tempId;
			cin >> tempId >> sal;

			for(int i = 0; i < listaPracownikow.size(); i++)
				listaPracownikow[i]->changeSalary(tempId, sal);
		}
		}
	}
	while (choise != 0);
	return 0;	
}