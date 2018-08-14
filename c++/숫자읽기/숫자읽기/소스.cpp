/***********************************
*                                  *
*       problem                    *
*             숫자읽기		       *
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
#include<string>
#include<cmath>

using namespace std;


string hw[] = { "X","One","Two","Three","Four","Five","Six","Seven","Eight","Nine" };
string hw2[] = { "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
string hw3[] = { "X","X","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

void hw_function(int num, int &count);
int main()
{
	int num;
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
		int arrayA[4] = { 0, };
		unsigned int numcase;
		instream >> numcase;
		int stack = 0;
		int count = 0;
		while (numcase / 1000 || numcase % 1000)
			arrayA[stack++] = numcase % 1000, numcase /= 1000;

		for (int j = 3; j >=0; j--)
		{
			if (j == 3)
			{
				if (arrayA[j] != 0)
				{
					hw_function(arrayA[j], count);
					cout << "_" << "Billion";
				}
			}
			else if (j == 2)
			{
				if (arrayA[j] != 0)
				{
					hw_function(arrayA[j], count);
					cout << "_" << "Million";
				}
			}
			else if (j == 1)
			{
				if (arrayA[j] != 0)
				{
					hw_function(arrayA[j], count);
					cout << "_" << "Thousand";
				}
			}
			else
				if(arrayA[j]!=0)
				hw_function(arrayA[j], count);
		}
		cout << endl;
	}
	instream.close();

	return 0;
}
void hw_function(int num, int &count)
{
	if (num / 100)
	{
		if (count == 0)count++;
		else cout << "_";

		cout << hw[num / 100] << "_Hundred";
		num %= 100;
	}
	if (num / 10)
	{
		if (count == 0)count++;
		else cout << "_";
		if (num / 10 == 1)
		{
			cout << hw2[num % 10];
		}
		else
		{
			cout << hw3[num / 10];
			if (num % 10)
				cout << "_" << hw[num % 10];
		}
	}
	if (num / 10 == 0 && num % 10)
	{
		if (count == 0)count++;
		else cout << "_";
		cout << hw[num % 10];
	}
}