/***********************************
*                                  *
*       problem                    *
*                패리티 비트       *
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
		int sum = 0;
		int mask = 1;
		unsigned int number = 1;
		int nums = 0;
		nums = numcase;
		cout << nums << endl;
		while (nums > 0)
		{
			if (nums % 2==0)
				cout << 1;
			else
				cout << 0;

			nums /= 2;
		}

		/*	if (sum % 2 != 0 || numcase == 1)
			{
				for (int k = 0; k < 31; k++)
					number = 2 * number;

				number += numcase;
			}
			else if (numcase == 0)
				number = 0;
			else
				number = numcase;
			std::cout << number << std::endl;*/
	}
	instream.close();

	return 0;
}