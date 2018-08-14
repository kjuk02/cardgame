#ifndef __PRIM_H__
#define __PRIM_H__

#include <iostream>

#define MAX 6
#define MAX_INT 100

using namespace std;

static int graph[MAX][MAX] = 
{ {MAX_INT,6,1,5,MAX_INT,MAX_INT},
{6,MAX_INT,4,MAX_INT,3,MAX_INT},
{1,4,MAX_INT,5,6,5},
{5,MAX_INT,5,MAX_INT,MAX_INT,2},
{MAX_INT,3,6,MAX_INT,MAX_INT,6},
{MAX_INT,MAX_INT,5,2,6,MAX_INT}};

class mst
{
private:
	bool TV[MAX];
	int T[MAX - 1][2];
	int top;
	int cost;
	bool cycle[MAX][MAX];
	bool check(int a, int b);
public:
	mst();
	void init();
	void prim(int n);
	void kruskal();
	bool ifCycle(int a, int b);
	void printGraph();
};

#endif
