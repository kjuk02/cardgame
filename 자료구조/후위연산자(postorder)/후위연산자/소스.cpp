#include <iostream> //ǥ�� ���̺귯���� �ϳ��� ������Լ��� �������� header file
#include "infix.h" //class�� �������� header file

using namespace std;

int main()
{
	infix infix2;//class ����
	char num;
	char input[5];
	infix2.create_stack(); //���� ����
	int len = 0; //���� ���
	while (1)
	{
		cout << "1.����� ���� �־��ּ���. 2.������ \n";
		cin >> input;
		if (strcmp(input, "1") == 0) //Ǫ��
		{
			infix2.hw3(); //stack,stack2,compare,compare2 �ʱ�ȭ
			cout << "0) Enter data :";
			cin >> infix2.compare2; //postfix �� ������ �޾ƿ´�
			cout << "1) Echo data(infix form) :" << " ";
			cout << infix2.compare2 << endl;
			len = strlen(infix2.compare2);//������ ���̸� �����Ѵ�.
			cout << "2) Conversion (postfix form) :" << " ";
			infix2.hw(len);//postfix ������ �־ ���� ���ش�
			cout << endl;
			len = strlen(infix2.compare);//������ Result�ϱ����� ���̸� �������ش�
			cout << "3) Result :" << " ";
			infix2.hw2(len);//Result ���� ����Ͽ��ݴϴ�.
		}
		else if (strcmp(input, "2") == 0) //������
			exit(0);

		else
			cout << "Bad Command!\n"; //��ɾ �ùٸ����ʽ��ϴ�.
	}
	return 0;
}