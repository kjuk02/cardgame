#include <iostream>
#include <cstdlib>

using namespace std;
//MaxTerms 정의 -- 항개수 최대 100개에 사용하기 위함
#define MaxTerms 100
//1~3번의 다항식 계수, 지수, 항개수 배열
float coefarray[6][5] = { { 3, 6, 2 },{ -2, 7, 1 },{ 9, 8, 7, 3 },{ 42, -3, 1, 1, 2 },{ 1, 1, 2, 1 },{ -1, -1, 2, -1 } };
int exparray[6][5] = { { 1000, 2, 0 },{ 15, 2, 0 },{ 35, 34, 33, 30 },{ 42, 30, 29, 3, 0 },{ 3, 2, 1, 0 },{ 3, 2, 1, 0 } };
int numarray[6] = { 3, 3, 4, 5, 4, 4 };
//Polynomial class 정의
class Polynomial;
//term class 정의
class term {
	friend Polynomial;
private:
	float coef;
	int exp;
public:
	term() { coef = 0; exp = 0; };
};
//class Polynomial 내용
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
//Polynomial() 초기값 정의
Polynomial::Polynomial()
{
	Start = Finish = free;
}
//Polynomial Add 정의(책내용)
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
//NewTerm 선언부(책 내용)
void Polynomial::NewTerm(float c, int e)
{
	if (free >= MaxTerms) {//항의 개수가 MaxTerms(100개) 이상일 때 처리
		cerr << "Too many terms in polynomials" << endl;
		exit(1);
	}
	termArray[free].coef = c;
	termArray[free].exp = e;
	free++;
}
// compare =====
// Polynomial::Add 안에서의 exp 값 비교 후 char값 반환 위한 method
char Polynomial::compare(int a, int b)
{
	if (a == b) return '=';
	else if (a>b) return '>';
	else return '<';
}
//다항식 입력 받는 부분
void Polynomial::get()
{
	int num;
	float c;
	int e;
	cout << "다항식 항 개수 : ";
	cin >> num;
	Start = free;
	for (int i = 0; i<num; i++)
	{
		cout << i + 1 << "항 계수 : ";
		cin >> c;
		cout << i + 1 << "항 지수 : ";
		cin >> e;
		NewTerm(c, e); // term 생성부분
	}
	Finish = free - 1;
}
//다항식 출력 부분
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
//1번-3번 다항식
//프로그램 초기에 정의된 coefarray, exparray, numarray 이용
//NewTerm 생성
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

// 실제 프로그램 실행부
void main()
{
	Polynomial A, B, C;

	//1번-3번 다항식 계산 및 출력
	cout << "=====<<  리스트를 이용한 다항식 덧셈 프로그램 >>=====" << endl << endl;

	cout << "1~3번 정해진 다항식 계산 " << endl;
	cout << "4~6번 사용자 임의 값 다항식 받아 계산" << endl << endl;

	for (int i = 0; i<3; i++)
	{
		cout << "다항식 " << i + 1 << "번 문제" << endl;
		cout << i + 1 << "번 문제" << endl;
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
	//4번-5번 다항식 계수,지수 받아서[get()] 계산[add()] 및 출력[print()]
	for (int i = 0; i<3; i++)
	{
		cout << "다항식" << i + 4 << "번 문제" << endl;
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