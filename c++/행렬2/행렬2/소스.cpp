#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
class myMatrix
{
private:
	int rows;
	int cols;
	int **pData;
	void allocateMemory();
	void deleteMemory();
	void errorMessage(string msg) const;
public:
	myMatrix(int nRows = 1, int nCols = 1);
	myMatrix(int nRows, int nCols, int initValue);
	myMatrix(int nRows, int nCols, int *data);
	myMatrix(int nRows, int nCols, int **data);
	myMatrix(const myMatrix& mat);
	~myMatrix();

	int getRows() const;
	int getCols() const;
	int* operator [](int i) const;
	int& operator ()(int i, int j) const;

	myMatrix operator +(const myMatrix& mat) const;
	myMatrix operator -(const myMatrix& mat) const;
	myMatrix operator *(const myMatrix& mat) const;
	myMatrix operator *(int value) const;

	myMatrix& operator =(const myMatrix& mat);
	myMatrix& operator +=(const myMatrix& mat);
	myMatrix& operator -=(const myMatrix& mat);
	myMatrix& operator *=(const myMatrix& mat);
	myMatrix& operator *=(int value);

	bool operator ==(const myMatrix& mat) const;
	bool operator !=(const myMatrix& mat) const;

	myMatrix operator -() const;
	myMatrix& transpose();

	friend ostream &operator <<(ostream &outStream, const myMatrix& mat);
	friend istream &operator >> (istream &inStream, myMatrix& mat);
	friend myMatrix operator*(int value, const myMatrix& mat);
};

myMatrix::myMatrix(int nRows, int nCols) : rows(nRows), cols(nCols), pData(NULL)
{
	allocateMemory();
}
myMatrix::myMatrix(int nRows, int nCols, int initValue) : rows(nRows), cols(nCols), pData(NULL)
{
	allocateMemory();
	for (int i = 0; i<rows; i++)
		for (int j = 0; j<cols; j++)
			pData[i][j] = initValue;
}
myMatrix::myMatrix(int nRows, int nCols, int *data) : rows(nRows), cols(nCols), pData(NULL)
{
	allocateMemory();
	for (int i = 0; i<rows; i++)
		for (int j = 0; j<cols; j++)
			pData[i][j] = data[i*cols + j];
}
myMatrix::myMatrix(int nRows, int nCols, int **data) : rows(nRows), cols(nCols), pData(NULL)
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
myMatrix::myMatrix(const myMatrix& mat) : rows(mat.rows), cols(mat.cols), pData(NULL)
{
	allocateMemory();
	for (int i = 0; i<rows; i++)
		for (int j = 0; j<cols; j++)
			pData[i][j] = mat.pData[i][j];
}
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
myMatrix myMatrix::operator *(const myMatrix& mat) const
{
	if (cols != mat.rows)
		errorMessage("cannot do multiplication between the given two matrices");
	myMatrix tempmat(rows, mat.cols, 0);
	for (int i = 0; i<rows; ++i)
		for (int j = 0; j < mat.cols; ++j)
			for (int k = 0; k < cols; ++k)
				tempmat.pData[i][j] += (this->pData[i][k] * mat.pData[k][j]);
	return tempmat;
}
myMatrix myMatrix::operator *(int value) const
{
	return value * (*this);
}
myMatrix& myMatrix::operator =(const myMatrix& mat)
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
myMatrix myMatrix::operator -() const // unary minus
{
	return *this * (-1);
}
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
	//cout << "Error: " << str << endl;
	//exit(1);
}
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

void testSimpleCase();
void testDataFromFile();
myMatrix readMatrix(ifstream& inStream);
int main()
{
	testSimpleCase();
	testDataFromFile();

	return 0;
}
void testSimpleCase()
{
	int testData1[6] = { 1, 2, 3, 4, 5, 6 };
	int testData2[6] = { 6, 5, 4, 3, 2, 1 };
	myMatrix m1(2, 2, 1);
	myMatrix m2(2, 3, testData1);
	myMatrix m3(3, 2, testData2);
	myMatrix m4(m3);
	myMatrix m5, m6(2, 3, 1), m7(3, 4, 1), m8(4, 2, 1), m9;
	cout << m1.getRows() << " " << m1.getCols() << endl;
	m4(0, 0) = 1;
	m4(0, 1) = 2;
	cout << m4[0][0] << " " << m4[0][1] << endl;
	cout << m4(1, 0) << " " << m4(1, 1) << endl;
	cout << m4[2][0] << " " << m4(2, 1) << endl;
	m3 = m3;
	cout << m3;
	m5 = m3 + m4;
	cout << m5;
	cout << (m4 == m3) << " " << (m4 != m3) << endl;
	m4 = m5 - m4;
	cout << (m4 == m3) << " " << (m4 != m3) << endl;
	m9 = m6 * m7 * m8 + m1;
	cout << m9;
	m8 = m7 = m6 = m5;
	cout << m8;
	m4 = m4 * 2;
	cout << m4;
	m4 = 2 * m4;
	cout << m4;
	m5 = m2 * m3;
	cout << m5;
	m2 *= m3;
	cout << m2;
	m2 += m1;
	cout << m2;
	m2 -= m1;
	cout << m2;
	m2 = -m1 + 2 * m2;
	cout << m2;
	m7 = m4;
	m8 = m7 * m4.transpose();
	cout << m8;
}
void testDataFromFile()
{
	ifstream inStream;
	int numTestCases;
	inStream.open("input.txt");
	if (inStream.fail())
	{
		std::cout<< "Input file opening failed.\n";
		exit(1);
	}
	inStream >> numTestCases;
	for (int i = 0; i<numTestCases; i++)
	{
		myMatrix m[4], m0;
		for (int j = 0; j<4; j++)
			m[j] = readMatrix(inStream);
		m0 = m[0] * m[1] * m[2] + m[3];
		cout << m0;
		cout << m0[0][0] << " " << m0[m0.getRows() - 1][m0.getCols() - 1] << endl;
	}
	inStream.close();
}
#define MAX_SIZE 10000 // 100 * 100
myMatrix readMatrix(ifstream& inStream)
{
	int data[MAX_SIZE];
	int row, col;
	inStream >> row >> col;
	for (int i = 0; i<row*col; i++)
		inStream >> data[i];
	return myMatrix(row, col, data);
}