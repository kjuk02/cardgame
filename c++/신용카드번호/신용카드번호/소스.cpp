/***********************************
*                                  *
*       problem                    *
*             신용카드번호          *
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
#include<cstdlib>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	int num;
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
		string k;
		instream >> k;
		if ((k[0] - 48) == 3)
		{
			if (k.size() != 14 && k.size() != 15)
			{
				cout << 0 << endl;
				continue;
			}
		}
		else if ((k[0] - 48) == 4)
		{
			if (k.size() != 13 && k.size() != 16)
			{
				cout << 0 << endl;
				continue;
			}
		}
		else if ((k[0] - 48) == 5)
		{
			if (k.size() != 16)
			{
				cout << 0 << endl;
				continue;
			}
		}
		else if ((k[0] - 48) == 6)
		{
			if (k.size() != 16)
			{
				cout << 0 << endl;
				continue;
			}
		}
		else
		{
			cout << 0 << endl;
			continue;
		}
		int sum = 0;
		for (int i = k.size() - 2; i >= 0; i = i - 2)
		{
			if ((k[i] - 48) * 2<10)
				sum += (k[i] - 48) * 2;
			else if ((k[i] - 48) * 2 >= 10)
				sum += (k[i] - 48) * 2 - 9;
		}

		for (int i = k.size() - 1; i >= 0; i = i - 2)
		{
			sum += k[i] - 48;
		}
		if (sum % 10 == 0)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	instream.close();

	return 0;
}