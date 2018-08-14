#include<iostream>
#include<fstream>

void check(int arrayA[][5], int count);
void bingo_function(int arrayA[][5], int &bingo);
int main()
{
	std::ifstream instream;
	instream.open("input.txt");

	int num = 0;
	instream >> num;
	for (int i = 0; i < num; i++)
	{
		int arrayA[5][5] = { { 0,0 } };
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				instream >> arrayA[j][k];
		arrayA[2][2] = 100;
		int count = 0;
		int bingo = 0;
		int number = 0;
		for (int j = 0; j<75; j++)
		{
			instream >> count;
			check(arrayA, count);
			if (bingo == 0)
			{
				bingo_function(arrayA, bingo);
				number++;
			}
		}
		std::cout << number << std::endl;
	}
}
void check(int arrayA[][5], int count)
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (arrayA[i][j] == count)
				arrayA[i][j] = 100;
}
void bingo_function(int arrayA[][5], int &bingo)
{
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		count = 0;
		for (int k = 0; k < 5; k++)
		{
			if (arrayA[i][k] == 100)
				count++;
			else
				count = 0;
			if (count == 5)
			{
				bingo = 1;
				break;
			}
		}
	}
	count = 0;
	for (int i = 0; i < 5; i++)
	{
		count = 0;
		for (int k = 0; k < 5; k++)
		{
			if (arrayA[k][i] == 100)
				count++;
			else
				count = 0;
			if (count == 5)
			{
				bingo = 1;
				break;
			}
		}
	}
	count = 0;
	for (int i = 0; i < 5; i++)
	{
		if (arrayA[i][i] == 100)
			count++;
		else
			count = 0;
		if (count == 5)
		{
			bingo = 1;
			break;
		}
	}
	count = 0;
	for (int i = 0; i < 5; i++)
	{
		if (arrayA[i][4 - i] == 100)
			count++;
		else
			count = 0;
		if (count == 5)
		{
			bingo = 1;
			break;
		}
	}
	if (arrayA[0][0] == 100 && arrayA[0][4] == 100 && arrayA[4][0] == 100 && arrayA[4][4] == 100)
		bingo = 1;
}