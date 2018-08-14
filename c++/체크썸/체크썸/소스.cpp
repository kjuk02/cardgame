/***********************************
*                                  *
*       problem                    *
*                üũ ��	       *
*                                  *
*                                  *
***********************************/

/************************************
*                                   *
*       ����Ʈ�����к�              *
*                20143050           *
*                        ������     *
*                                   *
************************************/
#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
using namespace std;

int main()
{
	int num;
	unsigned int numcase;
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
		unsigned int sum = 0, sum2 = 0, sum3 = 0, sum4 = 0;
		int mask = 1;
		int number = 0, number2 = 0, number3 = 0, number4 = 0;
		unsigned int last = 0;
		for (int j = 32; j > 24; j--)//������
		{
			if(((numcase & (mask << j - 1)) ? 1 : 0)==1)
			sum += pow(2, 7-number);
			number++;
		}
		for (int j = 24; j > 16; j--)//������
		{
			if (((numcase & (mask << j - 1)) ? 1 : 0) == 1)
			sum2 += pow(2, 7-number2);
			number2++;
		}
		for (int j = 16; j > 8; j--)//�ι���
		{
			if (((numcase & (mask << j - 1)) ? 1 : 0) == 1)
				sum3 += pow(2, 7-number3);
			number3++;
		}
		last = sum + sum2 + sum3;
		
		while (last >= 256)
			last -= 256;

		last =255-last;

		for (int j = 8; j > 0; j--)//ù��°
		{
			if (((numcase & (mask << j - 1)) ? 1 : 0) == 1)
				sum4 += pow(2, 7 -number4 );
			number4++;
		}
		if (last == sum4)
		cout << 1 << endl;
		else
		cout << 0 << endl;
	}
	instream.close();
	return 0;
}