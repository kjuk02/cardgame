#include <iostream>
#include <fstream>
#include <cstdlib>
#include "date.h"
using namespace std;
int main(void)
{
	ifstream inStream;
	int numTestCases;
	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}
	inStream >> numTestCases;
	for (int i = 0; i<numTestCases; i++)
	{
		int year, month, day;
		inStream >> year >> month >> day;
		myDate date1(year, month, day);
		myDate date2;
		cout << date1.getYear() << " ";
		cout << date1.getMonth() << " ";
		cout << date1.getDayOfMonth() << endl;
		cout << date1.isLeapYear() << " ";
		cout << date1.getDayOfWeek() << endl;
		inStream >> year >> month >> day;
		date2.setDayOfMonth(day);
		date2.setMonth(month);
		date2.setYear(year);
		cout << date2.getYear() << " ";
		cout << date2.getMonth() << " ";
		cout << date2.getDayOfMonth() << endl;
		cout << date2.isLeapYear() << " ";
		cout << date2.getDayOfWeek() << endl;
		inStream >> year >> month >> day;
		date2.setDate(year, month, day);
		cout << date2.getYear() << " ";
		cout << date2.getMonth() << " ";
		cout << date2.getDayOfMonth() << endl;
		cout << date2.isLeapYear() << " ";
		cout << date2.getDayOfWeek() << endl;
	}
	inStream.close();
	return 0;
}