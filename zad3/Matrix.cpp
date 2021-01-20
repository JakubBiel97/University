#include "Matrix.h"
#include <algorithm>

using namespace::std;

Matrix::Matrix(unsigned x, unsigned y)				//macierz 2 wymiarowa
{
	this->mCols = x;
	this->mRows = y;

	this->matrix = new double* [mCols];
	for (int i = 0; i < mCols; ++i)
		this->matrix[i] = new double[mRows];

	for (int i = 0; i < mCols; i++)
		for (int j = 0; j < mRows; j++)
			this->matrix[i][j] = 0;				//startowa inicjacja zerami
}

double** Matrix::getMatrix()
{
	return this->matrix;
}

Matrix::Matrix(unsigned sqm)						//macierz kwadratowa
{
	this->mCols = sqm;
	this->mRows = sqm;

	this->matrix = new double* [mCols];
	for (int i = 0; i < mCols; ++i)
		this->matrix[i] = new double[mRows];

	for (int i = 0; i < mCols; i++)
		for (int j = 0; j < mRows; j++)
			this->matrix[i][j] = 0;
}

Matrix::Matrix(const Matrix& matrix)
{
	this->mRows = matrix.mRows;
	this->mCols = matrix.mCols;

	this->matrix = new double* [this->mRows];

	for (int i = 0; i < this->mRows; i++)
	{
		this->matrix[i] = new double[this->mCols];

		for (int j = 0; j < this->mCols; j++)
			this->matrix[i][j] = matrix.matrix[i][j];
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < this->rows(); i++)
		free(this->matrix[i]);

	free(this->matrix);
}

void Matrix::print() //const
{
	for (int i = 0; i < this->mRows; ++i) {
		for (int j = 0; j < this->mCols; j++) {
			string wyglad = this->matrix[i][j] < 10 ? " " : "";			//do sprawdzenia
			cout << this->matrix[i][j] << wyglad << "	";
		}
		cout << endl;
	}
}

unsigned Matrix::rows()
{
	return this->mRows;
}

unsigned Matrix::cols()
{
	return this->mCols;
}

void Matrix::set(unsigned x, unsigned y, double value)
{
	this->matrix[x][y] = value;											//sprawdzic
}

double Matrix::get(unsigned x, unsigned y)
{
	return this->matrix[x][y];
}

Matrix Matrix::add(Matrix& m2)
{
	if (m2.cols() != this->cols() || m2.rows() != this->rows())
		return m2;

	auto* newMatrix = new Matrix(this->mRows, this->mCols);

	for (unsigned i = 0; i < this->rows(); i++)
		for (unsigned j = 0; j < this->cols(); j++)
			newMatrix->set(i, j, this->get(i, j) + m2.get(i, j));

	return *newMatrix;
}

Matrix Matrix::operator+(Matrix& m2)
{
	if (m2.cols() != this->cols() || m2.rows() != this->rows())
		return m2;

	Matrix* newMatrix = new Matrix(this->mRows, this->mCols);

	for (unsigned i = 0; i < this->rows(); i++)
		for (unsigned j = 0; j < this->cols(); j++)
			newMatrix->set(i, j, this->get(i, j) + m2.get(i, j));

	return *newMatrix;
}

Matrix Matrix::subtract(Matrix& m2)
{
	if (m2.cols() != this->mCols || m2.rows() != this->mRows)
		return m2;

	Matrix* newMatrix = new Matrix(this->mRows, this->mCols);

	for (int i = 0; i < this->mRows; i++)
		for (int j = 0; j < this->mCols; j++)
			newMatrix->set(i, j, this->get(i, j) - m2.get(i, j));

	return *newMatrix;
}

Matrix Matrix::operator-(Matrix& m2)
{
	if (m2.cols() != this->mCols || m2.rows() != this->mRows)
		return m2;

	Matrix* newMatrix = new Matrix(this->mRows, this->mCols);

	for (int i = 0; i < this->mRows; i++)
		for (int j = 0; j < this->mCols; j++)
			newMatrix->set(i, j, this->get(i, j) - m2.get(i, j));

	return *newMatrix;
}

Matrix Matrix::multiply(Matrix& m2)
{
	if (m2.cols() != this->mRows || m2.rows() != this->mCols)
		return m2;

	Matrix* newMatrix = new Matrix(this->mRows, this->mCols);

	for (int i = 0; i < this->mRows; i++)
		for (int j = 0; j < this->mCols; j++)
		{
			double res = 0;

			for (int k = 0; k < this->mCols; k++)
				res += this->get(i, k) * m2.get(k, j);

			newMatrix->set(i, j, res);
		}

	return *newMatrix;
};

Matrix Matrix::operator*(Matrix& m2)
{
	if (m2.cols() != this->mRows || m2.rows() != this->mCols)
		return m2;

	Matrix* newMatrix = new Matrix(this->mRows, this->mCols);

	for (int i = 0; i < this->mRows; i++)
		for (int j = 0; j < this->mCols; j++)
		{
			double res = 0;

			for (int k = 0; k < this->mCols; k++)
				res += this->get(i, k) * m2.get(k, j);

			newMatrix->set(i, j, res);
		}

	return *newMatrix;
}

bool Matrix::operator==(Matrix& m2)
{
	if (m2.cols() != this->mCols || m2.rows() != this->mRows)
		return false;

	for (int i = 0; i < this->mRows; i++) {
		for (int j = 0; j < this->mCols; j++) {
			if (this->get(i, j) != m2.get(i, j)) {
				return false;
			}
		}
	}
	return true;
}

double* Matrix::operator[](unsigned row)
{
	return this->matrix[row];
}

//zapisanie do pliku
void Matrix::store(string name, string path)
{
	string filepath = path + name;
	ofstream f(filepath);
	for (int i = 0; i < this->rows(); i++) {
		for (int j = 0; j < this->cols(); j++) {
			string additonalSpace = this->matrix[i][j] < 10 ? " " : "";
			f << this->matrix[i][j] << additonalSpace << "|";
		}
		f << endl;
	}

	f.close();
}

Matrix::Matrix(string name)
{
	ifstream f(name);
	string line;

	getline(f, line);

	for (char i : line)
		if (i == '|')
			this->mCols++;

	f.clear();
	f.seekg(0, ios::beg);

	while (getline(f, line))
		this->mRows++;

	this->matrix = new double* [this->mRows];
	for (int i = 0; i < this->mCols; ++i)
		this->matrix[i] = new double[this->mCols];

	f.clear();
	f.seekg(0, ios::beg);

	int counter1 = 0;
	int counter2 = 0;
	while (getline(f, line))
	{
		line.erase(remove(line.begin(), line.end(), ' '), line.end());

		istringstream ss(line);
		string token;


		while (getline(ss, token, '|'))
		{
			this->matrix[counter1][counter2] = stod(token);
			counter2++;
		}
		counter2 = 0;
		counter1++;
	}

	f.close();
}

ostream& operator<< (ostream& os, Matrix& m)
{
	for (int i = 0; i < m.rows(); i++) {
		for (int j = 0; j < m.cols(); j++)
		{
			string additonalSpace = m.getMatrix()[i][j] < 10 ? " " : "";
			os << m.getMatrix()[i][j] << additonalSpace << "|";
		}
		os << endl;
	}

	return os;
}
