#ifndef _MYDATE_H_
#define _MYDATE_H_
#include <iostream>

using namespace std;

class myDate {
	// friend 함수
	friend ostream &operator <<(ostream &outStream, const myDate& date);
	friend istream &operator >> (istream &inStream, myDate& date);
	friend myDate operator +(int num, const myDate& date);
public:
	// Constructor (생성자)
	myDate(int year = 1582, int month = 1, int day = 1);

	// Copy Constructor (복사 생성자)
	myDate(const myDate& date);

	// Accessor functions (접근자)
	int getDayOfMonth() const;
	int getMonth() const;
	int getYear() const;

	// Mutator functions (변경자)
	void setDayOfMonth(int day);
	void setMonth(int month);
	void setYear(int year);
	void setDate(int year, int month, int day);

	// Operators overloaded
	int operator -(const myDate& date) const; // difference between two days
	myDate operator +(int num) const;
	myDate operator -(int num) const;
	myDate& operator ++(); // prefix increment
	myDate& operator --(); // prefix decrement
	myDate operator ++(int); // postfix increment
	myDate operator --(int); // postfix decrement
	myDate& operator =(const myDate& date);
	myDate& operator +=(int num);
	myDate& operator -=(int num);
	bool operator >(const myDate& date) const;
	bool operator >=(const myDate& date) const;
	bool operator <(const myDate& date) const;
	bool operator <=(const myDate& date) const;
	bool operator ==(const myDate& date) const;
	bool operator !=(const myDate& date) const;

	// utility functions
	bool isLeapYear() const; //윤년
	int getDayOfWeek() const; //0=Sunday, 1=Monday, ..., 6=Saturday
	int getDayOfYear() const; //1=Jan.1, 2=Jan.2, ..., 366=Dec.31 (in a leap year)
	int getNumHolidays() const; //휴일수 계산
	int getNumSummerTimeDays()const; //써머타임 날짜수
	void printCalendarOfMonth() const; // 달력출력하기
private:
	// information hiding : implement as you wish
	int Y, M, D;
};
#endif