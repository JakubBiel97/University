#include <iostream>
#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace::std;

int main()
{
	Matrix sq_m(10);  //Macierz kwadratowa
	Matrix m1(10, 10);
	Matrix m2(10, 10);

	cout << "Ilosc kolumn macierzy: " << sq_m.cols() << "." << endl;
	cout << "Ilosc wierszy: " << sq_m.rows() << "." << endl << endl;

	cout << "Funkcja set dla pierwszej macierzy: " << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			m1.set(i, j, (double)i);
	}

	m1.print(); //wypisanie stworzonej macierzy
	cout << endl;

	//to samo dla innej macierzy m2
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			m2.set(i, j, (double)2 * i);
	}

	cout << "Macierz m2" << endl;
	m2.print();

	//tworzenie macierzy z pliku (m1)
	Matrix fileMatrix("savedMatrix.txt");

	//suma m1 i m2 w nowej macierzy "suma"
	Matrix suma = m1.add(m2);
	cout << "Wynik dodawania macierzy: " << endl;
	suma.print();

	//Adding with operator
	Matrix matrixSum = m1 + m2;
	cout << "Wynik dodawania macierzy (operator): " << endl;
	matrixSum.print();

	//roznica m2 i m1 zapisane w macierzy "odejmowanie"
	Matrix odejmowanie = m2.subtract(m1);
	cout << endl << "Wynik odejmowania m2 i m1: " << endl;
	odejmowanie.print();

	//Substracting with operator
	Matrix matrixSubstract = m2 - m1;
	cout << endl << "Wynik odejmowania m2 i m1 (operator): " << endl;
	matrixSubstract.print();

	//mnozenie
	Matrix mnozenie = m1.multiply(m2);
	cout << endl << "Wynik mnozenia m1 i m2: " << endl;
	mnozenie.print();

	//multiplying with operator
	Matrix matrixMultiplication = m1 * m2;
	cout << endl << "Wynik mnozenia m1 i m2: (operator)" << endl;
	matrixMultiplication.print();

	//validate if two multiplication are equal:
	bool isEqual = matrixMultiplication == mnozenie;
	cout << endl << "Both multiplication are equal? (1 == true): " << isEqual << endl;


	double* p = m1[3];

	for (unsigned i = 0; i < m1.cols(); i++) {
		cout << p[i] << " ";
	}
	cout << endl;

	ofstream f("savedMatrix2.txt");
	f << matrixMultiplication;
	f.close();

	m1.store("savedMatrix.txt", "");
}