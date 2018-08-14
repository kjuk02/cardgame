#pragma once
#ifndef _MYCOMPLEX_H_ 
#define _MYCOMPLEX_H_  
#include <iostream> 
using namespace std;
class myComplex {
	friend ostream &operator<<(ostream &outStream, const myComplex& number);
	friend istream &operator >> (istream &inStream, myComplex& number);
	friend myComplex operator +(int value, const myComplex& number);
	friend myComplex operator -(int value, const myComplex& number);
	friend myComplex operator *(int value, const myComplex& number);
public:
	// Constructor (������)  
	myComplex(int real = 0, int imag = 0);
	// Copy constructor (���� ������)  
	myComplex(const myComplex& number);
	// Accessor functions ( ������) 
	int getRealPart() const;
	int getImaginaryPart() const;
	// Mutator functions ( ������) 
	void setRealPart(int real);
	void setImaginaryPart(int imag);
	void set(int real, int imag);
	// Overloaded binary operators 
	myComplex operator +(const myComplex& number) const;
	myComplex operator +(int value) const;
	myComplex operator -(int value) const;
	myComplex operator -(const myComplex& number) const;
	myComplex operator *(int value) const;
	myComplex operator *(const myComplex& number) const;
	// Overloaded assignment operators 
	myComplex& operator =(const myComplex& number);
	myComplex& operator =(int value);
	myComplex& operator +=(const myComplex& number);
	myComplex& operator -=(const myComplex& number);
	myComplex& operator *=(const myComplex& number);
	// Overloading relational operators 
	bool operator ==(const myComplex& number) const;
	bool operator >(const myComplex& number) const;
	bool operator !=(const myComplex& number) const;
	bool operator >=(const myComplex& number) const;
	bool operator <(const myComplex& number) const;
	bool operator <=(const myComplex& number) const;
	// Overloaded unary operators 
	myComplex operator -();     // unary minus  
	myComplex operator ++();
	myComplex operator ++(int);
	myComplex operator --();
	myComplex operator --(int);
	myComplex operator ~();
private:
	int realPart;
	int imaginaryPart;
	int norm() const;
};
#endif 