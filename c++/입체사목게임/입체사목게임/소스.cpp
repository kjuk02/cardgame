#include<iostream>
#include<fstream>

void hw(int arrayA[][7], int &winner);
int main()
{
	std::ifstream instream;
	instream.open("input.txt");

	int num = 0, numcase = 0;
	instream >> num;
	for (int i = 0; i < num; i++)
	{
		instream >> numcase;
		int input = 0;
		int total[7] = { 5,5,5,5,5,5,5 };
		int arrayA[6][7] = { 0, };
		int arrayB[6][7] = { 0, };
		for (int j = 0; j < numcase; j++)
		{
			instream >> input;
			if (j % 2 == 0)
				arrayA[total[input - 1]][input - 1] = 1;
			else
				arrayB[total[input - 1]][input - 1] = 1;
			total[input - 1]--;
		}
		int player1 = 0, player2 = 0;
		hw(arrayA, player1);
		hw(arrayB, player2);
		if (player1 == 1)
			std::cout << 1 << std::endl;
		else if (player2 == 1)
			std::cout << 2 << std::endl;
		else
			std::cout << 0 << std::endl;
	}
	instream.close();

	return 0;
}
void hw(int arrayA[][7], int &winner)
{
	int count = 0;

	for (int j = 0; j < 6; j++) //가로
	{
		count = 0;
		for (int k = 0; k < 7; k++)
		{
			if (arrayA[j][k] == 1)
				count++;
			else
				count = 0;
			if (count == 4)
				winner = 1;
		}
	}
	count = 0;
	for (int j = 0; j < 7; j++) //세로
	{
		count = 0;
		for (int k = 0; k < 6; k++)
		{
			if (arrayA[k][j] == 1)
				count++;
			else
				count = 0;
			if (count == 4)
				winner = 1;
		}
	}
	count = 0;
	for (int j = 0; j < 6; j++)
	{
		count = 0;
		for (int k = 0; k < j + 1; k++)
		{
			if (arrayA[j - k][k] == 1)
				count++;
			else
				count = 0;
			if (count == 4)
				winner = 1;
		}
	}
	count = 0;
	for (int j = 0; j < 6; j++)
	{
		count = 0;
		for (int k = 0; k < j + 1; k++)
		{
			if (arrayA[5 - k][6 + k - j] == 1)
				count++;
			else
				count = 0;
			if (count == 4)
				winner = 1;
		}
	}
	count = 0;
	for (int j = 0; j < 6; j++)
	{
		count = 0;
		for (int k = 0; k < j + 1; k++)
		{
			if (arrayA[k][6 - j + k] == 1)
				count++;
			else
				count = 0;
			if (count == 4)
				winner = 1;
		}
	}
	count = 0;
	for (int j = 0; j < 6; j++)
	{
		count = 0;
		for (int k = 0; k < j + 1; k++)
		{
			if (arrayA[5 - j + k][k] == 1)
				count++;
			else
				count = 0;
			if (count == 4)
				winner = 1;
		}
	}
}