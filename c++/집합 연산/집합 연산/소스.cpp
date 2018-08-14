/***********************************
*                                  *
*       problem                    *
*                집합 연산	       *
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
	int num, numcase, numcases, numcases2;
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
		unsigned int arrayA[1000] = {};
		unsigned int arrayB[1000] = {};

		instream >> numcases;
		for (int j = 0; j < numcases; j++)
			instream >> arrayA[j];
		instream >> numcases2;
		for (int j = 0; j < numcases2; j++)
			instream >> arrayB[j];

		unsigned int arrayC[1000] = {0};//첫번째줄
		unsigned int arrayC2[1000] = {0};//두번째줄
		unsigned int arrayC3[1000] = { 0 };//세번쨰줄
		int csr = 0, count1 = 0;//첫번째줄
		int csr2 = 0, count2 = 0;//두번째줄
		int csr3 = 0, count3 = 0;//세번쨰줄
		sort(arrayA, arrayA + numcases);
		sort(arrayB, arrayB + numcases2);
		if (numcases > numcases2)
		{
			for (int j = 0; j < numcases; j++)
				for (int k = 0; k < numcases2; k++)
					if (arrayA[j] == arrayB[k])
					{
						arrayC[csr] = arrayA[j];
						csr++;
						count1++;
					}
		}
		else
		{
			for (int j = 0; j < numcases2; j++)
				for (int k = 0; k < numcases; k++)
					if (arrayA[k] == arrayB[j])
					{
						arrayC[csr] = arrayB[j];
						csr++;
						count1++;
					}
		}
		sort(arrayC, arrayC + csr);
		cout << count1 << " ";
		for (int k = 0; k < csr; k++)
			cout << arrayC[k] << " ";
			
		cout << endl;
		int compare = 0;
		for (int t = 0; t < numcases; t++)
			arrayC2[csr2] = arrayA[t], csr2++, count2++;
		if (csr != 0)
		{
			for (int t = 0; t < numcases2; t++)
			{
				compare = 0;
				for (int m = 0; m < csr; m++)
				{
					if (arrayB[t] != arrayC[m])
					{
						if ((m == (csr - 1)) && compare == 0)
							arrayC2[csr2] = arrayB[t], csr2++, count2++;
					}
					else
						compare++;
				}
			}
		}
		else
		{
			for (int k = 0; k < numcases2; k++)
				arrayC2[csr2] = arrayB[k], csr2++, count2++;
		}
		sort(arrayC2, arrayC2 + count2);

		cout << count2 << " ";

		for (int h = 0; h < count2; h++)
			cout << arrayC2[h] << " ";
		
		cout << endl;
		if (count1 != 0)
		{
			for (int t = 0; t < numcases; t++)
			{
				compare = 0;
				for (int u = 0; u < csr; u++)
				{
					if (arrayA[t] != arrayC[u])
					{
						if (u == csr - 1 && compare == 0)
							arrayC3[csr3] = arrayA[t], csr3++, count3++;
					}
					else
						compare++;
				}
			}
			sort(arrayC3, arrayC3 + csr3);
			cout << count3 << " ";
			for (int p = 0; p < csr3; p++)
				cout << arrayC3[p] << " ";
		}
		else
		{
			cout << numcases << " ";
			for (int i = 0; i < numcases; i++)
				cout << arrayA[i] << " ";
		}
		cout << endl;
	}
	instream.close();

	return 0;
}