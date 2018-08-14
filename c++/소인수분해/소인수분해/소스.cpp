#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(void) {
	ifstream inStream;
	inStream.open("input.txt");
	if (inStream.fail()) exit(1);

	int num_cases;
	inStream >> num_cases;

	for (int i = 0; i<num_cases; i++) 
	{
		unsigned int number, temp;
		inStream >> number;
		unsigned int fact[10000] = { 0 };
		int count[10000] = { 0 };
		temp = number;

		int j = 2;
		int c=0;
		int scount = 1;
		for(int j=2;j<=temp;)
		{
				if (temp%j == 0)
				{
					temp /= j;
					fact[j]++;
				}
				else
				{
					j++;
					c = 0;
				}
				scount++;
		}
		int sum = 0;
		for (int k = 0; k <= scount; k++)
			if (fact[k] != 0)
				sum++;
		cout <<sum << " ";
		for (int k = 0; k <=scount; k++) {
			if (fact[k] != 0) cout <<k << " " << fact[k] << " ";

		}
		cout << endl;
	}
	inStream.close();
	return 0;
}
