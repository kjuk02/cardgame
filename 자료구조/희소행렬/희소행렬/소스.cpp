#include<iostream>
#include<fstream>
#include<cstdlib>

typedef struct {
	int row;
	int col;
	int value;
}hw;
int main()
{
	int m, n;
	int mx[100][100] = { { 0,0} };
	hw f[100]= { 0, };
	hw fb[100] = { 0, };
	
	std::ifstream instream;
	instream.open("input.txt");
	if (instream.fail())
	{
		std::cerr << "input file openning error " << std::endl;
		exit(1);
	}
	instream >> m >> n;
	int count = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			instream >> mx[i][j];
			if (mx[i][j] != 0)
			{
				f[count].row = i;
				f[count].col = j;
				f[count].value = mx[i][j];
				count++;
			}
		}
	int term[100] = { 0, };
	int starting_pos[100] = { 0, };
	for (int i = 0; i < count; i++)
		term[f[i].col]++;
	int starting_count = 1;
	for (int i = 0; i < n; i++)
	{
		starting_pos[starting_count] = term[i] + starting_pos[starting_count - 1];
		starting_count++;
	}
	int k = 0;
	for (int i = 0; i < count; i++)
	{
		k = starting_pos[f[i].col]++;
		fb[k].col = f[i].row;
		fb[k].row = f[i].col;
		fb[k].value = f[i].value;
	}
	for (int i = 0; i < count; i++)
		std::cout << fb[i].row << " " << fb[i].col << " " << fb[i].value << std::endl;
	
	instream.close();
	return 0;
}