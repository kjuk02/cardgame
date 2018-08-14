#ifndef _MYMATRIX_H_
#define _MYMATRIX_H_
#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;
class myMatrix
{
public:
	// friend �Լ�
	// Constructor (������)
	myMatrix();
	myMatrix(int nRows, int nCols, int initValue);
	myMatrix(int nRows, int nCols, int *data);
	myMatrix(int nRows, int nCols, int **data);
	// Copy constructor (���� ������)
	myMatrix(const myMatrix& mat);
	// Destructor (�Ҹ���)
	~myMatrix();
	// Accessor functions (������)
	int getRows() const;
	int getCols() const;
	int* operator [](int i) const;
	int& operator ()(int i, int j) const;
	// Overloaded binary operators
	myMatrix operator +(const myMatrix& mat) const;
	myMatrix operator -(const myMatrix& mat) const;
	myMatrix operator *(const myMatrix& mat) const;
	myMatrix operator *(int value) const;
	// Overloaded assignment operators
	myMatrix& operator =(const myMatrix& mat);
	myMatrix& operator +=(const myMatrix& mat);
	myMatrix& operator -=(const myMatrix& mat);
	myMatrix& operator *=(const myMatrix& mat);
	myMatrix& operator *=(int value);
	// Overloading relational operators
	bool operator ==(const myMatrix& mat) const;
	bool operator !=(const myMatrix& mat) const;
	// Overloaded unary operators
	myMatrix operator -() const; // unary minus
								 // transpose the matrix
	myMatrix& transpose();
	friend ostream &operator <<(ostream &outStream, const myMatrix& mat);
	friend istream &operator >> (istream &inStream, myMatrix& mat);
	friend myMatrix operator *(int value, const myMatrix& mat);
private:
	int rows; // number of rows
	int cols; // number of columns
	int **pData; // pointer to actual data
	void allocateMemory(); // allocate memory for pDdata
	void deleteMemory(); // delete memory for pData
	void errorMessage(string msg) const; // print error message and exit
};
#endif 