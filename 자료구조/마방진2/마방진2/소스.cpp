#include<iostream>

using namespace std;
int input();//ũ�� �Է¹ް� Ȧ������ �Ǻ�
void hw1(int arrayA[][500], int num); //���� �Ǻ�
void hw2(int arrayA[][500], int num); //�Լ� ���
int main()
{
	int arrayA[500][500]; //��� �־��� �迭 ����
	int num = 0; //ũ�� �Է¹޴� ����
	num = input(); //���� �Է� �� Ȧ��Ȯ��
	hw1(arrayA, num);//���� �Ǻ�
	hw2(arrayA, num);//�Լ����
}
int input()//ũ�� �Է¹ް� Ȧ������ �Ǻ�
{
	int numcase;
	while (1)
	{
		cout << "���ϴ� Ȧ�������������� ũ�⸦ �Է��Ͻÿ�" << endl;
		cin >> numcase;
		if (numcase % 2 == 0 || numcase < 0)
		{
			cout << "������ ¦���� �ƴѼ��� �Է��Ͻÿ�" << endl;
			cout << endl;
		}
		else
			break;
	}
	return numcase;
}
void hw1(int arrayA[][500], int num)//���� �Ǻ�
{
	int x = 0, y;//�ʱ�ȭ 
	y = num / 2; // y�� ��ó�� ���� �߰�������

	for (int i = 1; i <= num*num; i++)
	{
		arrayA[x][y] = i;

		if (i%num == 0) //�ٸ����� �������
			x = x + 1;
		else//���ʻ������ �̵�
			x = x - 1, y = y - 1;
		if (x < 0)//���� �ʰ��Ҷ� 
			x = num - 1;
		if (y < 0)//���� �ʰ��ҋ�
			y = num - 1;
	}
}
void hw2(int arrayA[][500], int num)//�Լ� ���
{
	cout << endl;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
			cout << arrayA[i][j] << "\t";

		cout << endl;
	}
	cout << endl;
}