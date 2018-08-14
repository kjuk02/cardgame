#include "header.h"
myRational::myRational(long n, long d) :num(n), den(d) {
	reduce();
}

myRational::myRational(const myRational& r) {
	this->num = r.num;
	this->den = r.den;
	reduce();
}
long myRational::getNumerator() const
{
	return num;
}

long myRational::getDenominator() const
{
	return den;
}

std::ostream &operator <<(std::ostream &outStream, const myRational& r)
{
	if (r.num == 0)
		outStream << 0;
	else if (r.den == 1)
		outStream << r.num;
	else
		outStream << r.num << "/" << r.den;
	return outStream;
}

std::istream &operator >> (std::istream &inStream, myRational& r)
{
	inStream >> r.num >> r.den;
	if (r.den == 0)
	{
		r.num = 0;
		r.den = 1;
	}
	r.reduce();
	return inStream;
}
// overloaded operator
myRational myRational::operator +(const int& n) const
{
	myRational m(num, den);
	m.num += n*m.den;
	m.reduce();
	return m;
}

myRational myRational::operator -(const int& n) const
{
	myRational m(num, den);
	m.num -= n*m.den;
	m.reduce();
	return m;
}

myRational myRational::operator *(const int& n) const
{
	myRational m(num, den);
	m.num *= n;
	m.reduce();
	return m;
}

myRational myRational::operator /(const int& n) const
{

	myRational m(num, den);
	if (n == 0)
	{
		m.num = 0;
	}
	else
	{
		m.den *= n;
	}
	m.reduce();
	return m;
}

myRational myRational::operator +(const myRational& r) const
{
	myRational m1(num, den);
	myRational m2(r.num, r.den);
	int den_ = m1.den;
	m1.den *= m2.den;  m1.num *= m2.den;
	m2.den *= den_;  m2.num *= den_;
	m1.num += m2.num;
	m1.reduce();
	return m1;
}

myRational myRational::operator -(const myRational& r) const
{
	myRational m1(num, den);
	myRational m2(r.num, r.den);
	int den_ = m1.den;
	m1.den *= m2.den;  m1.num *= m2.den;
	m2.den *= den_;  m2.num *= den_;
	m1.num -= m2.num;
	m1.reduce();
	return m1;
}

myRational myRational::operator *(const myRational& r) const
{
	myRational m(num, den);
	m.num *= r.num;
	m.den *= r.den;
	m.reduce();
	return m;
}

myRational myRational::operator /(const myRational& r) const
{
	myRational m(num, den);
	if (r.num == 0)
	{
		m.num = 0;
	}
	else
	{
		m.num *= r.den;
		m.den *= r.num;
	}
	m.reduce();
	return m;
}

myRational operator +(const int& n, const myRational& r)
{
	int num_, den_;
	den_ = r.den;
	num_ = r.num + r.den*n;
	return myRational(num_, den_);
}
myRational operator -(const int& n, const myRational& r)
{
	int num_, den_;
	den_ = r.den;
	num_ = r.den*n - r.num;
	return myRational(num_, den_);
}
myRational operator *(const int& n, const myRational& r)
{
	int num_, den_;
	num_ = n*r.num;
	den_ = r.den;
	return myRational(num_, den_);
}
myRational operator /(const int& n, const myRational& r)
{
	int num_, den_ = 1;
	if (n == 0 || r.num == 0)
	{
		num_ = 0;
	}
	else
	{
		num_ = n*r.den;
		den_ = r.num;
	}
	return myRational(num_, den_);
}
//compare operator
bool myRational::operator >(const myRational& r) const
{
	myRational m1(num, den);
	myRational m2(r.num, r.den);
	m1.num *= m2.den; m2.num *= m1.den;
	return (m1.num>m2.num);
}

bool myRational::operator >=(const myRational& r) const
{
	myRational m1(num, den);
	myRational m2(r.num, r.den);
	m1.num *= m2.den; m2.num *= m1.den;
	return (m1.num >= m2.num);
}

bool myRational::operator <(const myRational& r) const
{
	myRational m1(num, den);
	myRational m2(r.num, r.den);
	m1.num *= m2.den; m2.num *= m1.den;
	return (m1.num<m2.num);
}

bool myRational::operator <=(const myRational& r) const
{
	myRational m1(num, den);
	myRational m2(r.num, r.den);
	m1.num *= m2.den; m2.num *= m1.den;
	return (m1.num <= m2.num);
}

bool myRational::operator ==(const myRational& r) const
{
	myRational m1(num, den);
	myRational m2(r.num, r.den);
	int num1, num2;
	num1 = num*r.den; num2 = r.num*den;

	return (num1 == num2);
}

bool myRational::operator !=(const myRational& r) const
{
	return !(*this == r);
}
//assignment operator

myRational& myRational::operator =(const myRational& r)
{
	this->num = r.num;
	this->den = r.den;
	reduce();
	return *this;
}
myRational& myRational::operator +=(const myRational& r)
{
	*this = *this + r;
	reduce();
	return *this;
}
myRational& myRational::operator -=(const myRational& r)
{
	*this = *this - r;
	reduce();
	return *this;
}
myRational& myRational::operator *=(const myRational& r)
{
	*this = *this * r;
	reduce();
	return *this;
}
myRational& myRational::operator /=(const myRational& r)
{
	if (r.num == 0)
	{
		this->num = 0;
	}
	else
	{
		*this = *this / r;
	}
	reduce();
	return *this;
}

//unary operator
myRational myRational::operator -()
{
	return myRational(-this->num, this->den);
}

myRational& myRational::operator ++()
{
	this->num += this->den;
	this->reduce();
	return *this;
}

myRational& myRational::operator --()
{
	this->num -= this->den;
	this->reduce();
	return *this;
}

myRational myRational::operator ++(int)
{
	myRational m(this->num, this->den);
	this->num += this->den;
	this->reduce();
	return m;
}

myRational myRational::operator --(int)
{
	myRational m(this->num, this->den);
	this->num -= this->den;
	this->reduce();
	return m;
}

//element
long myRational::gcd(long m, long n)
{
	if (m == n)
		return n;
	else if (m < n)
		return gcd(m, n - m);
	else
		return gcd(m - n, n);
}

void myRational::reduce()
{
	if (num == 0 || den == 0)
	{
		num = 0;
		den = 1;
		return;
	}
	if (den < 0)
	{
		den *= -1;
		num *= -1;
	}
	if (num == 1)
		return;
	int sgn = (num < 0 ? -1 : 1);
	long g = gcd(sgn * num, den);
	num /= g;
	den /= g;
}
