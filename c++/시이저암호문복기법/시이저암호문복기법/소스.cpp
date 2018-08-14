/***************************************************************
*  ��������ȣ����ȣ���                                                                                                  *
***************************************************************/
/***************************************************************
* ���δ��б� ����Ʈ�������մ��� ����Ʈ�����к� 20163281Ȳ����                                *
***************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

//#define __MY_DEBUG__
void hw_32(std::ifstream& ifs);

int main()
{
	std::ifstream ifs;

	ifs.open("input.txt");
	if (ifs.fail())
	{
		std::cerr << "Cannot open file: input.txt" << std::endl;
		exit(1);
	}
	int num_cases;
	ifs >> num_cases;
#ifdef __MY_DEBUG__
	std::cout << "num_cases : " << num_cases << '\n';
#endif

	for (int i = 0; i < num_cases; ++i)
	{
		hw_32(ifs);
	}
	ifs.close();

	return 0;
}

void hw_32(std::ifstream& ifs)
{
	//������ �־��� ���ĺ��� ������� a���� z���� ������� ����
	double fe[26] = { 8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.996, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074 };

	std::string s;
	ifs >> s; //��Ʈ�� �Է¹ޱ�

			  //num : ��ȣ������ ������ �󵵼� üũ(0��° : a�� �󵵼�, 1��° : b�� �󵵼� ...)
	double num[26] = { 0, };
	//fm : ��ȣ������ ������ �󵵼� �����
	//kai : ī��������� ����
	double fm[26] = { 0, }, kai[26] = { 0, }, min ;

	//���ڿ� �ޱ�
	/*(�Է¹��� ��Ʈ���� i��°�� A�� a�̸� num�迭�� 0��° �� 1���� ����
	*b�� B�̸� 1��° �� 1�� ���� ...
	*��Ʈ���� ���̸�ŭ �ݺ��ϸ鼭 A(a) ~ Z(z) �󵵼� üũ)*/
	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case 'A':
		case 'a':
			num[0]++;
			break;

		case 'B':
		case 'b':
			num[1]++;
			break;

		case 'C':
		case 'c':
			num[2]++;
			break;

		case 'D':
		case 'd':
			num[3]++;
			break;

		case 'E':
		case 'e':
			num[4]++;
			break;

		case 'F':
		case 'f':
			num[5]++;
			break;

		case 'G':
		case 'g':
			num[6]++;
			break;

		case 'H':
		case 'h':
			num[7]++;
			break;

		case 'I':
		case 'i':
			num[8]++;
			break;

		case 'J':
		case 'j':
			num[9]++;
			break;

		case 'K':
		case 'k':
			num[10]++;
			break;

		case 'L':
		case 'l':
			num[11]++;
			break;

		case 'M':
		case 'm':
			num[12]++;
			break;

		case 'N':
		case 'n':
			num[13]++;
			break;

		case 'O':
		case 'o':
			num[14]++;
			break;

		case 'P':
		case 'p':
			num[15]++;
			break;

		case 'Q':
		case 'q':
			num[16]++;
			break;

		case 'R':
		case 'r':
			num[17]++;
			break;

		case 'S':
		case 's':
			num[18]++;
			break;

		case 'T':
		case 't':
			num[19]++;
			break;

		case 'U':
		case 'u':
			num[20]++;
			break;

		case 'V':
		case 'v':
			num[21]++;
			break;

		case 'W':
		case 'w':
			num[22]++;
			break;

		case 'X':
		case 'x':
			num[23]++;
			break;

		case 'Y':
		case 'y':
			num[24]++;
			break;

		case 'Z':
		case 'z':
			num[25]++;
			break;
		}
	}

	int cnt = 0; //��Ʈ������ ���ĺ����� ����
	for (int i = 0; i < s.length(); i++) {
		if (((65 <= (int)s[i]) && ((int)s[i]) <= 90) || (97 <= (int)s[i]) && (((int)s[i]) <= 122)) {
			cnt++;
		}
	}

	//��ȣ�� ����� ���
	//������ ���ĺ��� �󵵼��� �� �Ŀ� ����� ���
	// : �󵵼� / ���ĺ����� ����
	for (int i = 0; i < cnt; i++) {
		fm[i] = num[i] / cnt;
	}
	min = kai[0];
	//ī���������
	int key = 0, temp = 0;
	for (int i = 0; i < 26; i++) { //i : key���� �� �� �ִ� �ĺ�
		for (int j = 0; j < 26; j++) { //j : fm[]�� ������ �ε���
			 temp = i + j; //���ĺ����� Ű����ŭ �̵��� ���ĺ��� �ִ� ��
			if (temp >= 26)
				temp -= 26;
			kai[i] += (fm[temp] * fm[temp]) / fe[j]; //�󵵼��� ����/���ĺ����� ������� kai�� ����
		}

		//ī�������� �ּڰ��� �� �ε��� ã��
		if (min > kai[i]) {
			min = kai[i];
			key = i;
		}
	}
	//key�� Ȯ�ο� ��¹�
	//std::cout << "key : " << key << std::endl;

	for (int i = 0; i < s.length(); i++) {
		//���ĺ��϶��� key����ŭ �̵��ؾ���
		//key����ŭ ���µ� 65�̳� 97���� ���� ��� 25+1�� ����
		if (char(s[i] )>= 'A' && char(s[i]) <= 'Z')
		{
			if (s[i] - key < 65)
				std::cout << char(s[i] - key + 26);
			else
				std::cout << char(s[i] - key);
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (s[i] - key < 97)
				std::cout << char(s[i] - key + 26);
			else
				std::cout << char(s[i] - key);
		}
		else
			std::cout << s[i];

	}std::cout << std::endl;
}