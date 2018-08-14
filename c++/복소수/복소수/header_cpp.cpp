#include "header.h"  
// Constructor 
myComplex::myComplex(int real, int imag)
{
	realPart = real;
	imaginaryPart = imag;
}  // Copy constructor 
myComplex::myComplex(const myComplex& number)
{
	realPart = number.realPart;
	imaginaryPart = number.imaginaryPart;
}  // Accessor functions 
int myComplex::getRealPart() const
{
	return realPart;
}  
int myComplex::getImaginaryPart() const
{
	return imaginaryPart;
}  // Mutator functions 
void myComplex::setRealPart(int real)
{
	realPart = real;
} 
void myComplex::setImaginaryPart(int imag)
{
	imaginaryPart = imag;
}  
void myComplex::set(int real, int imag)
{
	realPart = real;
	imaginaryPart = imag;
}  // Overloaded binary operators 
myComplex myComplex::operator +(const myComplex& number) const
{
	int newReal = realPart + number.realPart;
	int newImag = imaginaryPart + number.imaginaryPart;
	return myComplex(newReal, newImag);
}
myComplex myComplex::operator +(int value) const
{
	return myComplex(value) + (*this);
}  // Assignment operators 
myComplex& myComplex::operator =(const myComplex& number)
{
	this->realPart = number.realPart;
	this->imaginaryPart = number.imaginaryPart;
	return *this;
}  
myComplex& myComplex::operator =(int value)
{
	realPart = value;
	imaginaryPart = 0;
	return *this;
}  // Overloading comparison operators 
bool myComplex::operator ==(const myComplex& number) const
{
	return (realPart == number.realPart) &&(imaginaryPart == number.imaginaryPart);
}
bool myComplex::operator >(const myComplex& number) const
{
	return norm() > number.norm();
}   // Overloaded unary operators 
myComplex myComplex::operator -()       // unary minus  
{
	return myComplex(-realPart, -imaginaryPart);
}  // private function 
int myComplex::norm() const
{
	return realPart * realPart + imaginaryPart * imaginaryPart;
}
ostream &operator <<(ostream &outStream, const myComplex& number)
{
	outStream << "(" << number.realPart << "," << number.imaginaryPart << ")";
	return outStream;
}
istream &operator >> (istream &inStream, myComplex& number)
{
	inStream >> number.realPart >> number.imaginaryPart;
	return inStream;
}
myComplex operator +(int value, const myComplex& number) 
{
	return myComplex(number.realPart + value, number.imaginaryPart);
}
myComplex operator -(int value, const myComplex& number) 
{
	return myComplex(value - number.realPart, -number.imaginaryPart);
}
myComplex operator *(int value, const myComplex& number) 
{
	return myComplex(number.realPart*value, number.imaginaryPart*value);
}
myComplex myComplex::operator-(int value) const {
	return myComplex(realPart - value, imaginaryPart);
}
myComplex myComplex::operator-(const myComplex& number) const {
	return myComplex(realPart - number.realPart, imaginaryPart - number.imaginaryPart);
}

myComplex myComplex::operator*(int value) const {
	return myComplex(realPart*value, imaginaryPart*value); 
}
myComplex myComplex::operator*(const myComplex& number) const {
	return myComplex(realPart * number.realPart - imaginaryPart * number.imaginaryPart
		, realPart * number.imaginaryPart + imaginaryPart * number.realPart);
}

bool myComplex::operator!=(const myComplex& number) const {
	return realPart != number.realPart || imaginaryPart != number.imaginaryPart;
}
bool myComplex::operator>=(const myComplex& number) const {
	return norm() >= number.norm();
}
bool myComplex::operator<(const myComplex& number) const {
	return norm() < number.norm();
}
bool myComplex::operator<=(const myComplex& number) const {
	return norm() <= number.norm();
}

myComplex& myComplex::operator+=(const myComplex& number) {
	this->realPart += number.realPart;
	this->imaginaryPart += number.imaginaryPart;
	return *this;
}
myComplex& myComplex::operator-=(const myComplex& number) {
	this->realPart -= number.realPart;
	this->imaginaryPart -= number.imaginaryPart;
	return *this;
}
myComplex& myComplex::operator*=(const myComplex& number) {
	int thisR = this->realPart, thisI = this->imaginaryPart;
	this->realPart = thisR * number.realPart - thisI * number.imaginaryPart;
	this->imaginaryPart = thisR * number.imaginaryPart + thisI * number.realPart;
	return *this;
}

myComplex myComplex::operator++() {
	++realPart;
	return *this;
}
myComplex myComplex::operator++(int) {
	++*this;
	return *this;
}
myComplex myComplex::operator--() {
	realPart -= 1;
	return *this;
}
myComplex myComplex::operator--(int) {
	myComplex out = *this;
	--*this;
	return out;
}
myComplex myComplex::operator~() {
	this->imaginaryPart = -this->imaginaryPart;
	return *this;
}