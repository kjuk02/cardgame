#ifndef _MYDATE_H_
#define _MYDATE_H_
#include <iostream>
using namespace std;
class myDate {
public:
	// Constructor (������)
	myDate() {}
	myDate(int year_, int month_, int day_) :year(year_), month(month_), day(day_) {}
	// Accessor functions (������)
	int getDayOfMonth() const;
	int getMonth() const;
	int getYear() const;
	// Mutator functions (������)
	void setDayOfMonth(int day);
	void setMonth(int month);
	void setYear(int year);
	void setDate(int year, int month, int day);
	// utility functions 
	bool isLeapYear() const; //����
	int getDayOfWeek() const; //0=Sunday, 1=Monday, ..., 6=Saturday
	int getDayOfYear() const; //1=Jan.1, 2=Jan.2, ..., 366=Dec.31 (in a leap year)
	int getNumHolidays() const; //���ϼ� ���
	int getNumSummerTimeDays()const; //���Ÿ�� ��¥��
	void printCalendarOfMonth(); // �޷�����ϱ�
	int monthday(int arrayA[]);
private:
	int year;
	int month;
	int day;
};
#endif