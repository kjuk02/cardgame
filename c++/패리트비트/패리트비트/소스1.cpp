#include<iostream>

int main()
{
	int num; //����
	int mask = 1; //�񱳽� ����� ����
	int i; //for������ ����� ����2

	std::cout << "������ ������ �Է��Ͻÿ�:" << std::endl;
	std::cin >> num;
	std::cout << "�Է��� ���� ���� ���� ǥ��(������)�� ������ �����ϴ�.\n\n\t"<<std::endl;

	for (i = 32; i>0; i--)  //for��
	{
		if (i % 8)
			std::cout << " " << std::endl;
		std::cout << ((num & (mask << i - 1)) ? 1 : 0) << std::endl;
	}
}