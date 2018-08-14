#include <iostream>
#include <cstdlib>
#include<string>
#include<vector>
int stack[100];
int top;

using namespace std;

void create_stack();
void push(int num);
void displayStack();
int pop();
int isFull();
int isEmpty();
int main()
{
	create_stack;
	string input;
	vector<char>input2;
	input = "5-(4+3)*6/2";
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			input2.push_back(input[i]);
		}
		else if (input[i] == '*' || input[i] == '/')
		{
			if (input2.size() > 1&&(input2[input2.size() - 1] == '/' || input2[input2.size() - 1] == '*'))
			{
				cout << input2[input2.size() - 1];
				input2.pop_back();
				input2.push_back(input[i]);
			}
			else
				input2.push_back(input[i]);
		}
		else if (input[i] == '+' || input[i] == '-')
		{
			if (input2.size() > 1 && input2[input2.size()-1]!='(')
			{
				cout << input2[input2.size() - 1];
				input2.pop_back();
				input2.push_back(input[i]);
			}
			else
				input2.push_back(input[i]);
		}
		else if (input[i] == ')')
		{
			while (input2[input2.size() - 1] != '(')
			{
				cout << input2[input2.size() - 1];
				input2.pop_back();
			}
			input2.pop_back();
		}
		else
		{
			cout << input[i];
		}
		if (i == input.size() - 1)
		{
			for (; input2.size()>0; )
			{
				cout << input2[input2.size() - 1];
				input2.pop_back();
			}
		}
	}
	cout << endl;
	return 0;
}
void create_stack()
{
	top = -1;
}

void push(int num) //값 입력
{
	++top;
	stack[top] = num;
}

int pop()  //출력
{
	return stack[top--];
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

void displayStack()  //스택 나열
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