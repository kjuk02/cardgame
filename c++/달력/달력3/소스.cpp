/*******************************************************************************
*                                                                              *
*       problem.     �޷� ����ϱ�                                             *
*                                                                              *
*******************************************************************************/
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(void)
{
	ifstream inStream;
	int NumTestCase;

	inStream.open("input.txt");  //intput���� �ҷ�����
	if (inStream.fail())
	{
		cerr << "Input file opening failed." << endl;
		exit(1);
	}
	inStream >> NumTestCase;
	for (int a = 0; a<NumTestCase; a++)
	{
		int Y, M;     //year,month,date
		inStream >> Y >> M;
		int year = 0, month = 0, sum = 4, FirstD;
		int CommonY[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };   //���
		int LeapY[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };   //����

		for (int i = 1582; i<Y; i++)
		{
			if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)   //����
			{
				year += 366;
			}
			else
				year += 365;
		}
		for (int j = 0; j<M - 1; j++)
		{
			if (Y % 4 == 0 && Y % 100 != 0 || Y % 400 == 0)
			{
				month += LeapY[j];
			}
			else
				month += CommonY[j];
		}
		sum += (year + month);
		FirstD = sum % 7;           //ù��° ����
		int lastD;                //������ ����
		cout << Y << " " << M << endl;
		if (FirstD != 6)                       //ù���� ������ �Ͽ����̸� 0�� ����� �ʿ䰡 ���⶧��
		{
			for (int i = 0; i <= FirstD; i++)
			{
				cout << "0 ";
			}
		}
		if ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0)  //����
		{
			int lastday = LeapY[M - 1];
			lastD = (sum + lastday) % 7;

			for (int j = 1; j <= lastday; j++)
			{
				cout << j << " ";
				if ((FirstD + j + 1) % 7 == 0)          //�������� �Ǹ� �ٹٲ�
				{
					cout << endl;
				}
			}
			if (lastD<6)        //������ ���Ϸκ��� 0�� ����ϱ� ����
			{
				for (int k = 0; k<(6 - lastD); k++)
				{
					cout << "0 ";
				}
				cout << endl;
			}
			
		}
		else
		{
			int lastday = CommonY[M - 1];
			lastD = (sum + lastday) % 7;
			for (int j = 1; j <= lastday; j++)
			{
				cout << j << " ";
				if ((FirstD + j + 1) % 7 == 0)   //�������� �Ǹ� �ٹٲ�
				{
					cout << endl;
				}
			}
			if (Y % 4 == 0 && Y % 100 != 0 || Y % 400 == 0)  //����
			{
				if (lastD<6)    //������ ���Ϸκ��� 0�� ����ϱ� ����
				{
					for (int k = 0; k<(6 - lastD); k++)
					{
						cout << "0 ";
					}
					cout << endl;
				}
			}
			else
			{
				if (M == 2 && FirstD == 0)
				{
					if (lastD<6)    //������ ���Ϸκ��� 0�� ����ϱ� ����
					{
						for (int k = 0; k<(6 - lastD); k++)
						{
							cout << "0 ";
						}
					}
				}
				else
				{
					if (lastD<6)    //������ ���Ϸκ��� 0�� ����ϱ� ����
					{
						for (int k = 0; k<(6 - lastD); k++)
						{
							cout << "0 ";
						}
						cout << endl;
					}

				}
			}
		}
	}
	inStream.close();
	return 0;
}
