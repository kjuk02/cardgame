#include<iostream>
#include<fstream>
#include "string"
using namespace std;

 struct area{
	string shape;
	int data;
	int data2;
	int sum;
};

void hw1(ifstream &instream,area term[],int x);
void hw2(area term[],int x);
void sorting(area term[],int x);
int main()
{
	ifstream instream;
	area term[100];
	instream.open("input.txt");
	if (instream.fail())
	{
		cerr << "input file openning error " << endl;
		exit(1);
	}
	int x = 0;
	instream >> term[x].shape;

	while (1)
	{
		hw1(instream,term,x);
		x++;
		instream >> term[x].shape;
		if (term[x].shape == "")break;
	}
	cout << endl;

	sorting(term,x);
	hw2(term,x);

	instream.close();

	return 0;
}

void hw1(ifstream &instream,area term[],int x)
{
	if (term[x].shape == "triangle")
	{
		instream >> term[x].data >> term[x].data2;
		
		term[x].sum = (term[x].data*term[x].data2) / 2;
		cout << term[x].shape << " " << term[x].data << " " << term[x].data2 << " " << term[x].sum << endl;
	}
	else if(term[x].shape == "rectangle")
	{
		instream >> term[x].data >> term[x].data2;

		term[x].sum = term[x].data*term[x].data2;
		cout << term[x].shape << " " << term[x].data << " " << term[x].data2 << " " << term[x].sum << endl;
	}
	else
	{
		instream >> term[x].data;

		term[x].sum = term[x].data*term[x].data*3.14;
		cout << term[x].shape << " " << term[x].data << " " << term[x].sum << endl;
	}
}
void sorting(area term[],int x)
{
	area temp;
	for (int i = 0; i < x-1; i++)
	{
		for (int k = 0; k<x-1; k++)
		{
			if (int(term[k].shape[0]) >int(term[k+1].shape[0]))
			{
				temp =term[k+1];
				term[k+1] = term[k];
				term[k] = temp;
			}
		}
	}
}
void hw2(area term[],int x)
{
	for (int i=0; i<x;i++)
	{
		if (term[i].shape == "triangle")
		cout << term[i].shape << " " << term[i].data << " " << term[i].data2 << " " << term[i].sum << endl;
		else if (term[i].shape == "rectangle")
			cout << term[i].shape << " " << term[i].data << " " << term[i].data2 << " " << term[i].sum << endl;
		else
			cout << term[i].shape << " " << term[i].data << " " << term[i].sum << endl;	
	}
}