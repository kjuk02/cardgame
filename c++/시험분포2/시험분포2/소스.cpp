/***********************************
*                                  *
*       problem                    *
*                시험 점수 분포    *
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
void arraychange(int arrayA[], int numcase);

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
		int arrayA[101] = { 0 };
		for (int j = 0; j < numcase; j++)
			instream >> arrayA[j];

		sort(arrayA, arrayA + numcase);
		
		void arraychange(int arrayA[], int numcase);

		cout << endl;
	}
	instream.close();

	return 0;
}

void arraychange(int arrayA[],int numcase)
{
	int number = 1;
	for (int k = 0; k < numcase; k++)
	{
		for (int f = k; f < numcase; f++)
		{
			if (arrayA[f] == arrayA[f + 1])
				number++, k++;
			else
			{
				cout << arrayA[f] << " " << number << " ";
				number = 1;
				k++;
			}
		}
	}
}