#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;
void hw(string* input,int numcase);
int main()
{
	int num, numcase;
	ifstream instream;
	instream.open("input.txt");
	if (instream.fail())
	{
		cerr << "input file openning error " << endl;
		exit(1);
	}
	instream >> num;
	for (int i = 0; i < num; i++)
	{
		string input;//input 받기
		instream >> numcase; //이동 위치
		instream >> input;

		hw(&input, numcase);
		for (int j = 0; j < input.size(); j++)
			cout << input[j];
		cout << endl;
	}

	instream.close();
}
void hw(string* input, int numcase)
{
	for (int j = 0; j < input->size(); j++)
	{
		if (input->at(j) >= 'A' && input->at(j) <= 'Z')
		{
			if (input->at(j) + numcase > 90)
				input->at(j) =char(input->at(j) + numcase - 26);
			else
				input->at(j) = char(input->at(j) + numcase);
		}
		else if (input->at(j) >= 'a' && input->at(j) <= 'z')
		{
			if (input->at(j) + numcase > 122)
				input->at(j) =char(input->at(j) + numcase - 26);
			else
				input->at(j) =char(input->at(j) + numcase);
		}
		else
			input[j]=input[j];
	}
}