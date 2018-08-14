#include <iostream>
#include <cstring>
#include <cstdlib>
#include<string>
char stack[100];
char stack2[100] = { 0, };
char compare[100];
char compare2[100];
int top;
int top2;
using namespace std;

void create_stack();
void push(int num);
int isFull();
void hw(int len);

int pop();
void create_stack2();
void push2(int num);
int isFull2();
void hw2(char compare3[], int len);
int main()
{
	char num;
	char input[5];
	int len = 0;
	char compare3[100];
	create_stack();
	create_stack2();
	

	while (1)
	{

		cout << "1.���� ���� �Է� 2.��ȣ ���� �Է� 3.���� ���ϱ� 4.��ȣ ���� ���ϱ� 5.exit \n";
		cin >> input;
		cout << endl;
		if (strcmp(input, "1") == 0) //Ǫ��
		{
			if (!isFull())
			{
				cout << "���ϰ���� ������ �Է��Ͻÿ�.=> ";
				cin >> compare;
				len = strlen(compare);

				for (int i = 0; i < len / 2; i++)
					push(compare[i]);

				cout << endl;
			}
			else
				cout << "Stack is full!\n";
		}
		else if (strcmp(input, "2") == 0)
		{
			if (!isFull2())
			{
				cout << "���ϰ���� ������ �Է��Ͻÿ�.=> ";
						cin >> compare3;
			}
			else
				cout << "Stack is full!\n";
		}
		else if (strcmp(input, "3") == 0)
			hw(len);
		else if (strcmp(input, "4") == 0)
		{
			len = strlen(compare3);
			hw2(compare3, len);
			cout << endl;
		}
		else if (strcmp(input, "5") == 0) //������
			exit(0);

		else
			cout << "Bad Command!\n";
	}




	return 0;
}

//���� ����
//�Լ� ����
void create_stack() //���� ����
{
	top = -1;
}
void create_stack2()
{
	top2 = -1;
}
void push(int num) //�� �Է�
{
	++top;
	stack[top] = num;
}
int pop()
{
	return (stack2[top2--]);
}
void push2(int num) //�� �Է�
{
	++top2;
	stack2[top2] = num;
}
int isFull()
{
	if (top == 99)
		return 1;
	else
		return 0;
}
int isFull2()
{
	if (top2 == 99)
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
int isEmpty2()
{
	if (top2== -1)
		return 1;
	else
		return 0;
}
void hw(int len)
{
	int number = 0;

	if (len % 2 == 0)
	{
		number = len - 1;
		for (int i = 0; i < len / 2; i++)
		{
			int a = (int)stack[i];
			int b = (int)compare[number];

			if (a == b)
				number--;
			else
			{
				cout << "not a palindrome" << endl;
				for (int k = 0; k<100; k++)
					stack[k] = 0;
				top = -1;
				break;
			}
		}
		if (number == len / 2 - 1)
		{
			cout << "a palindrome" << endl;
			for(int k=0; k<100;k++)
				stack[k] = 0;
			top = -1;
		}
	}
	else
	{
		number = len - 1;
		for (int i = 0; i < len / 2; i++)
		{
			int a = (int)stack[i];
			int b = (int)compare[number];
			if (a == b)
				number--;
			else
			{
				cout << "not a palindrome" << endl;
				for (int k = 0; k<100; k++)
					stack[k] = 0;
				top = -1;
				break;
			}
		}
		if (number == len / 2)
		{
			cout << "a palindrome" << endl;
			for (int k = 0; k<100; k++)
				stack[k] = 0;
			top = -1;
		}
	}

}
void hw2(char compare3[],int len)
{
	int number = 0;
	for (int i = 0; i < len; i++)
	{
		if (((int)compare3[i] == 123) || ((int)compare3[i] == 125) || ((int)compare3[i] == 91) || ((int)compare3[i] == 93) || ((int)compare3[i] == 40) || ((int)compare3[i] == 41))
		{
			compare2[number] = compare3[i];
			number++;
		}
	}
	int j;
	int len2 = strlen(compare2);
	for (j = 0; j < len2; j++)
	{
		if (((int)compare2[j] == 123) || ((int)compare2[j] == 40) || ((int)compare2[j] == 91))
			push2(compare2[j]);
		else
		{
			if (((int)stack2[top2] == 123) && ((int)compare2[j] == 125))
			{
				pop();
				continue;
			}
			else if (((int)stack2[top2] == 40) && ((int)compare2[j] == 41))
			{
				pop();
				continue;
			}
			else if (((int)stack2[top2] == 91) && ((int)compare2[j] == 93))
			{
				pop();
				continue;
			}
			else
			{
				cout << "unbalance" << endl;
				for (int k = 0; k < 100; k++)
				{
					stack2[k] = 0;
					compare2[k] = 0;
				}
				top2 = -1;
				break;
			}
		}
	}
	if (top2 != -1 && ((int)stack2[top2] != 0))
	{
		cout << "unbalance" << endl;
		for (int k = 0; k < 100; k++)
		{
			stack2[k] = 0;
			compare2[k] = 0;
		}
		top2 = -1;

	}
	else if (j == len2)
	{
		cout << "balance" << endl;
		for (int k = 0; k < 100; k++)
		{
			stack2[k] = 0;
			compare2[k] = 0;
		}
		top2 = -1;
	}

}