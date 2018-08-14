/***********************************
*                                  *
*       problem                    *
*             IPV4 주소변환	       *
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

int main()
{
	int num;
	int numcase;
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
		if (numcase == 1)
		{
			int one = 0, two = 0, three = 0, four = 0;
			string k;
			instream >> k;
			int count = 0;
			int number = 0;
			for (int j = k.size() - 1; j >= 0; j--)
			{
				if (k[j] == '.')
					number = 0, count++;
				else
				{
					if (count == 0)
					{
						if (number == 0)
							one += int(k[j] - 48), number++;
						else if (number == 1)
							one += int(k[j] - 48) * 10, number++;
						else if (number == 2)
							one += int(k[j] - 48) * 100, number++;
					}
					else if (count == 1)
					{
						if (number == 0)
							two += int(k[j] - 48), number++;
						else if (number == 1)
							two += int(k[j] - 48) * 10, number++;
						else if (number == 2)
							two += int(k[j] - 48) * 100, number++;
					}
					else if (count == 2)
					{
						if (number == 0)
							three += int(k[j] - 48), number++;
						else if (number == 1)
							three += int(k[j] - 48) * 10, number++;
						else if (number == 2)
							three += int(k[j] - 48) * 100, number++;
					}
					else
					{
						if (number == 0)
							four += int(k[j] - 48), number++;
						else if (number == 1)
							four += int(k[j] - 48) * 10, number++;
						else if (number == 2)
							four += int(k[j] - 48) * 100, number++;
					}
				}
			}
			int hw[100] = { 0, };
			count = 0;
			int mask = 1;
			for (int j = 8; j > 0; j--)
				hw[count] = ((four & (mask << j - 1)) ? 1 : 0), count++;
			for (int j = 8; j > 0; j--)
				hw[count] = ((three & (mask << j - 1)) ? 1 : 0), count++;
			for (int j = 8; j > 0; j--)
				hw[count] = ((two & (mask << j - 1)) ? 1 : 0), count++;
			for (int j = 8; j > 0; j--)
				hw[count] = ((one & (mask << j - 1)) ? 1 : 0), count++;
			unsigned int sum = 0;
			int count2 = 0;
			for (int j = 31; j >=0; j--)
			{
				sum+=pow(2, j)*hw[count2];
				count2++;
			}
			cout << sum << endl;
		}
		else
		{
			unsigned int numtest = 0;
			instream >> numtest;
			int hw[100] = { 0, };
			int hw2[100] = { 0, };
			int hw3[100] = { 0, };
			int hw4[100] = { 0, };
			int count = 0;
			int mask = 1;
			for (int j = 32; j>24; j--)
			{
				hw[count] = ((numtest & (mask << j - 1)) ? 1 : 0);
				count++;
			}
			count = 0;
			for (int j = 24; j>16; j--)
			{
				hw2[count] = ((numtest & (mask << j - 1)) ? 1 : 0);
				count++;
			}
			count = 0;
			for (int j = 16; j>8; j--)
			{
				hw3[count] = ((numtest & (mask << j - 1)) ? 1 : 0);
				count++;
			}
			count = 0;
			for (int j = 8; j>0; j--)
			{
				hw4[count] = ((numtest & (mask << j - 1)) ? 1 : 0);
				count++;
			}
			int one = 0, two = 0, three = 0, four = 0;
			count = 0;
			for (int j = 7; j >=0; j--)
				one+=pow(2, j)*hw[count], count++;
			count = 0;
			for (int j = 7; j >= 0; j--)
				two += pow(2, j)*hw2[count], count++;
			count = 0;
			for (int j = 7; j >= 0; j--)
				three += pow(2, j)*hw3[count], count++;
			count = 0;
			for (int j = 7; j >= 0; j--)
				four += pow(2, j)*hw4[count], count++;
			cout << one << '.' << two << '.' << three<< '.' << four << endl;
		}
	}
	instream.close();

	return 0;
}