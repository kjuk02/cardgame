#include <iostream>
#include <fstream>
#include <cmath>
#include<algorithm>

using namespace std;

int yunyear(int year);
int allday(int year,int month,int day);
void print(int lastday);
int main(void) 
{
	ifstream inStream;
	inStream.open("input.txt");

	int numTestcase;
	inStream >> numTestcase;

	for (int i = 0; i < numTestcase; i++) 
	{
		int year, month, day;
		inStream >> year >> month >> day;

		int lastday = 0;
		lastday = allday(year, month,day);

		print(lastday);
	}
}
int yunyear(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}
int allday(int year,int month,int day)
{
	int date = 0;
	for (int i = 1582; i < year; i++) 
	{
		if (yunyear(i) == 1) 
			date = date + 366;
	
		else 
			date= date + 365;
	}
	for (int i = 1; i < month; i++) 
	{
		if ((i == 1) || (i == 3) || (i == 5) || (i == 7) || (i == 8) || (i == 10))
			date = date + 31;
		if (i == 2) 
			if (yunyear(year)==1)
				date = date + 29;
			else 
				date = date + 28;
		if ((i == 4) || (i == 6) || (i == 9) || (i == 11)) 
			date = date + 30;
	}
	date += day;
	return date;
}
void print(int lastday) 
{
	if (lastday % 7 == 1) 
		cout << 5 << endl;
	else if (lastday % 7 == 2)
		cout << 6 << endl;
	else if (lastday % 7 == 3)
		cout << 0 << endl;
	else if (lastday % 7 == 4)
		cout << 1 << endl;
	else if (lastday % 7 == 5)
		cout << 2 << endl;
	else if (lastday % 7 == 6)
		cout << 3 << endl;
	else if (lastday % 7 == 0)
		cout << 4 << endl;
}