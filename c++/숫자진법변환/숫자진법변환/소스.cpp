/***********************************
*                                  *
*       problem                    *
*         숫자의 진법 변환	       *
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
#include<string>
#include<vector>
#include<cstdlib>
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
		string input;
		unsigned int numcase,port = 0, output, k = 0;
		char result[127] = { 0, };
		instream >> numcase>>input>>output;
		for (int i = 0; i < input.size(); i++)
		{
			if('a'<=input.at(i)&&input.at(i)<='f')
				port += pow(numcase, input.size() - 1 - i)*(int(input.at(i))-87);
			else
				port += pow(numcase, input.size() - 1 - i)*(int(input.at(i))-48);
		}
		while (port >= output)
		{
			result[k++] = port%output;
			port /= output;
		}
		result[k] = port;
		for (int m =k; m>=0; m--)
		{
			if (result[m] > 9)
				cout << char(result[m] + 87);
			else
				cout <<char(result[m]+48);
		}
		cout << endl;
	}
	instream.close();
	return 0;
}