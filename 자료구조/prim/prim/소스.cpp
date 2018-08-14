#include<iostream>
#include<fstream>
#include<vector> //disjoint set prim Àç±Í
#define f_pos 0
#define edges 6
struct line {
	int from;
	int to;
};

void find(bool visited[edges], line liner[edges - 1], int arr[100][100], int& now_position, int& count, int& f_pos_count, line first_liner[edges - 1], int& i);
int main()
{
	std::ifstream instream;
	instream.open("input.txt");
	int max;
	int arr[100][100] = { {0,0} };
	instream >> max;
	for (int i = 0; i < max; ++i)
	{
		for (int j = 0; j < max; ++j)
		{
			instream >> arr[i][j];
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	bool visited[edges];
	line liner[edges - 1];
	line first_liner[edges - 1];
	for (int i = 0; i < edges; ++i)
		visited[i] = false;
	visited[f_pos] = true;
	int now_position = f_pos;
	int count = 0;
	int f_pos_count = 0;
	for (int i = 0; i < edges; ++i)
	{
		find(visited, liner, arr, now_position, count,f_pos_count,first_liner,i);
	}
	for (int i = 0; i < count; ++i)
	{
		std::cout << "(" << liner[i].from+1 << "," << liner[i].to+1 << ")" << " ";
	}
	instream.close();
}
void find(bool visited[edges], line liner[edges - 1], int arr[100][100], int& now_position, int& count,int& f_pos_count,line first_liner[edges-1],int& i)
{
	int min = 100;
	int min_pos = 0;
	for (int i = 0; i < edges; ++i)
	{
		if (!visited[i])
		{
			if (arr[f_pos][i]!=100&&now_position == f_pos)
			{
				first_liner[f_pos_count].from = f_pos;
				first_liner[f_pos_count].to = i;
				++f_pos_count;
			}
			if (min > arr[now_position][i])
			{
				min = arr[now_position][i];
				min_pos = i;
			}
		}
	}
	for (int i = 0; i < f_pos_count; ++i)
	{
		if (min > arr[first_liner[i].from][first_liner[i].to]&&(first_liner[i].to!=liner[0].to))
		{
			now_position = f_pos;
			++i;
			return;
		}
	}
	visited[min_pos] = true;
	liner[count].from = now_position;
	liner[count].to = min_pos;
	now_position = min_pos;
	++count;
}