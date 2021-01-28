#include <iostream>
#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

#define SIZEM 10

using namespace::std;

int main()
{
	Matrix sq_m(SIZEM);															 //Macierz kwadratowa
	Matrix m1(SIZEM, SIZEM);
	Matrix m2(SIZEM, SIZEM);

	cout << "Ilosc kolumn macierzy: " << sq_m.cols() << "." << endl;
	cout << "Ilosc wierszy: " << sq_m.rows() << "." << endl << endl;

	cout << "Funkcja set dla pierwszej macierzy: " << endl;
	for (int i = 0; i < SIZEM; i++)
	{
		for (int j = 0; j < SIZEM; j++)
			m1.set(i, j, (double)i);
	}

	//m1.set(1, 13, 600);
	//cout << endl << m1.get(13, 1) << endl;

	m1.print();																	//wypisanie stworzonej macierzy
	cout << endl;


	//to samo dla innej macierzy m2
	for (int i = 0; i < SIZEM; i++)
	{
		for (int j = 0; j < SIZEM; j++)
			m2.set(i, j, (double)2 * i);
	}

	cout << "Macierz m2" << endl;
	m2.print();

	//tworzenie macierzy z pliku (m1)
	Matrix fileMatrix("savedMatrix.txt");

	Matrix* dodawanie = m1.add(m2);
	if (dodawanie == NULL)
	{
		cout << endl << "Error - cant add those matrixes." << endl;
	}
	else
	{
		cout << endl << "Wynik dodawania m1 i m2:" << endl;
		dodawanie->print();
	}

	//roznica m2 i m1 zapisane w macierzy "odejmowanie"
	Matrix* odejmowanie = m2.subtract(m1);
	if (odejmowanie == NULL)
	{
		cout << endl << "Error - cant subtract those matrixes." << endl;
	}
	else
	{
		cout << endl << "Wynik odejmowania m2 i m1: " << endl;
		odejmowanie->print();
	}


	//mnozenie
	Matrix* mnozenie = m1.multiply(m2);
	if (mnozenie == NULL)
	{
		cout << endl << "Error - cant multiply those matrixes." << endl;
	}
	else
	{
		cout << endl << "Wynik mnozenia m1 i m2: " << endl;
		mnozenie->print();
	}

	m1.store("savedMatrix.txt", "");


	// DODATKOWE - dodawanie i odejmowanie macierzy bez tworzenia nowej macierzy(oszczednosc pamieci)
	bool resultadd = m1.addInplace(m2);
	if (resultadd)
	{
		cout << endl <<  "Wynik dodawania macierzy(dodatkowo z zapisem wyniku w m1): " << endl;
		m1.print();
	}
	else
	{
		cout << endl << "Error - cant add those matrixes.(dodatkowe)" << endl;
	}

	bool resultsub = m2.subtractInplace(m1);
	if (resultsub)
	{
		cout << endl << "Wynik odejmowania macierzy(dodatkowo z zapisem wyniku w m2): " << endl;
		m2.print();
	}
	else
	{
		cout << endl << "Error - cant add those matrixes.(dodatkowe)" << endl;
	}

}