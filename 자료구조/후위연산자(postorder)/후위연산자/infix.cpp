#include<iostream>
#include "infix.h"
using namespace std;
void infix::create_stack() //���� ����
{
	top = -1;
}
void infix::push(int num) //�� �Է�
{
	++top;
	stack[top] = num;
}
int infix::pop()  //����
{
	return stack[top--];
}
int infix::isFull()//stack�� �����ִ��� Ȯ��
{
	if (top == 99)
		return 1;
	else
		return 0;
}
int infix::isEmpty()//stack�� ����ִ��� Ȯ��
{
	if (top == -1)
		return 1;
	else
		return 0;
}
void infix::hw(int len)//postfix�� ���ش�.
{
	int numcase = 0;
	for (int i = 0; i < len; i++) //������ ���̸�ŭ for���� �����ش�
	{
		if (((int)compare2[i] == 43) || ((int)compare2[i] == 45) || ((int)compare2[i] == 47) || ((int)compare2[i] == 42) || ((int)compare2[i] == 40))//*,/,+,-,(�ϰ�� �۵��ȴ�.
		{
			if ((int)stack[top] == 40)//stack[top]�� (�ϰ�� pop���ְ� ������ ���� push���ش�.
			{
				push(compare2[i]);
			}
			else if ((int)compare2[i] == 40)//�����¼��� (�ϰ�� push
			{
				push(compare2[i]);
			}
			else if (((int)stack[top] == 47) || ((int)stack[top] == 42))//*,/�� ��� stack���ִ°� ������ְ� pop���ش�.
			{
				compare[numcase] =(char) stack[top];//����� �ư�� compare�� ������ �׾��ش�.
				numcase++;
				cout << (char)stack[top] << " "; //������ ���
				pop();//�����ڸ� ������ص� ����
				push(compare2[i]);//������ �����ڸ� stack�� �־��ش�
			}
			else if ((int)stack[top] == 43 || (int)stack[top] == 45)//stack���ִ� �����ڰ� +,-�� ��� 
			{
				if (((int)compare2[i] == 47) || ((int)compare2[i] == 42))//+,-�ϰ�� stack�ױ�
				{
					push(compare2[i]);
				}
				else//����� �ư�� compare�� ������ �׾��ش�. 
				{
					compare[numcase] = (char)stack[top];
					numcase++;
					cout << (char)stack[top] << " ";//������ ���
					pop();//�����ڸ� ������ص� ����
					push(compare2[i]);//������ �����ڸ� stack�� �־��ش�
				}
			}
			else
				push(compare2[i]);//stack�� �־��ش�
		}
		else if (((int)compare2[i] == 41))// )�� ���ð�� ���δ� ������ش�.
		{
			while (int(stack[top])!=40)
			{
				compare[numcase] = (char)stack[top]; //����� ��� compare�� �׾��ش�.
				numcase++;
				cout << (char)stack[top] << " "; //������ ���
				pop();//����
			}
			pop();
		}
		else
		{
			compare[numcase] = (char)compare2[i]; //����� ��� compare�� �׾��ش�.
			numcase++;
			cout << (char)compare2[i] << " ";//���� ���
		}
	}
	while (top > -1)//stack�� ������ �׿������� ���� ������ش�.
	{
		compare[numcase] = (char)stack[top];//����� ��� compare�� �׾��ش�.
		numcase++;
		cout << (char)stack[top] << " ";//������ ���
		pop();//����
	}
}
void infix::hw2(int len)//Result�� ��� ���ش�.
{
	int sum = 0;//����� ���� ���� �����ش�
	int num = 0;//char���� ���ڸ� ��ȯ������ ����
	for (int m = 0; m < len; m++)
	{
		if ((int)compare[m] == 42)//*�� ���
		{
			sum = (((int)stack[top]) * ((int)stack[top - 1])); //������ ������ش�.
			pop();//����� ���� ����
			pop();//����� ���� ����
			push(sum);//����� stack�� ����
		}
		else if ((int)compare[m] == 47)// /�� ���
		{
			sum = (((int)stack[top - 1]) / ((int)stack[top]));//������ ������ش�.
			pop();//����� ���� ����
			pop();//����� ���� ����
			push(sum);//����� stack�� ����
		}
		else if ((int)compare[m] == 43)// +�� ���
		{
			sum = (((int)stack[top- 1]) + ((int)stack[top]));//������ ������ش�.
			pop();//����� ���� ����
			pop();//����� ���� ����
			push(sum);//����� stack�� ����
		}
		else if ((int)compare[m] == 45)// -�� ���
		{
			sum = (((int)stack[top - 1]) - ((int)stack[top]));//������ ������ش�.
			pop();//����� ���� ����
			pop();//����� ���� ����
			push(sum);//����� stack�� ����
		}
		else//���ڰ� ���ð�� stack�� �׾��ش�
		{
			num = (int)compare[m] - 48; //�ƽ�Ű�ڵ尪�� ��ȯ�����ش�.
			push(num);//���ڸ� stack�� ����
		}
	}
	cout << stack[top] << endl; //���������δ� stack�� result���� top�����̱� ������ stack2[top2]�� ������ش�.
	pop();
}
void infix::hw3()//stack,stack2,compare,compare2,top,top2 �ʱ�ȭ���ش�.
{
	for (int k = 0; k < 100; k++)
	{
		stack[k] = 0;
		compare[k] = 0;
		compare2[k] = 0;
	}
	top = -1;
}