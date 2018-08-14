#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100
using namespace std;

typedef struct {
	float coef;
	int expon;
} Polynomial;
Polynomial terms[MAX_TERMS];
Polynomial terms_copy[MAX_TERMS];
int avail = 0;
int starta, finisha, startb, finishb, startd, finishd;

void padd(int, int, int, int, int *, int *);
void attach(float, int);
int compare(int, int);
void print(Polynomial a);

int main()
{

	int numPol;
	ifstream inStream;
	inStream.open("input.txt");
	int numa, numb;  // num  = a, b�� �� ����

	int i;
	inStream >> numa;
	cout << "numa : " << numa << endl;
	for (i = 0; i<numa; ++i)
	{
		inStream >> terms[i].expon >> terms[i].coef;
	}

	inStream >> numb;
	cout << "numb : " << numb << endl << endl;
	for (i = numa; i<numa + numb; ++i)
	{
		inStream >> terms[i].expon >> terms[i].coef;
	}

	starta = 0;
	finisha = starta + numa - 1;
	startb = finisha + 1;
	finishb = startb + numb - 1;

	for (int i = 0; i <= finishb; i++)
	{
		cout << terms[i].coef << " " << terms[i].expon << endl;
	}
	cout << endl;

	padd(starta, finisha, startb, finishb, &startd, &finishd);

	cout << "startd : " << startd << ", finishd : " << finishd << endl << endl;
	for (int i = 0; i <= finishd; i++)
	{
		cout << terms_copy[i].coef << " " << terms_copy[i].expon << endl;
	}
}

void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd)
{

	float coefficient;
	*startd = avail;
	while (starta <= finisha && startb <= finishb)

		switch (compare(terms[starta].expon, terms[startb].expon))
		{
		case -1: /* a�� expon�� b�� expon���� ���� ��� */
			attach(terms[startb].coef, terms[startb].expon);
			startb++;
			break;
		case  0: /* ������ ���� ��� */
			coefficient = terms[starta].coef + terms[startb].coef;
			if (coefficient)
				attach(coefficient, terms[starta].expon);
			starta++;
			startb++;
			break;
		case   1: /* a�� expon�� b�� expon���� ū ��� */
			attach(terms[starta].coef, terms[starta].expon);
			starta++;
			break;

		}
	/* A(x)�� ������ �׵��� ÷���Ѵ�. */
	for (; starta <= finisha; starta++)
		attach(terms[starta].coef, terms[starta].expon);

	/* B(x)�� ������ �׵��� ÷���Ѵ�. */
	for (; startb <= finishb; startb++)
		attach(terms[startb].coef, terms[startb].expon);

	*finishd = avail - 1;
}


void attach(float coefficient, int exponent)
{
	/* ���ο� ���� ���׽Ŀ� ÷�� */
	if (avail >= MAX_TERMS) {
		fprintf(stderr, "���׽Ŀ� ���� �ʹ� ����.\n");
		exit(1);
	}
	terms_copy[avail].coef = coefficient;
	terms_copy[avail++].expon = exponent;
}


int compare(int a, int b)
{
	/* a�� b�� ���Ͽ� ������ -1, ������ 0, ũ�� 1�� ��ȯ�Ѵ�. */
	if (a<b) return -1;
	else if (a>b) return 1;
	else return 0;
}
