#include "header.h"
// Constructor
myMatrix::myMatrix() :rows(1), cols(1),pData(NULL) {}
myMatrix::myMatrix(int nRows, int nCols, int initValue) : rows(nRows), cols(nCols),
pData(NULL)
{
	allocateMemory();
	for (int i = 0; i<rows; i++)
		for (int j = 0; j<cols; j++)
			pData[i][j] = initValue;
}
myMatrix::myMatrix(int nRows, int nCols, int *data) : rows(nRows), cols(nCols),
pData(NULL)
{
	allocateMemory();
	for (int i = 0; i<rows; i++)
		for (int j = 0; j<cols; j++)
			pData[i][j] = data[i*cols + j];
}
myMatrix::myMatrix(int nRows, int nCols, int **data) : rows(nRows), cols(nCols),
pData(NULL)
{
	allocateMemory();
	for (int i = 0; i<rows; i++)
		for (int j = 0; j<cols; j++)
			pData[i][j] = data[i][j];
}
myMatrix::~myMatrix()
{
	if (pData != NULL)
		deleteMemory();
}
// Copy constructor
myMatrix::myMatrix(const myMatrix& mat) :
	rows(mat.rows), cols(mat.cols), pData(NULL)
{
	allocateMemory();
	for (int i = 0; i<rows; i++)
		for (int j = 0; j<cols; j++)
			pData[i][j] = mat.pData[i][j];
}
// Accessor functions
int myMatrix::getRows() const
{
	return rows;
}
int myMatrix::getCols() const
{
	return cols;
}
int* myMatrix::operator [](int i) const
{
	if ((i < 0) || (i >= rows))
		errorMessage("Accessing out-of-bound value of a matrix");
	return pData[i];
}
int& myMatrix::operator ()(int i, int j) const
{
	if ((i < 0) || (i >= rows) || (j < 0) || (j >= cols))
		errorMessage("Accessing out-of-bound value of a matrix");
	return pData[i][j];
}
// Overloaded binary operators
myMatrix myMatrix::operator +(const myMatrix& mat) const
{
	if ((rows != mat.rows) || (cols != mat.cols))
		errorMessage("cannot add two matrices of different size");
	myMatrix tempmat(rows, cols, 0);
	for (int i = 0; i<rows; ++i)
		for (int j = 0; j < cols; ++j)
			tempmat.pData[i][j] = this->pData[i][j] + mat.pData[i][j];
	return tempmat;
}
myMatrix myMatrix::operator -(const myMatrix& mat) const
{
	if ((rows != mat.rows) || (cols != mat.cols))
		errorMessage("cannot do subtraction between two matrices of different size");
	myMatrix tempmat(rows, cols, 0);
	for (int i = 0; i<rows; ++i)
		for (int j = 0; j < cols; ++j)
			tempmat.pData[i][j] = this->pData[i][j] - mat.pData[i][j];
	return tempmat;
}
myMatrix myMatrix::operator*(const myMatrix& mat) const
{
	if (cols != mat.rows)
		errorMessage("cannot do multiplication between the given two matrices");
	if (cols != mat.rows)
		errorMessage("cannot do multiplication between the given two matrices");
	myMatrix tempmat(rows, mat.cols, 0);
	for (int i = 0; i<rows; ++i)
		for (int j = 0; j < mat.cols; ++j)
			for (int k = 0; k < cols; ++k)
				tempmat.pData[i][j] += (this->pData[i][k] * mat.pData[k][j]);
	return tempmat;
}
myMatrix myMatrix::operator* (int value) const
{
	return value * (*this);
}
// Assignment operators
myMatrix& myMatrix::operator= (const myMatrix& mat)
{
	if (&mat == this)
		return *this;
	else
	{
		rows = mat.rows;
		cols = mat.cols;
		allocateMemory();
		for (int i = 0; i<mat.rows; ++i)
			for (int j = 0; j <mat.cols; ++j)
				this->pData[i][j] = mat[i][j];
		return *this;
	}
}
myMatrix& myMatrix::operator +=(const myMatrix& mat)
{
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			this->pData[i][j] += mat.pData[i][j];
	return *this;
}
myMatrix& myMatrix::operator -=(const myMatrix& mat)
{
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			this->pData[i][j] -= mat.pData[i][j];
	return *this;
}
myMatrix& myMatrix::operator *=(const myMatrix& mat)
{
	const myMatrix tempmat = *this;
	return *this = tempmat.operator *(mat);
}
myMatrix& myMatrix::operator *=(int value)
{
	const myMatrix tempmat = *this;
	return *this = tempmat * value;
}
// Overloading relational operators
bool myMatrix::operator ==(const myMatrix& mat) const
{
	if ((rows != mat.rows) || (cols != mat.cols))
		return false;
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			if (this->pData[i][j] != mat.pData[i][j])
				return false;
	return true;
}
bool myMatrix::operator !=(const myMatrix& mat) const
{
	return !((*this) == mat);
}
// Overloaded unary operators
myMatrix myMatrix::operator -() const // unary minus
{
	return *this * (-1);
}
// transpose the matrix
myMatrix& myMatrix::transpose()
{
	myMatrix tempmat(cols, rows, 0);
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			tempmat.pData[j][i] = this->pData[i][j];
	deleteMemory();
	rows = tempmat.rows;
	cols = tempmat.cols;
	allocateMemory();
	for (int i = 0; i < tempmat.rows; ++i)
		for (int j = 0; j < tempmat.cols; ++j)
			this->pData[i][j] = tempmat.pData[i][j];
	return *this;
}
// private functions
void myMatrix::allocateMemory()
{
	if (pData != NULL)
		deleteMemory();
	pData = new int *[rows];
	if (pData == NULL)
		errorMessage("Memory allocation error");
	pData[0] = new int[rows*cols];
	if (pData[0] == NULL)
	{
		delete[] pData;
		errorMessage("Memory allocation error");
	}
	for (int i = 1; i<rows; i++)
		pData[i] = pData[0] + i * cols;
}
void myMatrix::deleteMemory()
{
	delete[] pData[0];
	delete[] pData;
	pData = NULL;
}
void myMatrix::errorMessage(string str) const
{
	cout << "Error: " << str << endl;
	exit(1);
}
// friend functions
myMatrix operator *(int value, const myMatrix& mat)
{
	for (int i = 0; i < mat.rows; ++i)
		for (int j = 0; j < mat.cols; ++j)
			mat.pData[i][j] *= value;
	return mat;
}
ostream &operator <<(ostream &outStream, const myMatrix& mat)
{
	outStream << mat.rows << "*" << mat.cols << endl;
	for (int i = 0; i<mat.rows; i++)
	{
		for (int j = 0; j<mat.cols; j++)
			outStream << mat[i][j] << " ";
		outStream << endl;
	}
	return outStream;
}
istream &operator >> (istream &inStream, myMatrix& mat)
{
	mat.deleteMemory();
	inStream >> mat.rows >> mat.cols;
	mat.allocateMemory();
	for (int i = 0; i<mat.rows; i++)
	{
		for (int j = 0; j<mat.cols; j++)
			inStream >> mat[i][j];
	}
	return inStream;
}