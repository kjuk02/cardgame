/***********************************
*                                  *
*       problem                    *
*             수직 수평성분의 교차 *
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
using namespace std;

#define max(a,b) (a>b) ? a : b ;
#define min(a,b) (a>b) ? b : a ;

int check(int x, int y, int x2, int y2);
void check2(int x, int y, int x2, int y2, int x3, int y3, int x4, int y4);
void check3(int x, int y, int x2, int y2, int x3, int y3, int x4, int y4);

int main()
{
	int num, x, y, x2, y2, x3, y3, x4, y4;
	fstream instream;
	instream.open("input.txt");
	if (instream.fail())
	{
		cerr << "input file openning error " << endl;
		exit(1);
	}

	instream >> num;

	for (int i = 0; i < num; i++)
	{
		instream >> x >> y >> x2 >> y2;
		instream >> x3 >> y3 >> x4 >> y4;

		if (check(x, y, x2, y2) == 1) // 수직일경우
		{
			check2(x, y, x2, y2, x3, y3, x4, y4);
		}
		else//수평일경우
		{
			check3(x, y, x2, y2, x3, y3, x4, y4);
		}
	}
	instream.close();
	return 0;
}

int check(int x, int y, int x2, int y2)
{
	if (x == x2)
		return 1;
	else
		return 0;
}

void check2(int x, int y, int x2, int y2, int x3, int y3, int x4, int y4)
{
	int temp;
	temp = y;
	y = min(y, y2);
	y2 = max(temp, y2);

	temp = x3;
	x3 = min(x3, x4);
	x4 = max(temp, x4);

	if (x3 <= x && x <= x4)
	{
		if (y <= y3 && y3 <= y2)
		{
			if (x == x3 || x == x4 || y3 == y || y3 == y2)
				cout << 2 << endl;
			else
				cout << 1 << endl;
		}
		else
			cout << 0 << endl;
	}
	else
	{
		cout << 0 << endl;
	}
}

void check3(int x, int y, int x2, int y2, int x3, int y3, int x4, int y4)
{
	int temp;
	temp = x;
	x = min(x, x2);
	x2 = max(temp, x2);

	temp = y3;
	y3 = min(y3, y4);
	y4 = max(temp, y4);

	if (x <= x3&&x3 <= x2)
	{
		if (y3 <= y&&y <= y4)
		{
			if (x == x3 || x3 == x2 || y3 == y || y == y4)
				cout << 2 << endl;
			else
				cout << 1 << endl;
		}
		else
			cout << 0 << endl;
	}
	else
		cout << 0 << endl;
}