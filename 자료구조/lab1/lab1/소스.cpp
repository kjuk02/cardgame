#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream instream;
	instream.open("input.txt");

	string s;
	while (!instream.eof())
	{
		int count = 0;
		getline(instream, s);
		cout << s;
		for (int i = 0; i < s.size(); i++)
		{
			if(s[i]==' ')
			count++;
		}
		cout << count+1 << endl;
	}
	instream.close();
	return 0;
}