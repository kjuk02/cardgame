#ifndef _MYRATIONAL_H_
#define _MYRATIONAL_H_
#include <iostream>

class myRational {
	friend myRational operator +(const int& n, const myRational& r);
	friend myRational operator -(const int& n, const myRational& r);
	friend myRational operator *(const int& n, const myRational& r);
	friend myRational operator /(const int& n, const myRational& r);
	friend std::ostream &operator <<(std::ostream &outStream, const myRational& r);
	friend std::istream &operator >> (std::istream &inStream, myRational& r);
public:
	myRational(long n = 0, long d = 1);
	myRational(const myRational& r);
	
	long getNumerator() const;
	long getDenominator() const;
	
	myRational operator +(const int& n) const;
	myRational operator -(const int& n) const;
	myRational operator *(const int& n) const;
	myRational operator /(const int& n) const;
	myRational operator +(const myRational& r) const;
	myRational operator -(const myRational& r) const;
	myRational operator *(const myRational& r) const;
	myRational operator /(const myRational& r) const;
		
	myRational& operator =(const myRational& r);
	myRational& operator +=(const myRational& r);
	myRational& operator -=(const myRational& r);
	myRational& operator *=(const myRational& r);
	myRational& operator /=(const myRational& r);
	
	myRational& operator ++();
	myRational& operator --();
	myRational operator ++(int);
	myRational operator --(int);
	myRational operator -();

	bool operator >(const myRational& r) const;
	bool operator >=(const myRational& r) const;
	bool operator <(const myRational& r) const;
	bool operator <=(const myRational& r) const;
	bool operator ==(const myRational& r) const;
	bool operator !=(const myRational& r) const;
private:
	long num;// 분수는 항상 내부적으로 기약분수로 표현하며, 또한 항상 _den>0 이다. long _num; // numerator
	long den; // denominator
	long gcd(long m, long n); // 최대공약수
	void reduce();
};
#endif