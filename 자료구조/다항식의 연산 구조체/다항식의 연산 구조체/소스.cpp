#include <iostream>
#include <cstdlib>

using namespace std;
//MaxTerms ���� -- �װ��� �ִ� 100���� ����ϱ� ����
#define MaxTerms 100
//1~3���� ���׽� ���, ����, �װ��� �迭
float coefarray[6][5] = { { 3, 6, 2 },{ -2, 7, 1 },{ 9, 8, 7, 3 },{ 42, -3, 1, 1, 2 },{ 1, 1, 2, 1 },{ -1, -1, 2, -1 } };
int exparray[6][5] = { { 1000, 2, 0 },{ 15, 2, 0 },{ 35, 34, 33, 30 },{ 42, 30, 29, 3, 0 },{ 3, 2, 1, 0 },{ 3, 2, 1, 0 } };
int numarray[6] = { 3, 3, 4, 5, 4, 4 };
//Polynomial class ����
class Polynomial;
//term class ����
class term {
	friend Polynomial;
private:
	float coef;
	int exp;
public:
	term() { coef = 0; exp = 0; };
};
//class Polynomial ����
class Polynomial
{
private:
	static term termArray[MaxTerms];
	static int free;
	int Start, Finish;
public:
	Polynomial();
	Polynomial Add(Polynomial poly);
	void NewTerm(float c, int e);
	char compare(int a, int b);
	void get();
	void set(int i);
	void print();
};
//Polynomial() �ʱⰪ ����
Polynomial::Polynomial()
{
	Start = Finish = free;
}
//Polynomial Add ����(å����)
Polynomial Polynomial::Add(Polynomial B)
{
	Polynomial C; int a = Start; int b = B.Start; C.Start = free; float c;
	while ((a <= Finish) && (b <= B.Finish))
		switch (compare(termArray[a].exp, termArray[b].exp)) {
		case'=':
			c = termArray[a].coef + termArray[b].coef;
			if (c) NewTerm(c, termArray[a].exp);
			a++; b++;
			break;
		case'<':
			NewTerm(termArray[b].coef, termArray[b].exp);
			b++;
			break;
		case'>':
			NewTerm(termArray[a].coef, termArray[a].exp);
			a++;
		}
	for (; a <= Finish; a++)
		NewTerm(termArray[a].coef, termArray[a].exp);
	for (; b <= B.Finish; b++)
		NewTerm(termArray[b].coef, termArray[b].exp);
	C.Finish = free - 1;
	return C;
}
//NewTerm �����(å ����)
void Polynomial::NewTerm(float c, int e)
{
	if (free >= MaxTerms) {//���� ������ MaxTerms(100��) �̻��� �� ó��
		cerr << "Too many terms in polynomials" << endl;
		exit(1);
	}
	termArray[free].coef = c;
	termArray[free].exp = e;
	free++;
}
// compare =====
// Polynomial::Add �ȿ����� exp �� �� �� char�� ��ȯ ���� method
char Polynomial::compare(int a, int b)
{
	if (a == b) return '=';
	else if (a>b) return '>';
	else return '<';
}
//���׽� �Է� �޴� �κ�
void Polynomial::get()
{
	int num;
	float c;
	int e;
	cout << "���׽� �� ���� : ";
	cin >> num;
	Start = free;
	for (int i = 0; i<num; i++)
	{
		cout << i + 1 << "�� ��� : ";
		cin >> c;
		cout << i + 1 << "�� ���� : ";
		cin >> e;
		NewTerm(c, e); // term �����κ�
	}
	Finish = free - 1;
}
//���׽� ��� �κ�
void Polynomial::print()
{
	for (int i = Start; i <= Finish; i++)
	{
		cout << termArray[i].coef;
		if (termArray[i].exp != 0) cout << "x^" << termArray[i].exp;
		if (i != Finish) cout << "+";
	}
	cout << endl;
}
//1��-3�� ���׽�
//���α׷� �ʱ⿡ ���ǵ� coefarray, exparray, numarray �̿�
//NewTerm ����
void Polynomial::set(int i)
{
	Start = free;
	for (int j = 0; j<numarray[i]; j++)
	{
		NewTerm(coefarray[i][j], exparray[i][j]);
	}
	Finish = free - 1;
}
term Polynomial::termArray[MaxTerms];
int Polynomial::free = 0;

// ���� ���α׷� �����
void main()
{
	Polynomial A, B, C;

	//1��-3�� ���׽� ��� �� ���
	cout << "=====<<  ����Ʈ�� �̿��� ���׽� ���� ���α׷� >>=====" << endl << endl;

	cout << "1~3�� ������ ���׽� ��� " << endl;
	cout << "4~6�� ����� ���� �� ���׽� �޾� ���" << endl << endl;

	for (int i = 0; i<3; i++)
	{
		cout << "���׽� " << i + 1 << "�� ����" << endl;
		cout << i + 1 << "�� ����" << endl;
		A.set(i * 2);
		cout << "A(x)=";
		A.print();
		B.set(2 * i + 1);
		cout << "B(x)=";
		B.print();
		C = A.Add(B);
		cout << "C(x)=";
		C.print();
		cout << "==================================================" << endl;
	}
	//4��-5�� ���׽� ���,���� �޾Ƽ�[get()] ���[add()] �� ���[print()]
	for (int i = 0; i<3; i++)
	{
		cout << "���׽�" << i + 4 << "�� ����" << endl;
		A.get();
		cout << "A(x)=";
		A.print();
		B.get();
		cout << "B(x)=";
		B.print();
		C = A.Add(B);
		cout << "C(x)=";
		C.print();
		cout << "==================================================" << endl;
	}
}