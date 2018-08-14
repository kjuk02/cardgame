/*********************************************************
* Name: ������
* Student ID : 20143050
* Program ID : Homework2
* Description: 
* Algorithm : �˰����� ������ ��
*
* Variables : ����� �Լ��� �� ����� ������ ��
* x : ��.
**********************************************************/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include<string>
char stack[100];
char compare[100];
int top;

using namespace std;

void create_stack();
void push(int num);
void displayStack();
int isFull();
void hw(int len);
int main()
{
	char num;
	char input[5];
	int len = 0;
	create_stack();

	while (1)
	{

		cout << "1.���� �Է� 2.���� ���ϱ� 3.exit \n";
		cin >> input;
		cout << endl;

		if (strcmp(input, "1") == 0)
		{
			if (!isFull())
			{
				cout << "���ϰ���� ������ �Է��Ͻÿ�.=> ";
				cin >> compare;
				len = strlen(compare);
				for (int i = 0; i < len; i++)
				{
					if (((int)compare[i] == 123) || ((int)compare[i] == 125) || ((int)compare[i] == 91) || ((int)compare[i] == 93) || ((int)compare == 40) || ((int)compare == 41))
					{
						push(compare[i]);
					}
				}
				cout << endl;
			}
			else
				cout << "Stack is full!\n";
		}
		else if (strcmp(input, "2") == 0)
			hw(len);
		else if (strcmp(input, "3") == 0) //������
			exit(0);

		else
			cout << "Bad Command!\n";
	}
	return 0;
}

//���� ����
//�Լ� ����
void create_stack()
{
	top = -1;
}
void push(int num) //�� �Է�
{
	++top;
	stack[top] = num;
}
int isFull()
{
	if (top == 99)
		return 1;
	else
		return 0;
}
int isEmpty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}
void hw(int len)
{
	int number = 0;
	int number2 = 0;
	int number3 = 0;
	for (int i = 0; i < len; i++)
	{
		if (((int)compare[i] == 123) || ((int)compare[i] == 125))
			number++;
		else if (((int)compare[i] == 91) || ((int)compare[i] == 93))
			number2++;
		else if (((int)compare[i] == 40) || ((int)compare[i] == 41))
			number3++;
	}
	if ((number % 2 == 0) && (number2 % 2 == 0) && (number3 % 2 == 0))
	{
		cout << "balanced" << endl;
		for (int k = 0; k < 100; k++)
			stack[k] = 0;
		top = -1;
	}
	else
	{
		cout << "unbalanced" << endl;
		for (int k = 0; k<100; k++)
			stack[k] = 0;
		top = -1;
	}
}