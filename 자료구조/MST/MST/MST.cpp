#include "MST.h"

mst::mst()
{
	init();
}

void mst::init()
{
	for (int i = 0; i < MAX; i++)
	{
		TV[i] = false;
		for (int j = 0; j < MAX; j++)
			cycle[i][j] = false;
	}
	top = 0;
	cost = 0;
}

void mst::prim(int n)
{
	n = n - 1;
	TV[n] = true;

	while (top<MAX - 1)
	{
		int s = -1, f = -1;
		int min = MAX_INT;

		for (int i = 0; i < MAX; i++)
		{
			if (!TV[i])
				continue;

			for (int j = 0; j < MAX; j++)
			{
				if (TV[j] || graph[i][j] == MAX_INT)
					continue;
				else if (min>graph[i][j])
				{
					min = graph[i][j];
					s = i;
					f = j;
				}
			}
		}

		if (min == MAX_INT)
		{
			break;
		}
		else
		{
			T[top][0] = s;
			T[top++][1] = f;
			TV[f] = true;
			cost += graph[s][f];
		}
	}

	if (top < MAX - 1)
		cout << "No spanning Tree.\n";
	else
	{
		cout << "Mininum spanning trees :" << endl;
		for (int i = 0; i < MAX - 1; i++)
			cout << " (" << T[i][0] + 1 << "," << T[i][1] + 1 << ")";
		cout << endl;
		cout << "Total cost : " << cost << endl;
	}
}

void mst::kruskal()
{
	while (top < MAX - 1)
	{
		int s = -1, f = -1;
		int min = MAX_INT;

		for (int i = 0; i < MAX; i++)
		{
			// if (!TV[i])
			// 	continue;
			for (int j = 0; j < MAX; j++)
			{	// kruskal
				if (graph[i][j] == MAX_INT)
					continue;
				else if (min > graph[i][j] && !ifCycle(i, j) && !check(i, j))
				{
					s = i;
					f = j;
					min = graph[i][j];
				}
			}
		}

		if (min == MAX_INT)
			break;
		else
		{
			T[top][0] = s;
			T[top++][1] = f;
			TV[s] = true;
			TV[f] = true;
			cout << s << " " << f << " " << graph[s][f] << endl;
			cost += graph[s][f];
		}
	}
	if (top < MAX - 1)
		cout << "No spanning Tree.\n";
	else
	{
		cout << "Mininum spanning trees :" << endl;
		for (int i = 0; i < MAX - 1; i++)
			cout << " (" << T[i][0] + 1 << "," << T[i][1] + 1 << ")";
		cout << endl;
		cout << "Total cost : " << cost << endl;
	}
}


bool mst::ifCycle(int a, int b)
{
	if (a == b)
		return true;

	for (int i = 0; i < top; i++)
	{
		if (T[i][0] == a && !cycle[T[i][0]][T[i][1]])
		{
			cycle[T[i][0]][T[i][1]] = true;
			cycle[T[i][1]][T[i][0]] = true;

			if (ifCycle(T[i][1], b))
				return true;
			return true;
		}
		else if (T[i][1] == a && !cycle[T[i][1]][T[i][0]])
		{
			cycle[T[i][0]][T[i][1]] = true;
			cycle[T[i][1]][T[i][0]] = true;

			if (ifCycle(T[i][0], b))
				return true;
			return true;
		}
	}
	return false;
}

bool mst::check(int a, int b)
{
	for (int i = 0; i < top; i++)
	{
		if (T[i][0] == a && T[i][1] == b)
			return true;
		else if (T[i][1] == a && T[i][0] == b)
			return true;
	}
	return false;
}

void mst::printGraph()
{
	cout << "     ";
	for (int a = 0; a < MAX; a++)
		cout << 'v' << a << "   ";
	cout << endl;
	for (int b = 0; b < MAX; b++)
	{
		cout << 'v' << b << "  ";
		for (int c = 0; c < MAX; c++)
		{
			if (graph[b][c] / 100 == 0)
				cout << " ";
			if (graph[b][c] / 10 == 0)
				cout << " ";

			cout << graph[b][c] << "  ";
		}
		cout << endl;
	}
}
