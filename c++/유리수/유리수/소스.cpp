#include <fstream>
#include <cstdlib>
#include "header.h"

void testSimpleCase();
void testDataFromFile();
int main()
{
	testSimpleCase();
	testDataFromFile();
}
void testSimpleCase()
{
	myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
	std::cout << frac1 << " " << frac2 << " " << frac3 << " " << frac4 << " " << frac5 << std::endl;
	std::cout << frac1.getNumerator() << " " << frac1.getDenominator() << std::endl;
	// Check arithmetic operators
	std::cout << frac1 * frac2 << " " << frac1 + frac3 << " " << frac2 - frac1 << " " << frac3 / frac2 << std::endl;
	// Check comparison operators
	std::cout << ((frac1 < frac2) ? 1 : 0) << " " << ((frac1 <= frac2) ? 1 : 0) << " " << ((frac1 > frac2) ? 1 : 0) << " " << ((frac1 >= frac2) ? 1 : 0) << " "
		<< ((frac1 == frac2) ? 1 : 0) << " "
		<< ((frac1 != frac2) ? 1 : 0) << " "
		<< ((frac2 < frac3) ? 1 : 0) << " "
		<< ((frac2 <= frac3) ? 1 : 0) << " "
		<< ((frac2 > frac3) ? 1 : 0) << " "
		<< ((frac2 >= frac3) ? 1 : 0) << " "
		<< ((frac2 == frac3) ? 1 : 0) << " "
		<< ((frac2 != frac3) ? 1 : 0) << std::endl;
	std::cout << (frac6 = frac3) << " ";
	std::cout << (frac6 += frac3) << " ";
	std::cout << (frac6 -= frac3) << " ";
	std::cout << (frac6 *= frac3) << " ";
	std::cout << (frac6 /= frac3) << std::endl;
	std::cout << -frac6 << std::endl;
	frac6 = (++frac4) + 2;
	frac7 = 2 + (frac4++);
	std::cout << frac4 << " " << frac6 << " " << frac7 << std::endl;
	frac6 = (--frac4) - 2;
	frac7 = 2 - (frac4--);
	std::cout << frac4 << " " << frac6 << " " << frac7 << std::endl;
	std::cout << 2 * frac3 << " " << frac3 * 2 << " " << 2 / frac3 << " " << frac3 / 2 << std::endl;
}
void testDataFromFile()
{
	std::ifstream instream;
	int num;
	instream.open("input.txt");
	
	instream >> num;

	for (int i = 0; i < num; ++i)
	{
		int numcase;
		instream >> numcase;
		myRational hw[100];
		for (int j = 0; j < numcase; ++j)
		{
			int x, y;
			instream >> x >> y;
			myRational m(x, y);
			hw[j] = m;
		}
		for (int i = 0; i < numcase - 1; ++i) 
		{
			for (int j = 0; j < numcase - i - 1; ++j) 
			{
				myRational temp;
				if (hw[j] > hw[j + 1]) 
				{
					temp = hw[j];
					hw[j] = hw[j + 1];
					hw[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < numcase; ++i)
			std::cout << hw[i] << " ";
		std::cout << std::endl;
	}
	instream.close();
}
