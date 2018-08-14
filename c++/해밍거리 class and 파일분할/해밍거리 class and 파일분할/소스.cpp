/* 20163150 2학년 이희지 <해밍거리> */
#include <iostream>
#include <fstream>
#include <cmath>
#include<algorithm>

class ham {
private:
	int num1 = 0;
	int num2 = 0;
	int cnt1 = 0; //무게
	int cnt2 = 0; //배열 길이
	int cnt3 = 0; //배열 길이
	unsigned int arr1[10000] = { 0 };
	unsigned int arr2[10000] = { 0 };
	int i = 0;
public:
	ham(int num_1, int num_2) :num1(num_1), num2(num_2) {}
	void hw();
};

using namespace std;
int main(void)
{
	ifstream inStream;
	inStream.open("input.txt");

	int numTestcase;
	inStream >> numTestcase;

	for (int j = 0; j<numTestcase; j++)
	{
		int num1 = 0;
		int num2 = 0;
		inStream >> num1 >> num2;
		ham hizi(num1, num2);
		hizi.hw();
	}
}


void ham::hw()
{
	while (num1 != 0)
	{
		arr1[i] = num1 % 2;
		if (num1 % 2 == 1)
		{
			cnt1++;
		}
		num1 = num1 / 2;
		cnt2++;
		i++;

	}
	cout << cnt1 << " ";

	i = 0; cnt1 = 0;
	while (num2 != 0)
	{
		arr2[i] = num2 % 2;
		if (num2 % 2 == 1)
		{
			cnt1++;
		}
		num2 = num2 / 2;
		cnt3++;
		i++;
	}
	cout << cnt1 << " ";


	int distance = 0;
	cnt2 = (cnt2>cnt3 ? cnt2 : cnt3);
	for (int i = 0; i<cnt2; i++)
	{
		if (arr1[i] != arr2[i])
		{
			distance++;
		}
	}
	cout << distance << endl;

}