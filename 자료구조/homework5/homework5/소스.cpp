#include <iostream>

#define max 7

int cost[max][max] = {// 비용 인접 행렬
	{ 100, 2, 4, 5, 100, 100, 100 },
	{ 100, 100, 100, 2, 7, 100, 100 },
	{ 100, 100, 100, 1, 100, 4, 100 },
	{ 100, 2, 1, 100, 4, 3, 100 },
	{ 100, 7, 100, 4, 100, 1, 5 },
	{ 100, 100, 4, 3, 1, 100, 7 },
	{ 100, 100, 100, 100, 7, 5, 100 }
};

void Shortestpath(int v, int cost[max][max], int distance[max], int node, bool found[]); //최단경로 찾는 함수
int choose(int distance[], int n, bool found[]);//해당 노드에서의 최단경로를 찾는다.
void print_(); //인접행렬을 출력한다.
void print_2(int distance[max]); //각 node의 distance를 출력한다.

int main() 
{
	print_(); //인접행렬 출력
	int distance[max]; //각 노드들의 distance 저장
	bool found[max]; //이미 찾은 노드를 true로 설정

	Shortestpath(0, cost, distance, max, found); //최단경로를 찾는다.
}
void Shortestpath(int v, int cost[max][max], int distance[max],int node, bool found[]) 
{
	int i, u, w;
	
	for (i = 0; i < max; i++)//found를 false으로 초기화하고 원하는 정점에서 distance를 distance에 넣어준다. -초기값 설정
	{
		found[i] = false;
		distance[i] = cost[v][i];
	}
	found[v] = true; //정점에서 시작하기때문에 정점은 true로 표시한다.
	distance[v] = 0; //정점은 0으로 입력한다.
	for (i = 0; i < node - 1; i++) 
	{ 
		u = choose(distance, node, found);//최소 비용노드 수색한다.
		
		found[u] = true; //최소비용의 노드를 찾았으면 그위치에 표시한다.
		for (w = 0; w < node; w++) {
			
			if (!found[w])//표시되지않은 노드들중에 이전의 값보다 경로의 비용이 적은것을 찾으면
			{
				if (distance[u] + cost[u][w] < distance[w])//그 값을 distance에 저장한다.
					distance[w] = distance[u] + cost[u][w];
			}
		}
		print_2(distance);//distance 출력
	}
}
int choose(int distance[], int n, bool found[]) //최소비용의 노드를 찾는다.
{
	int	temp, spot;
	spot = 0; //초기화
	temp = 100; //temp를 100으로 초기화
	for (int i = 0; i < n; i++) 
	{
		if (distance[i] < temp && !found[i]) //만약 distance의 값이 temp보다 작고 이미 간곳이 아니면 temp는 distance가 되고 spot는 그 위치가 된다.
		{
			temp = distance[i];
			spot = i;
		}
	}
	return spot;
}
void print_() //인접행렬을 출력한다.
{
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++)
			std::cout << cost[i][j] << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void print_2(int distance[max]) //distance를 출력한다.
{
	std::cout << "distance: ";
	for (int i = 0; i < max; i++)
		std::cout << distance[i] << " ";
	std::cout << std::endl;
}