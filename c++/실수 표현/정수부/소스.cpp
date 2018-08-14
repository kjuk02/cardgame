/***********************************
*                                  *
*       problem                    *
*                실수 표현	       *
*                                  *
*                                  *
***********************************/

/************************************
*                                   *
*       소프트웨어학부              *
*                20143050           *
*                        김현석     *
*                                   *
************************************/
#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<string>
using namespace std;

int hw(char num);
int main()
{
	int num;
	string numcase;
	fstream instream;
	instream.open("input.txt");
	if (instream.fail())
	{
		cerr << "input file openning error " << endl;
		exit(1);
	}

	instream >> num;

	for (int i = 0; i < num; i++)
	{
		instream >> numcase;
		int step = 0;
		int step2 = 0;
		int step3 = 0;
		int step4 = 0;
		int step5 = 0;
		int step6 = 0;
		int step7 = 0;
		int step8 = 0;
		int step9 = 0;
		int finalstep = 0, finalstep2 = 0, finalstep3 = 0, finalstep4 = 0, finalstep5 = 0, finalstep6 = 0;
		int point = 0;
		int point2 = 0;
		int point3 = 0;
		int point4 = 0;
		int point5 = 0;
		for (int k = 0; numcase[k] != 0; k++)
		{
			if ((numcase[k] == '.'))
			{
				if (point2 != 0||point4!=0)
					point = 2;
				else
					point++;
			}
			if ((numcase[k] == 'E' || numcase[k] == 'e'))
			{
				if (point4 != 0)
					point2 = 2;
				else
				point2++;
			}
			if ((numcase[k] == '-' || numcase[k] == '+'))
				point3++;
			if (numcase[k] != '-' && numcase[k] != '+' && numcase[k] != 'E' &&numcase[k] != 'e' && numcase[k] != '.' && hw(numcase[k]) == 0)
				point5++;
			if (step2 != 0||hw(numcase[k])==1)
			{
				step2 = 1;
				if (numcase[k] == 'E' || numcase[k] == 'e' || step3 != 0)
				{
					step3 = 1;

					if (numcase[k] == '.')
						step++;

					if (hw(numcase[k]) == 1&&step==0)
						finalstep = 1;
				}
				if (numcase[k] == '.' || step4 != 0)
				{
					step4 = 1;
					if (numcase[k] == 'E' || numcase[k] == 'e' || step5 != 0)
					{
						step5 = 1;
						if (hw(numcase[k]) == 1)
							finalstep2 = 1;
					}
				}
				
			}
			 if (numcase[k] == '.' || step6 != 0&&step3==0 )
			{
				step6= 1;
				if (hw(numcase[k])==1|| step7 != 0)
				{
					step7 = 1;
					if (numcase[k] == 'E' || numcase[k] == 'e' || step8 != 0)
					{
						step8 = 1;
						if (hw(numcase[k]==1))
							finalstep3 = 1;
					}
				}
				else if (step2 != 0)
				{
					if (numcase[k] == 'E' || numcase[k] == 'e' || step9!= 0)
					{
						step9 = 1;
						if (hw(numcase[k] == 1))
							finalstep6 = 1;
					}
				}
			}
		}
		if (step2 != 0 && step4 !=0&&step5==0&&step==0)
			finalstep5 = 1;
		if (step7 != 0 && step8 == 0)
			finalstep4 = 1;
		if (step4 != 0 && finalstep != 0)
			finalstep = 0;
		if ((finalstep != 0 || finalstep2 != 0 || finalstep3 != 0||finalstep4!=0||finalstep5!=0||finalstep6!=0)&& (point <=1) && (point2 <=1)&&(point5==0)&&(point4<=1))
			cout << 1 << endl;
		else 
			cout << 0 << endl;
	}
	instream.close();
	return 0;
}
int hw(char num)
{
	if (num=='0'||num == '1' || num == '2' || num == '3' || num == '4' || num == '5' || num == '6' || num == '7' || num == '8' || num == '9')
		return 1;
	else
		return 0;
}