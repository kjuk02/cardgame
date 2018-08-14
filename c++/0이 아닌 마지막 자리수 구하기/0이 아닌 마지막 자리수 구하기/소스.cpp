/***********************************
*                                  *
*  problem                         *
*    0이 아닌 마지막 자리수 구하기 *
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
		instream >> numcase;
		unsigned int arrayA[500] = { 0, };
		unsigned int sum = 1;
		unsigned int rest = 0;
		unsigned int number = 0;
		int count = 0;
		int two = 0;
		int five = 0;
		for (int j = 0; j < numcase; j++)
		{
			instream >> number;

			while (number % 2 == 0)
				number = number / 2,two++;
			
			while (number % 5 == 0)
				number = number / 5, five++;

			arrayA[j] = number % 10;
		}

		for (int k = 0; k < numcase; k++)
		{
			sum *= arrayA[k];
			sum %= 10;
		}
		if (two > five)
		{
			int hw = two - five;
			for (int f = 0; f < hw; f++)
			{
				sum *= 2;
				sum = sum % 10;
			}
			sum = sum % 10;
		}
		else
		{
			int hw = five - two;
			for (int f = 0; f < hw; f++)
			{
				sum *= 5;
				sum = sum % 10;
			}
			sum = sum % 10;
		}
		
		cout << sum << " ";

		if (two > five)
			cout << five << endl;
		else
			cout << two << endl;
	}
	instream.close();

	return 0;
}