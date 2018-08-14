#include <iostream>
#include <fstream>
#include <cstdlib>
#include<string>
#include"header.h"
using namespace std;
int main()
{
	ifstream inStream;
	int numTestCases;
	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}
	inStream >> numTestCases;
	for (int i = 0; i<numTestCases; i++)
	{
		string clock;
		int lap;
		inStream >> clock >> lap;
		MyDigitalClock digitalClock(clock);
		for (int j = 0; j<abs(lap); j++)
			if (lap > 0)
				digitalClock++;
			else
				--digitalClock;
		cout << digitalClock;
	}
	inStream.close();
	return 0;
}