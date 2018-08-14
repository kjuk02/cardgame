/***********************************
*                                  *
*       problem                    *
*                최빈값		       *
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
using namespace std;

int main()
{
	int num = 0, numcase = 0;
	int arrayB[101], arrayC[101];

	fstream instream;
	instream.open("input.txt");
	if (instream.fail())
	{
		cerr << "input file openning error " << endl;
		exit(1);
	}
	
	instream >> num;

	cout << num << endl;
	for (int i = 0; i < num; i++)
	{
		instream >> numcase;
		for (int j = 0; j < numcase; j++)
		{
			instream >> arrayB[j];
			arrayC[j] = arrayB[j];
		}
		for (; numcase>0; numcase--)
		{
			for (int m = 0; m <= numcase; m++)
			{
				if (arrayB[m] > arrayB[m + 1])
				{
					int temp = arrayB[m];
					arrayB[m] = arrayB[m + 1];
					arrayB[m + 1] = temp;
				}
			}
		}
		for (int b = 0; b < numcase; b++)
			cout << arrayB[b] << endl;

	}

	instream.close();

	return 0;
}
