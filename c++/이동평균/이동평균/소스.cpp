/***********************************
*                                  *
*       problem                    *
*                이동 평균	       *
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
	int num, numcase,count;
	int arrayA[500], arrayB[500];
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
		for (int j = 0; j < numcase; j++)
			instream >> arrayA[j];
		
		instream >> count;
		int number = 0;
		for (int j = 0; j < numcase -count +1; j++)
		{
			int sum = 0;
			for (int k = j; k < j + count; k++)
			{
				sum+= arrayA[k];
			}
			arrayB[j] = sum/count;
			number++;
		}
		cout << number << " ";
		
		for (int j = 0; j < numcase - count + 1; j++)
			cout << arrayB[j] << " ";

		cout << endl;
	}
	instream.close();

	return 0;
}