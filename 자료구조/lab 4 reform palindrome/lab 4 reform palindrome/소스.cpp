#include <iostream>
#include <cstdlib>
#include<fstream>
#include<string>
#include<vector>
const char stackSize = 100;
char stack[stackSize];
int top;

using namespace std;

void create_stack();
void push(char num);
void displayStack();
int pop();
int isFull();
int isEmpty();


int main()
{
	string num;

	ifstream instream;

	instream.open("input.txt");
	int numcase = 0;
	instream >> numcase;
	for(int i=0;i<numcase;++i)
	{	create_stack();
		int count = 0;
		instream >> num;

		for (int i = 0; i < num.size(); i++)
		{
			if (num[i] == '(' || num[i] == '{' || num[i] == '[')
				push(num[i]);
			else if (num[i] == ')' || num[i] == '}' || num[i] == ']')
			{
				if (num[i] == ')'&&stack[top] == '(')
				{
					pop();
				}
				else if (num[i] == ']'&&stack[top] == '[')
				{
					pop();
				}
				else if (num[i] == '}'&&stack[top] == '{')
				{
					pop();
				}
				else
				{
					count = 1;
					cout << 0 << endl;
					break;
				}
			}
		}
		if ((top != -1) && count == 0)
		{
			cout << 0 << endl;
		}
		else
		{
			if (count == 0)
				cout << 1 << endl;
		}


			//char input[5];

			//while (1)
			//{

			//	cout << "1.Push 2.Pop  3.Displaystack  7.exit \n";
			//	cin >> input;

			//	if (strcmp(input, "1") == 0) //Ǫ��
			//	{
			//		if (!isFull())
			//		{
			//			cout << "Enter an char to push => ";
			//			cin >> num;
			//			push(num);
			//		}
			//		else
			//			cout << "Stack is full!\n";
			//	}

			//	else if (strcmp(input, "2") == 0) //��
			//	{
			//		if (!isEmpty())
			//		{
			//			num = pop();
			//			cout << num << endl;
			//		}
			//		else
			//			cout << "Stack Empty!\n";
			//	}
			//	else if (strcmp(input, "5") == 0) //���÷��̽���
			//		displayStack();


			//	else if (strcmp(input, "7") == 0) //������
			//		exit(0);

			//	else
			//		cout << "Bad Command!\n";
			//}
	
	}


	instream.close();
	return 0;
}

//���� ����
//�Լ� ����
void create_stack() //���� ����
{
	top = -1;
}

void push(char num) //�� �Է�
{
	++top;
	stack[top] = num;
}

int pop()  //���
{
	return stack[top--];
}

int isFull()
{
	if (top == stackSize - 1)
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

void displayStack()  //���� ����
{

	if (isEmpty())
		cout << "Stack is empty!" << endl;
	else
	{
		for (int sp = 0; sp <= top; sp++)
		{
			cout << stack[sp] << " ";
		}
		cout << endl;
	}
}