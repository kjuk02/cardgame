#include<iostream>
#include<fstream>
using namespace std;
int top;
char buffer[80];
char stack[80];
void push(int);
int pop();
void create_stack();
int isEmpty();
void compare(char buffer[],char stack[], int k);
int main()
{
	int len;
	ifstream instream;
	char C;
	instream.open("input.txt");

	if (instream.fail())
	{
		cerr << "input file openning error " << endl;
		exit(1);
	}
	ifstream input;

	while (!instream.eof())
	{
		instream.get(C);
		while (input.getline(buffer, 80))
		{ //�� line�� ó����
			len = strlen(buffer);
			int k = 0;
			if (len % 2 == 0)
			{
				for (int i = 0; i < (len / 2); i++) //length�� �ݸ�ŭ PUSH. ��abccba�� �� ��� push a, push b, push c.
					push(buffer[i]);
			}
			else
			{
				for (int i = 0; i < (len / 2); i++) //length�� �ݸ�ŭ PUSH. ��abckcba���� ��� push a, push b, push c.
					push(buffer[i]); // ���� buffer �� kcba ������

				k++;// k�� �ǳ�1 �ڴ�.
			}
			
			while (buffer[k] != '\0')
			{
				compare(buffer, stack, k);
				if (isEmpty())
					cout << "PALINDROME" << endl;
				k++;
			}
		}
		if(C ==' ')
			break;
	}


}
void compare(char buffer[],char stack[], int k)
{
	if (buffer[k] == stack[k])
		cout << buffer[k] << endl;
}
int isEmpty()
{
	if (top == 79)
		return 1;
	else 
		return 0;
}
void push(int num)
{
	++top;
	stack[top] = num;
}
int pop()
{
	return (stack[top--]);
}
void create_stack()
{
	top = -1;
}