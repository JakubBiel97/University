#pragma once
#ifndef PRACOWNIK_H
#define PRACOWNIK_H
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class Employee
{
	
public:
	string  id, departmentId, name, surname, position;

	Employee();
	Employee(string id1, string na, string sur, string pos, string depId);
	~Employee() {};

	void add();
	virtual void printSalaries() = 0;
	virtual void changeSalary(string tempId, double sal) = 0;

};


class HRMS : public Employee
{
	vector <Employee*> listaPracownikow;
	double salary;

public:
	HRMS();
	HRMS(string id1, string na, string sur, string pos, string depId, double wynagr);

	void add();
	void printSalaries();
	void changeSalary(string tempId, double sal);

	~HRMS() {};
};

#endif