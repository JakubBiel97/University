#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee()
{
	cout << "Wprowadzanie danych nowego pracownika..." << endl;
	cout << "Imie: ";
	cin >> name;
	cout << "Nazwisko: ";
	cin >> surname;
	cout << "ID: ";
	cin >> id;
	cout << "DepID: ";
	cin >> departmentId;
	cout << "Pozycja: ";
	cin >> position;
}


Employee::Employee(string id1, string na, string sur, string pos, string depId)
{
	id = id1;
	name = na;
	surname = sur;
	position = pos;
	departmentId = depId;
}

HRMS::HRMS() : Employee()
{
	cout << "Wpisz zarobki miesieczne: ";
	cin >> salary;
}

HRMS::HRMS(string id1, string na, string sur, string pos, string depId, double wynagr) : Employee(id1, na, sur, pos, depId)
{
	salary = wynagr;
}

void HRMS::add()
{
	listaPracownikow.push_back(new HRMS());
}

void Employee::printSalaries()
{
	cout << id << "\t" << name << "\t" << surname << "\t" << departmentId << "\t" << position;
}

void HRMS::printSalaries()
{
	Employee::printSalaries();
	cout << "\t" << salary << endl;
}

void Employee::changeSalary(string tempId, double sal)
{

}

void HRMS::changeSalary(string tempId, double sal)
{
	Employee::changeSalary(tempId, sal);
	if (tempId == id)
		salary = sal;
}