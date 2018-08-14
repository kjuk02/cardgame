/***********************************
*                                  *
*       problem                    *
*                날짜 구하기       *
*                                  *
*                                  *
***********************************/

/************************************
*                                   *
*       소프트웨어학부              *
*                20143050           *
*                        김현석     *
*                                   *
************************************/
#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	int num, numcase;
	int month, day;

	ifstream instream;
	instream.open("input.txt");
	if (instream.fail())
	{
		cerr << "input file openning error " << endl;
		exit(1);
	}
	instream >> num;
	for (int i = 0; i < num; i++)
	{
		instream >> numcase >> month >> day;
		int allday = 0;
		int lastday = 0;
		for (int j = 1582; j<numcase; j++)
		{
			if (((j % 4 == 0) && (j % 100 != 0)) || j % 400 == 0)
				allday += 366;
			else
				allday += 365;
		}
		for (int m = 1; m < month; m++)
		{	
			if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10)
				allday += 31;

			else if (m == 2)
			{
				if (((numcase % 4 == 0) && (numcase % 100 != 0)) || numcase % 400 == 0)
					allday += 29;
				else
					allday += 28;
			}
			else
				allday += 30;
		}
		lastday = (((day-1 )+allday)+5) % 7;
		cout << lastday << endl;
	}
	instream.close();

	return 0;
}