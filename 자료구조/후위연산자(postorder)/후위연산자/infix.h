#include<iostream>

class infix {
private:
	int stack[100];//*,/,+,-�� �����ڵ��� �־��ݴϴ�.
	int top;//stack�� ������� �ε����� top�̴�.
public:
	char compare2[100];//Echo data�� ������ �� �־��ش�.
	char compare[100];//postfix�� ������ �� �־��ش�.

	void create_stack();//���� ����
	void push(int num);//���ÿ� num�� �־��ش�.
	int pop();//���ÿ��ִ� �ε����� �������ش�.
	int isFull();//������ ���ִ��� Ȯ���ϴ�.
	int isEmpty();//������ ������ Ȯ���Ѵ�.

	void hw(int len);//postfix�� ���ش�.
	void hw2(int len);//Result�� ��� ���ش�.
	void hw3();//stack,compare,compare2,top �ʱ�ȭ���ش�.
};