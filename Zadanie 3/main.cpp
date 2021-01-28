#include <iostream>
#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

#define SIZEM 10

using namespace::std;

int main()
{
	Matrix sq_m(SIZEM);  //Macierz kwadratowa
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

	m1.print(); //wypisanie stworzonej macierzy
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

	//suma m1 i m2 w nowej macierzy "suma"
	Matrix* matrixAdd = m1.add(m2);
	if (matrixAdd == NULL)
	{
		cout << endl << "Error - cant add those matrixes." << endl;
	}
	else
	{
		cout << endl << "Wynik dodawania m1 i m2:" << endl;
		matrixAdd->print();
	}

	//Adding with operator
	Matrix* matrixSum = m1 + m2;
	if (matrixSum == NULL)
	{
		cout << endl << "Error - cant add those matrixes(operatorowo)." << endl;
	}
	else
	{
		cout << endl << "Wynik dodawania m1 i m2(operatorowo):" << endl;
		matrixSum->print();
	}

	//roznica m2 i m1 zapisane w macierzy "odejmowanie"
	Matrix* matrixSub = m2.subtract(m1);
	if (matrixSub == NULL)
	{
		cout << endl << "Error - cant subtract those matrixes." << endl;
	}
	else
	{
		cout << endl << "Wynik odejmowania m2 i m1: " << endl;
		matrixSub->print();
	}

	//Substracting with operator
	Matrix* matrixSubstract = m2 - m1;
	if (matrixSubstract == NULL)
	{
		cout << endl << "Error - cant subtract those matrixes(operatorowo)." << endl;
	}
	else
	{
		cout << endl << "Wynik odejmowania m2 i m1 (operator): " << endl;
		matrixSubstract->print();
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


	//multiplying with operator
	Matrix* matrixMultiplication = m1 * m2;
	if (matrixMultiplication == NULL)
	{
		cout << endl << "Error - cant multiply those matrixes(operatorowo)." << endl;
	}
	else
	{
		cout << endl << "Wynik mnozenia m1 i m2(Operatorowo): " << endl;
		matrixMultiplication->print();
	}

	m1.store("savedMatrix.txt", "");


	//validate if two multiplication are equal:
	if (mnozenie == NULL || matrixMultiplication == NULL)
	{
		cout << endl << "Error - Are both matrixes the same?" << endl;
	}
	else
	{
		Matrix multiMat1 = *mnozenie;
		Matrix multiMat2 = *matrixMultiplication;
		cout << "Result of matrix comparision(1 == Matrixes are equal): " << (int)(multiMat1 == multiMat2) << endl;

		//prostsza lecz mniej poprawna forma
		/*bool isEqual = *matrixMultiplication == *mnozenie;										
		cout << endl << "Both multiplication are equal? (1 == true): " << isEqual << endl << endl;*/
	}

	double* p = m1[3];
	for (unsigned i = 0; i < m1.cols(); i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;

	if (matrixMultiplication == NULL)
	{
		cout << endl << "There is no matrix to save" << endl;
	}
	else
	{
		ofstream f("savedMatrix2.txt");
		f << *matrixMultiplication;
		f.close();
	}

}