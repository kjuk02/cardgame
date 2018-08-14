#include <iostream>
#include <cstdlib>
#include "date.h"

myDate::myDate(int year, int month, int day)
	:Y(year), M(month), D(day) {}

myDate::myDate(const myDate& date)
	: Y(date.Y), M(date.M), D(date.D) {}

int myDate::getDayOfMonth() const
{
	return D;
}

int myDate::getMonth() const
{
	return M;
}

int myDate::getYear() const
{
	return Y;
}

void myDate::setDayOfMonth(int day)
{
	D = day;
}

void myDate::setMonth(int month)
{
	M = month;
}

void myDate::setYear(int year)
{
	Y = year;
}

void myDate::setDate(int year, int month, int day)
{
	Y = year;
	M = month;
	D = day;
}

bool myDate::isLeapYear() const
{
	return ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0);
}

int myDate::getDayOfWeek() const
{
	int dayW = 5;
	for (int a = 1582; a<Y; a++) {
		if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
			dayW += 2;
		else
			dayW += 1;
	}
	dayW %= 7;
	for (int a = 1; a<M; a++) {
		if (a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12)
			dayW += 3;
		else if (a == 2) {
			if ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0)
				dayW += 1;
		}
		else
			dayW += 2;
	}
	dayW += D - 1;
	dayW %= 7;

	return dayW;
}

int myDate::getDayOfYear() const
{
	int dayY = 0;
	for (int a = 1; a<M; a++) {
		if (a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12)
			dayY += 31;
		else if (a == 2) {
			if ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0)
				dayY += 29;
			else
				dayY += 28;
		}
		else
			dayY += 30;
	}
	dayY += D;

	return dayY;
}

int myDate::getNumHolidays() const
{
	int dayY = 365, holiday = 0, dayW = 5;

	if (isLeapYear())
		++dayY;

	for (int a = 1582; a<Y; a++) {
		if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
			dayW += 2;
		else
			dayW += 1;
	}
	dayW %= 7;

	for (int a = 1; a <= dayY; a++) {
		if (dayW == 6 || dayW == 0)
			++holiday;
		else if (isLeapYear() && (a == 1 || a == 32 || a == 33 || a == 34 || a == 61 || a == 126 || a == 136 || a == 158 || a == 199 || a == 228 || a == 259 || a == 260 || a == 261 || a == 277 || a == 360))
			++holiday;
		else if (!isLeapYear() && (a == 1 || a == 32 || a == 33 || a == 34 || a == 60 || a == 125 || a == 135 || a == 157 || a == 198 || a == 227 || a == 258 || a == 259 || a == 260 || a == 276 || a == 359))
			++holiday;
		++dayW %= 7;
	}

	return holiday;
}

int myDate::getNumSummerTimeDays()const
{
	int st = 214;
	int day3, day10;
	myDate my1(Y, 3, 31);
	myDate my2(Y, 10, 31);
	day3 = my1.getDayOfWeek();
	day10 = my2.getDayOfWeek();

	while (1) {
		if (day3 == 0)
			break;
		--day3;
		++st;
	}
	while (1) {
		if (day10 == 0)
			break;
		--day10;
		--st;
	}

	return st;
}

void myDate::printCalendarOfMonth() const
{
	myDate my(Y, M, 1);
	int dayW(my.getDayOfWeek());
	int dayM;

	cout << Y << " " << M << endl;

	for (int a = 0; a<dayW; a++)
		cout << 0 << " ";

	if (M == 2 && isLeapYear())
		dayM = 29;
	else if (M == 2)
		dayM = 28;
	else if (M == 4 || M == 6 || M == 9 || M == 11)
		dayM = 30;
	else
		dayM = 31;

	for (int a = 1; a <= dayM; a++) {
		cout << a << " ";
		++dayW %= 7;
		if (a != dayM && dayW == 0)
			cout << endl;
	}

	if (dayW != 0)
		for (int a = dayW; a<7; a++)
			cout << 0 << " ";
}

ostream &operator <<(ostream &outStream, const myDate& date)
{
	if (date.D>9)
		cout << date.D << "/";
	else
		cout << "0" << date.D << "/";
	if (date.M>9)
		cout << date.M << "/";
	else
		cout << "0" << date.M << "/";

	cout << date.Y;

	return outStream;
}

istream &operator >> (istream &inStream, myDate& date)
{
	inStream >> date.Y >> date.M >> date.D;
	return inStream;
}

myDate operator +(int num, const myDate& date)
{
	myDate my(date);
	if (num<0)
		return date - (-num);

	while ((my.isLeapYear() && num + my.getDayOfYear()>366) || (!my.isLeapYear() && num + my.getDayOfYear()>365))
	{
		if (my.isLeapYear()) {
			num -= (367 - my.getDayOfYear());
			++my.Y;
			my.M = 1;
			my.D = 1;
		}
		else {
			num -= (366 - my.getDayOfYear());
			++my.Y;
			my.M = 1;
			my.D = 1;
		}
	}


	int dayM[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (my.isLeapYear())
		++dayM[1];
	while (num + my.D>dayM[my.M - 1])
	{
		if (num + date.D > dayM[my.M - 1])
		{
			num -= (dayM[my.M - 1] - (my.D - 1));
			++my.M;
			my.D = 1;
		}
	}
	my.D += num;

	if (my.Y < 1582)
	{
		my.Y = 1582;
		my.M = 1;
		my.D = 1;
	}

	return my;
}

int myDate::operator -(const myDate& date) const
{
	int count1(0), count2(0);
	for (int a = 1582; a<Y; a++)
	{
		if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
			count1 += 366;
		else
			count1 += 365;
	}
	for (int a = 1582; a<date.Y; a++)
	{
		if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
			count2 += 366;
		else
			count2 += 365;
	}
	count1 += getDayOfYear();
	count2 += date.getDayOfYear();

	return count1 - count2;
}

myDate myDate::operator +(int num) const
{
	return num + *this;
}

myDate myDate::operator -(int num) const
{
	myDate my(Y, M, D);
	if (num<0)
		return *this + (-num);
	while (my.getDayOfYear() - num<1)
	{
		num -= my.getDayOfYear();
		--my.Y;
		my.M = 12;
		my.D = 31;
	}

	int dayM[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (my.isLeapYear())
		++dayM[1];
	while (my.D - num<1)
	{
		num -= my.D;
		--my.M;
		my.D = dayM[my.M - 1];
	}

	my.D -= num;

	if (my.Y < 1582)
	{
		my.Y = 1582;
		my.M = 1;
		my.D = 1;
	}

	return my;
}

myDate& myDate::operator ++()
{
	int dayM[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear())
		++dayM[1];
	++D;
	if (D == dayM[M - 1] + 1)
	{
		D = 1;
		++M;
		if (M == 13)
		{
			M = 1;
			++Y;
		}
	}
	return *this;
}

myDate& myDate::operator --()
{
	int dayM[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear())
		++dayM[1];
	--D;
	if (D == 0)
	{
		--M;
		if (M == 0)
		{
			--Y;
			M = 12;
		}
		D = dayM[M - 1];
	}
	return *this;
}

myDate myDate::operator ++(int)
{
	myDate my(Y, M, D);
	int dayM[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear())
		++dayM[1];
	++D;
	if (D == dayM[M - 1] + 1)
	{
		D = 1;
		++M;
		if (M == 13)
		{
			M = 1;
			++Y;
		}
	}
	return my;
}

myDate myDate::operator --(int)
{
	myDate my(Y, M, D);
	int dayM[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear())
		++dayM[1];
	--D;
	if (D == 0)
	{
		--M;
		if (M == 0)
		{
			--Y;
			M = 12;
		}
		D = dayM[M - 1];
	}
	return my;
}

myDate& myDate::operator =(const myDate& date)
{
	Y = date.Y;
	M = date.M;
	D = date.D;

	return *this;
}

myDate& myDate::operator +=(int num)
{
	*this = *this + num;
	return *this;
}

myDate& myDate::operator -=(int num)
{
	*this = *this - num;
	return *this;
}

bool myDate::operator >(const myDate& date) const
{
	if (this->Y>date.Y)
		return true;
	else if (this->Y == date.Y && M>date.M)
		return true;
	else if (this->Y == date.Y && this->M == date.M && this->D>date.D)
		return true;
	else
		return false;
}

bool myDate::operator >=(const myDate& date) const
{
	if (Y>date.Y)
		return true;
	else if (Y == date.Y && M>date.M)
		return true;
	else if (Y == date.Y && M == date.M && D >= date.D)
		return true;
	else
		return false;
}

bool myDate::operator <(const myDate& date) const
{
	if (Y<date.Y)
		return true;
	else if (Y == date.Y && M<date.M)
		return true;
	else if (Y == date.Y && M == date.M && D<date.D)
		return true;
	else
		return false;
}

bool myDate::operator <=(const myDate& date) const
{
	if (Y<date.Y)
		return true;
	else if (Y == date.Y && M<date.M)
		return true;
	else if (Y == date.Y && M == date.M && D <= date.D)
		return true;
	else
		return false;
}

bool myDate::operator ==(const myDate& date) const
{
	if (Y == date.Y && M == date.M && D == date.D)
		return true;
	else
		return false;
}

bool myDate::operator !=(const myDate& date) const
{
	if (Y != date.Y || M != date.M || D != date.D)
		return true;
	else
		return false;
}