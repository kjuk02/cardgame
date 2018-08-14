/***********************************
*                                  *
*       problem                    *
*                Çà·Ä µ¡¼À	       *
*                                  *
*                                  *
***********************************/

/************************************
*                                   *
*       ¼ÒÇÁÆ®¿þ¾îÇÐºÎ              *
*                20143050           *
*                        ±èÇö¼®     *
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
	int x, y;
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
		instream >> x >> y;
		int arrayA[100][100];
		int arrayB[100][100];
		int arrayC[100][100];
		for (int j = 0; j < x; j++)
			for (int k = 0; k < y; k++)
				instream >> arrayA[j][k];

		for (int j = 0; j < x; j++)
			for (int k = 0; k < y; k++)
				instream >> arrayB[j][k];

		for (int j = 0; j < x; j++)
			for (int k = 0; k < y; k++)
				arrayC[j][k] = arrayA[j][k] + arrayB[j][k];

		for (int j = 0; j < x; j++)
		{
			for (int k = 0; k < y; k++)
			{
				cout << arrayC[j][k]<<" ";
			}
			cout << endl;
		}
	}
	instream.close();

	return 0;
}