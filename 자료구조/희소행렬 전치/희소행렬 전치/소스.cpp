#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef struct {
	int row;
	int col;
	int value;
} SMarray;

SMarray a[100];
SMarray fa[100];
SMarray b[100];
SMarray fb[100];
int m, n, k = 0;  // ����� ũ�Ⱑ m x n
int v = 1;

void transpose(SMarray a[], SMarray b[]);
void fast_transpose(SMarray fa[], SMarray fb[]);
void print(SMarray a[], int x);
void fprint(SMarray a[], int x);

int main()
{
	ifstream inStream;
	inStream.open("input.txt");
	inStream >> m >> n;
	int mx[500] = { 0, };

	/* transpose�� �� a[]�� ����� :: a[index]�� 0 3 5 7 ���� ��Ŀ����� ���� */
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			inStream >> mx[k];
			if (mx[k] != 0)
			{
				// cout << mx[k] << endl;
				a[k].row = i;
				a[k].col = j;
				a[k].value = mx[k];
				/* cout << k << " " << a[k].row << " " << a[k].col << " " << a[k].value << endl;*/
			}
			k++;
		}
	}

	/* fast_transpose�� �� a[]�� ����� :: a[index]�� 0 1 2 ���� */
	int s = 0;
	fa[0].row = m; fa[0].col = n;
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (a[s].value != 0)
			{
				fa[v].row = a[s].row;
				fa[v].col = a[s].col;
				fa[v].value = a[s].value;
				//cout<<v<<" "<< fa[v].row <<" "<<fa[v].col<<" "<<fa[v].value<<endl<<endl;
				++v;
			}
			s++;
		}
	}
	fa[0].value = v - 1;

	print(a, m*n);
	transpose(a, b);
	print(b, m*n);

	cout << endl << "-----------" << endl << endl;

	fprint(fa, m*n);
	fast_transpose(fa, fb);
	fprint(fb, m*n);

	inStream.close();
}


void transpose(SMarray a[], SMarray b[])
{ /* a �� ��ġ���� b �� ����, ��:(0,3,22) -> (3,0,22) */
	int i, j, currentb;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;


	if (a[0].value > 0)
	{ /* 0 �� �ƴ� ��� */
		currentb = 1;
		for (i = 0; i <= 6/*a[0].col*/; i++)
		{ /* a ���� ������ ��ġ*/
			for (j = 1; j < k/*a[0].value*/; j++)
			{ /* ������ ���κ��� ���Ҹ� ã�´�. */
				if (a[j].col == i)
				{ /*���� ���� �ִ� ���Ҹ� b �� ÷�� */
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb].value = a[j].value;
					++currentb;
				}
			}
		}
	}
}

void fast_transpose(SMarray fa[], SMarray fb[])
{
	/* a �� ��ġ���� b �� ���� */
	int row_terms[500] = { 0, }, starting_pos[500] = { 0 , };
	int i, j, num_cols = fa[0].col, num_terms = fa[0].value;

	fb[0].row = num_cols;
	fb[0].col = fa[0].row;
	fb[0].value = num_terms;

	if (num_terms > 0)
	{
		/* 0 �� �ƴ� ��� */
		for (i = 0; i < num_cols; i++)   /* row terms�� 0���� �ʱ�ȭ */
		{
			row_terms[i] = 0;
		}

		for (i = 1; i <= num_terms; i++) /* �� row terms ���� ��*/
		{
			row_terms[fa[i].col]++;
		}
		// row_terms = 2 1 2 2 0 1 (�� ������ ����)

		starting_pos[0] = 1;

		/* �� row terms ������ ����*/
		for (i = 1; i < num_cols; i++)
		{
			starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
		}
		// starting_pos = 1 3 4 6 8 8
		cout << endl;
		for (i = 1; i <= num_terms; i++)
		{ /* A �� B �� �ű�*/
			j = starting_pos[fa[i].col]++;
			fb[j].row = fa[i].col;
			fb[j].col = fa[i].row;
			fb[j].value = fa[i].value;
		}

	}
}

void print(SMarray a[], int x)
{
	cout << endl;
	for (int i = 0; i<x; i++)
	{
		if (a[i].value != 0)
		{
			cout << a[i].row << " " << a[i].col << " " << a[i].value << endl;
		}
	}
}

void fprint(SMarray a[], int x)
{
	cout << endl;
	for (int i = 1; i<x; i++)
	{
		if (a[i].value != 0)
		{
			cout << a[i].row << " " << a[i].col << " " << a[i].value << endl;
		}
	}
}
