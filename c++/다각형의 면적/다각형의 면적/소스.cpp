/***********************************
*                                  *
*       problem                    *
*                다각형의 면적     *
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
using namespace std;

int main()
{
	int num, numcase,testcaseX,testcaseY;
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
		int sum = 0;
		int x[1000], y[1000];

		for (int j = 0; j < numcase; j++)
		{
			instream >> x[j] >> y[j];
		}
		for (int k = 0; k < numcase-1; k++)
		{
			sum += ((x[k] + x[k + 1])*(y[k + 1] - y[k]));
		}
		sum += ((x[numcase-1] + x[0])*(y[0] - y[numcase-1]));
		if (sum > 0)
			cout << sum << " " << 1 << endl;
		else
			cout << -sum << " " << -1 << endl;
	}
	instream.close();
	return 0;
}