#include<iostream>
#include<cstdlib>

typedef struct {
	int coef;
	int expone;
}poly;

int avail = 0;
poly term[100] = { {4,2},{1,0},{4,2},{1,0} };
poly term2[100] = { {1,4},{2,0},{3,2},{1,0} };
void plus(int Astart, int Aend, int Bstart, int Bend, int &Cstart, int &Cend);
void minus(int Astart, int Aend, int Bstart, int Bend, int &Cstart, int &Cend);
void attach(int num, int num2, int &Cs);
void attach2(int num, int num2, int &Cs);
int compare(int num, int num2);
int main()
{
	int Cstart = 0,Cend=0;
	plus(0, 1, 2, 3, Cstart, Cend);
	for (int i = 0; i <= 1; i++)
		std::cout << term[i].coef << " " << term[i].expone<<" ";
	std::cout << std::endl;
	for (int i = 2; i <= 3; i++)
		std::cout << term[i].coef << " " << term[i].expone<<" ";
	std::cout << std::endl;
//¾Æ·¡ ¿¡ ÀÖ´Â°Ô µ¡¼À
	for (; Cstart < Cend; Cstart++)
		std::cout << term[Cstart].coef << " " << term[Cstart].expone<<" ";
	std::cout << std::endl;
	
	std::cout << std::endl;
	minus(0, 1, 2, 3, Cstart, Cend);
	for (int i = 0; i <= 1; i++)
		std::cout << term2[i].coef << " " << term2[i].expone << " ";
	std::cout << std::endl;
	for (int i = 2; i <= 3; i++)
		std::cout << term2[i].coef << " " << term2[i].expone << " ";
	std::cout << std::endl;
//¾Æ·¡¿¡ ÀÖ´Â°Ô »¬¼À
	for (; Cstart < Cend; Cstart++)
		std::cout << term2[Cstart].coef << " " << term2[Cstart].expone << " ";
	std::cout << std::endl;

	return 0;
}
void plus(int Astart, int Aend, int Bstart, int Bend, int &Cstart, int &Cend)
{
	int As = Astart;
	int Ae = Aend;
	int Bs = Bstart;
	int Be = Bend;
	Cstart = Be + 1;
	int Cs = Be + 1;
	int coef = 0;
	while ((As <= Ae) && (Bs <= Be))
	{
		switch (compare(term[As].expone, term[Bs].expone))
		{
			case 1:
			{
				attach(term[As].coef, term[As].expone, Cs);
				As++; break;
			}
			case 0:
			{
				coef = term[As].coef + term[Bs].coef;
				attach(coef,term[As].expone, Cs);
				As++, Bs++; break;
			}
			case -1:
			{
				attach(term[Bs].coef, term[Bs].expone, Cs);
				Bs++; break;
			}
		}
	}
	for (; As <= Ae; As++)
		attach(term[As].coef, term[As].expone, Cs);
	for (; Bs <= Be; Bs++)
		attach(term[Bs].coef, term[Be].expone, Cs);
	Cend = Cs;
}
void minus(int Astart, int Aend, int Bstart, int Bend, int &Cstart, int &Cend)
{
	int As = Astart;
	int Ae = Aend;
	int Bs = Bstart;
	int Be = Bend;
	Cstart = Be + 1;
	int Cs = Be + 1;
	int coef = 0;
	while ((As <= Ae) && (Bs <= Be))
	{
		switch (compare(term2[As].expone, term2[Bs].expone))
		{
		case 1:
		{
			attach2(term2[As].coef, term2[As].expone, Cs);
			As++; break;
		}
		case 0:
		{
			coef = term2[As].coef - term2[Bs].coef;
			attach2(coef, term2[As].expone, Cs);
			As++, Bs++; break;
		}
		case -1:
		{
			attach2((term2[Bs].coef) *(-1), term2[Bs].expone, Cs);
			Bs++; break;
		}
		}
	}
	for (; As <= Ae; As++)
		attach2(term2[As].coef, term2[As].expone, Cs);
	for (; Bs <= Be; Bs++)
		attach2((-1)*(term2[Bs].coef), term2[Bs].expone, Cs);
	Cend = Cs;
}
int compare(int num, int num2)
{
	if (num > num2)
		return 1;
	else if (num == num2)
		return 0;
	else
		return -1;
}
void attach(int num, int num2,int &Cs)
{
	term[Cs].coef = num;
	term[Cs].expone = num2;
	Cs++;
}
void attach2(int num, int num2, int &Cs)
{
	term2[Cs].coef = num;
	term2[Cs].expone = num2;
	Cs++;
}