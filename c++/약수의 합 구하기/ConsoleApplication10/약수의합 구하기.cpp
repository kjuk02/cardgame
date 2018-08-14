/***********************************
*                                  *
*       problem                    *
*               약수의 합 구하기   *
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

int main()
{
	int num, numcase;
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
		instream >> numcase;

		int number = 1, sum = 1;
		for (int j = 2; j <= sqrt(numcase); j++)
		{
			if (numcase%j == 0)
			{
				if ((j*j) == numcase)
				{
					sum += j;
					number++;
				}
				else
				{
					number += 2;
					sum += j;
					sum += numcase / j;
				}
			}
		}
		cout << number << " " << sum << endl;
	}
	instream.close();
	return 0;
}