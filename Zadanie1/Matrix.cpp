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
		for (int i = 0; i < this->cols(); i++)
			free(this->matrix[i]);

		free(this->matrix);
}

void Matrix::print() //const 
{
	for (int i = 0; i < this->mCols; i++)
	{
		for (int j = 0; j < this->mRows; j++) 
		{
			cout << this->matrix[i][j] << "\t";
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
	if (this->mCols > x && this->mRows > y && x >= 0 && y >= 0)
	{
		this->matrix[x][y] = value;
	}
	else
	{
		cout << endl << "Error - wrong column or row number.(set)" << endl;
	}
}

double Matrix::get(unsigned x, unsigned y)
{
	if (this->mCols > x && this->mRows > y && x >= 0 && y >= 0)
	{
		return this->matrix[x][y];
	}
	else 
	{
		cout << endl << "Error - wrong column or row number.(get)" << endl;
		//cout << x << " " << y << endl;
		return 0;
	}
}

bool Matrix::addInplace(Matrix& m2)
{
	if (m2.cols() != this->cols() || m2.rows() != this->rows())
	{
		return false;
	}

	for (unsigned i = 0; i < this->cols(); i++)
	{
		for (unsigned j = 0; j < this->rows(); j++)
		{
			this->set(i, j, this->get(i, j) + m2.get(i, j));
		}
	}
	return true;
}

bool Matrix::subtractInplace(Matrix& m2)							
{
	if (m2.cols() != this->cols() || m2.rows() != this->rows())
	{
		return false;
	}

	for (unsigned i = 0; i < this->cols(); i++)
	{
		for (unsigned j = 0; j < this->rows(); j++)
		{
			this->set(i, j, this->get(i, j) - m2.get(i, j));
		}
	}
	return true;
}

Matrix* Matrix::add(Matrix& m2)
{
	if (m2.cols() != this->mCols || m2.rows() != this->mRows)
	{
		//cout << endl << "Error - cant add those matrixes." << endl;
		return NULL;
	}
	else
	{
		Matrix* newMatrix = new Matrix(this->mCols, this->mRows);
		for (int i = 0; i < this->mCols; i++)
			for (int j = 0; j < this->mRows; j++)
				newMatrix->set(i, j, this->get(i, j) + m2.get(i, j));
		return newMatrix;
	}
}

Matrix* Matrix::subtract(Matrix& m2)
{
	if (m2.cols() != this->mCols || m2.rows() != this->mRows)
	{
		//cout << endl << "Error - cant subtract those matrixes." << endl;
		return NULL;
	}
	else
	{
		Matrix* newMatrix = new Matrix(this->mCols, this->mRows);
		for (int i = 0; i < this->mCols; i++)
			for (int j = 0; j < this->mRows; j++)
				newMatrix->set(i, j, this->get(i, j) - m2.get(i, j));
		return newMatrix;
	}
}


Matrix* Matrix::multiply(Matrix& m2)
{
	if (m2.cols() == this->mRows && m2.rows() == this->mCols)
	{
		if (this->mCols > m2.cols())
		{
			Matrix* newMatrix = new Matrix(this->mCols, m2.rows());
			for (int i = 0; i < this->mCols; i++)
				for (int j = 0; j < m2.rows(); j++)
				{
					double res = 0;

					for (int k = 0; k < this->mRows; k++)
					{
						res += this->get(i, k) * m2.get(k, j);
					}

					newMatrix->set(i, j, res);
				}

			return newMatrix;
		}
		else 
		{
			Matrix* newMatrix = new Matrix(m2.cols(), this->mRows);
			for (int i = 0; i < m2.cols(); i++)
				for (int j = 0; j < this->mRows; j++)
				{
					double res = 0;

					for (int k = 0; k < m2.rows(); k++)
					{
						res += this->get(k, j) * m2.get(i, k);
					}

					newMatrix->set(i, j, res);
				}

			return newMatrix;
		}
	}
	else
	{
		//cout << endl << "Error - cant multiply those matrixes." << endl;
		return NULL;
	}
};

//zapisanie do pliku
void Matrix::store(string name, string path)
{
	string filepath = path + name;
	ofstream f(filepath);
	for (int i = 0; i < this->cols(); i++)
	{
		for (int j = 0; j < this->rows(); j++) 
		{
			f << this->matrix[i][j] << "\t|";
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
