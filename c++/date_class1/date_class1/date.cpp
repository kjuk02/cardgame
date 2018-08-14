#include"date.h"

int myDate::getDayOfMonth() const
{return day;}
int myDate::getMonth() const
{return month;}
int myDate::getYear() const
{return year;}
// Mutator functions (변경자)
void myDate::setDayOfMonth(int day_)
{
	day = day_;
}
void myDate::setMonth(int month_)
{
	month = month_;
}
void myDate::setYear(int year_)
{
	year = year_;
}
void myDate::setDate(int year_, int month_, int day_)
{
	year = year_;
	month = month_;
	day = day_;
}
// utility functions 
bool myDate::isLeapYear() const //윤년

{
	if (((year % 4 == 0)&&( year % 100 != 0)) || year % 400 == 0)
		return 1;
	else
		return 0;
}
int myDate::getDayOfWeek() const //0=Sunday, 1=Monday, ..., 6=Saturday
{
	int lastday = 0;
	for (int i = 1582; i<year; i++)
	{
		if (((i % 4 == 0) && (i % 100 != 0)) || i % 400 == 0)
			lastday += 366;
		else
			lastday += 365;
	}
	int oneday = 0;
	oneday=(lastday+ getDayOfYear() +(day-1)+ 5) %7;
	return oneday;
}
int myDate::getDayOfYear() const //1=Jan.1, 2=Jan.2, ..., 366=Dec.31 (in a leap year)
{
	int allday = 0;
	for (int m = 1; m < month; m++)
	{
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10)
			allday += 31;

		else if (m == 2)
		{
			if (isLeapYear())
				allday += 29;
			else
				allday += 28;
		}
		else
			allday += 30;
	}
	return allday;
}
int myDate::getNumHolidays() const //휴일수 계산
{
	myDate date(year, 1, 1);
	int first_day = date.getDayOfWeek();
	int allday = first_day;
	int allday2 =first_day;
	int holly_day = 0;
	for (int m = 1; m < 12; m++)
	{
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
			allday += 31, allday2 += 31;

		else if (m == 2)
		{
			if (isLeapYear())
				allday += 29, allday2 += 29;
			else
				allday += 28, allday2 += 28;
		}
		else
			allday += 30, allday2 += 30;
			
		if (allday % 7 == 0)
			holly_day++, allday / 7;
		if (allday2 % 6 == 0)
			holly_day++, allday2 / 6;
	}
	int arr[][2] = { 1,1,2,1,2,3,5,15,9,15,9,16,9,17,3,1,5,5,6,5,7,17,8,15,10,3,12,25 };
	for (int i = 0; i < 14; i++)
	{
		myDate date(year, arr[i][0], arr[i][1]);
		if (getDayOfWeek() == 6 || getDayOfWeek() == 0)
			holly_day--;
	}
	return holly_day;
}
int myDate::getNumSummerTimeDays()const //써머타임 날짜수
{
	return 0;
}
void myDate::printCalendarOfMonth() const // 달력출력하기
{

}