#pragma once
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <cmath>
#include <tuple>

using namespace::std;

class Matrix
{

private:
	unsigned mRows = 0;
	unsigned mCols = 0;
	double** matrix;

public:
	Matrix(unsigned);
	Matrix(unsigned, unsigned);
	Matrix(string);
	Matrix(const Matrix& matrix);
	~Matrix();

	void print();//const
	unsigned rows();
	unsigned cols();
	void set(unsigned, unsigned, double);
	double get(unsigned, unsigned);
	//dodatkowe boole
	bool addInplace(Matrix&);
	bool subtractInplace(Matrix&);
	//
	Matrix* add(Matrix&);
	Matrix* subtract(Matrix&);
	Matrix* multiply(Matrix&);
	void store(string name, string path);

};

