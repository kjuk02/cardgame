/***********************************
*                                  *
*       problem                    *
*             모르스부호	       *
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
		string numcase;
		string input[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
		instream >> numcase;
		string k;
		for (int j = 0; j < numcase.size(); j++)
		{
			if (numcase[j] != '|' && numcase[j] != '#')
			{
				if (numcase[j] != '#')
					k += numcase[j];
			}
			else if (numcase[j] == '#')
			{
				for (int m = 0; m < 26; m++)
					if (input[m] == k)
					{
						cout << char(m + 65);
						k.clear();
						cout << '_';
						break;
					}
			}
			else
			{
				for (int m = 0; m < 26; m++)
					if (input[m] == k)
					{
						cout << char(m + 65);
						k.clear();
						break;
					}
			}
		}
		if (k.size() != 0)
			for (int m = 0; m < 26; m++)
				if (input[m] == k)
				{
					cout << char(m + 65);
					break;
				}
		cout << endl;
	}
	instream.close();

	return 0;
}