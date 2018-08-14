/***********************************
*                                  *
*		 problem                   *
*				절단 대각선		   *
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
		int arrayA[1000] = { 0, };
		int arrayB[1000] = { 0, };
		int arrayC[500][500] = { 0, };

		for (int j = 0; j < numcase; j++)
		{
			for (int k = 0; k < numcase; k++)
			{
				instream >> arrayC[j][k];
			}
		}
		int numcase2 = numcase - 1;
		for (int j=0;j<numcase;j++)//우측방향
		{
			int sum = 0;
			for (int k = 0; k < numcase; k++)
			{
				int count = k + j;
				if (count > numcase2)
				{
					count--;
					count %= numcase2;
					sum += arrayC[(numcase2) - k][count];
				}
				else
				sum += arrayC[(numcase2) - k][count];
			}
			arrayA[j] = sum;
		}
		for (int j = 0; j < numcase; j++)//좌측방향
		{
			int sum = 0;
			for (int k = 0; k < numcase; k++)
			{
				int count = k + j;
				if (count > numcase2)
				{
					count--;
					count %= numcase2;
					sum += arrayC[k][count];
				}
				else
					sum += arrayC[k][count];
			}
			arrayB[j] = sum;
		}
		int temp = arrayA[0];
		
		for (int n = 0; n < numcase; n++)
			if (temp < arrayA[n])
				temp = arrayA[n];
		
		for (int n = 0; n < numcase; n++)
			if (temp < arrayB[n])
				temp = arrayB[n];
		
		cout << temp << endl;
	}
	instream.close();
	
	return 0;
}