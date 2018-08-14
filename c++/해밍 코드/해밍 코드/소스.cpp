/***********************************
*                                  *
*       problem                    *
*               해밍 코드	       *
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
#include<cmath>
using namespace std;

void hw1(int ham[]);
void hw3(int ham[], int ham2[]);
void hw1print(int ham[]);
void print(int ham[]);
int main()
{
	int num;
	int choice;
	int numcase;
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
		instream >> choice >> numcase;
		int bit = numcase;
		int mask = 1;
		int ham[100] = { 0, };
		int ham2[100] = { 0, };
		int count = 0;
		if (choice ==0)
		{
			for (int j = 0; j < 31; j++)
			{
				while (count==0||count ==1|| count == 3 ||count==7||count==15)
					count += 1;
				ham[count++] = ((bit & (mask << j)) ? 1 : 0);
			}
			hw1(ham);
			hw1print(ham);
		}
		else
		{
			for (int j = 0; j < 32; j++)
			{
				ham[count] = ((bit & (mask << j)) ? 1 : 0);
				ham2[count] = ham[count];

				count++;
			}
		
			hw1(ham2);
			hw3(ham, ham2);
		}
	}
	instream.close();

	return 0;
}
void print(int ham[])
{
	int sum = 0;
	int i = 0;
	for (int count = 0; count < 31; count++ )
	{
		if (count != 0 && count != 1 && count != 3 && count != 7 && count != 15)	
		{
			if (ham[count] == 1)
				sum += pow(2, i);
			i++;
		}
	}
	cout << sum << endl;
}
void hw3(int ham[], int ham2[])
{
	if (ham[0] != ham2[0] || ham[1] != ham2[1] || ham[3] != ham2[3] || ham[7] != ham2[7] || ham[15] != ham2[15])
	{
		int result = 0;
		if (ham[0] != ham2[0])
			result = result + 1;
		if (ham[1] != ham2[1])
			result = result + 2;
		if (ham[3] != ham2[3])
			result = result + 4;
		if (ham[7] != ham2[7])
			result = result + 8;
		if (ham[1] != ham2[1])
			result = result + 16;
			
		if (ham[result] == 0)
			ham[result-1] = 1;
		else
			ham[result-1] = 0;
		print(ham);
	}
	else
		print(ham);
}
void hw1(int ham[])
{
	int hw = 0;
	hw = 0;
	for (int k = 16; k < 31; k++)
	{
		if (ham[k] == 1)
			hw++;
	}
	if (hw % 2 != 0)
		hw = 1;
	else
		hw = 0;
	ham[15] = hw;


	hw = 0;
	for (int k = 8; k < 31; k++)
	{
		if (ham[k] == 1)
			hw++;
		if ((k + 2) % 8 == 0)
			k = k + 8;
	}
	if (hw % 2 != 0)
		hw = 1;
	else
		hw = 0;
	ham[7] = hw;

	hw = 0;
	for (int k = 4; k < 31; k++)
	{
		if (ham[k] == 1)
			hw++;
		if ((k + 2) % 4 == 0)
			k = k + 4;
	}
	if (hw % 2 != 0)
		hw = 1;
	else
		hw = 0;
	ham[3] = hw;

	hw = 0;
	for (int k = 2; k < 31; k++)
	{
		if (ham[k] == 1)
			hw++;
		if ((k + 2) % 2 == 0)
			k = k + 2;
	}
	if (hw % 2 != 0)
		hw = 1;
	else
		hw = 0;
	ham[1] = hw;

	hw = 0;

	for (int k = 2; k < 31; k = k + 2)
	{
		if (ham[k] == 1)
			hw++;
	}
	if (hw % 2 != 0)
		hw = 1;
	else
		hw = 0;
	ham[0] = hw;
}
void hw1print(int ham[])
{
	int sum = 0;
	for (int j = 0; j < 31; j++)
		if (ham[j] == 1)
			sum += pow(2, j);

	cout << sum << endl;
}