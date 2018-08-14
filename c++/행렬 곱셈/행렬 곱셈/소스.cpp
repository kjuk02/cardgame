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
	int num, x,y,z;
	ifstream instream;
	instream.open("input.txt");
	if (instream.fail())
	{
		cerr << "input file openning error " << endl;
		exit(1);
	}
	instream >> num;
	int arrayA[100][100];
	int arrayB[100][100];
	int arrayC[100][100] = { {0,0} };
	for (int i = 0; i < num; i++)
	{
		instream >> x >> y >> z;

		for (int j = 0; j < x; j++)
			for (int k = 0; k < y; k++)
				instream >> arrayA[j][k];
		
		
		for (int j = 0; j < y; j++)
			for (int k = 0; k < z; k++)
				instream >> arrayB[j][k];


		for (int l = 0; l < z; l++)
		{
			for (int j = 0; j < x; j++)
			{
				int sum = 0;
				for (int k = 0; k < y; k++)
				{
					sum = sum + arrayA[j][k] * arrayB[k][l];
				}
				arrayC[j][l] = sum;
			}			
		}

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < z; j++)
			{
				cout<<arrayC[i][j] << " ";
			}
			cout << endl;
		}
	}

	instream.close();

	return 0;
}