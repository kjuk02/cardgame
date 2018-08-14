#include<iostream>
#include<fstream>
#include<string>
struct sell {
	int row;
	int col;
};
int hw(std::string input[][100], std::string spell[100], int x, int y,int dir,int now_x,int now_y,int fullconetr);
int check_function(std::string input[][100], std::string spell[100],int x,int y,int fullconter);
void movesert(sell move[]);
int main()
{
	std::ifstream instream;
	instream.open("input.txt");
	int num = 0, numcase = 0;
	instream >> num;
	for (int i = 0; i < num; i++)
	{
		int x = 0, y = 0;
		std::string input[100][100];
		std::string spell[100];
		std::string comber;
		char c;
		instream >> x >> y;
		for (int j = 0; j < x; j++)
			for (int k = 0; k < y; k++)
			{
				instream >> c;
				input[j][k] = c;
			}
		instream >> numcase;
		for (int j = 0; j < numcase; j++)
		{
			instream >> comber;
			int fullconter = 0;
			for (int f = 0; f < comber.size(); f++)
			{
				spell[f] = comber[f];
				fullconter++;
			}
			check_function(input, spell, x, y,fullconter);
			for(int f=0;f<comber.size();f++)
			spell[f].clear();

			comber.clear();
		}
	}
	instream.close();
	return 0;
}
int check_function(std::string input[][100], std::string spell[100], int x, int y,int fullcounter)
{
	sell move[8];
	movesert(move);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			int row = 0;
			int col = 0;
			
			if (input[i][j] == spell[0])
			{
				
				int dir = 0;
				int count = 0;
				while (dir < 8)
				{
					if (0 <=i+ move[dir].row&& i+ move[dir].row < x)
						row = i + move[dir].row;
					else
					{
						dir++;
						continue;
					}
					if (0 <= j + move[dir].col&& j + move[dir].col < y)
						col = j + move[dir].col;
					else
					{
						dir++;
						continue;
					}
					if (input[row][col] == spell[1])
					{
						if (hw(input, spell , x, y, dir, i, j, fullcounter))
						{
							std::cout << i+1 << " " << j+1 << " " << dir << std::endl;
							return 0;
						}
					}
					
					dir++;
				}
			}
		}
	}
	std::cout << -1 << std::endl;
	return 0;
}
int hw(std::string input[][100], std::string spell[100], int x, int y,int dir,int now_x,int now_y,int fullcounter)
{
	sell move[8];
	movesert(move);
	int row = 0, col = 0;
	row = now_x;
	col = now_y;
	int value = 1;
	int total = 1;
	while (row < x&&col<y&&value<fullcounter)
	{
		if (0 <= row + move[dir].row&& row + move[dir].row < x)
			row = row+move[dir].row;
		else
			return 0;
		if (0 <= col + move[dir].col&& col+ move[dir].col < y)
			col = col + move[dir].col;
		else
			return 0;
		if (input[row][col] == spell[value])
		{
			total++;
		}
		value++;
	}
	if (total == fullcounter)
		return 1;
	else
		return 0;
}
void movesert(sell move[])
{
	move[0].row = -1; move[0].col = 0;/*N*/  move[1].row = -1; move[1].col = 1; /*NE*/  move[2].row = 0; move[2].col = 1; /*E */move[3].row = 1; move[3].col = 1; /*SE */move[4].row = 1; move[4].col = 0;// S     
	move[5].row = 1; move[5].col = -1;   /*SW*/  move[6].row = 0; move[6].col = -1; /*W*/move[7].row = -1; move[7].col = -1;  /*NW*/
}