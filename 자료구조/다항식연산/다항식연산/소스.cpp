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
	int numa, numb;  // num  = a, b의 항 개수

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
		case -1: /* a의 expon이 b의 expon보다 작은 경우 */
			attach(terms[startb].coef, terms[startb].expon);
			startb++;
			break;
		case  0: /* 지수가 같은 경우 */
			coefficient = terms[starta].coef + terms[startb].coef;
			if (coefficient)
				attach(coefficient, terms[starta].expon);
			starta++;
			startb++;
			break;
		case   1: /* a의 expon이 b의 expon보다 큰 경우 */
			attach(terms[starta].coef, terms[starta].expon);
			starta++;
			break;

		}
	/* A(x)의 나머지 항들을 첨가한다. */
	for (; starta <= finisha; starta++)
		attach(terms[starta].coef, terms[starta].expon);

	/* B(x)의 나머지 항들을 첨가한다. */
	for (; startb <= finishb; startb++)
		attach(terms[startb].coef, terms[startb].expon);

	*finishd = avail - 1;
}


void attach(float coefficient, int exponent)
{
	/* 새로운 항을 다항식에 첨가 */
	if (avail >= MAX_TERMS) {
		fprintf(stderr, "다항식에 항이 너무 많다.\n");
		exit(1);
	}
	terms_copy[avail].coef = coefficient;
	terms_copy[avail++].expon = exponent;
}


int compare(int a, int b)
{
	/* a와 b를 비교하여 작으면 -1, 같으면 0, 크면 1을 반환한다. */
	if (a<b) return -1;
	else if (a>b) return 1;
	else return 0;
}
