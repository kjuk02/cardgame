#include <iostream>

#define max 7

int cost[max][max] = {// ��� ���� ���
	{ 100, 2, 4, 5, 100, 100, 100 },
	{ 100, 100, 100, 2, 7, 100, 100 },
	{ 100, 100, 100, 1, 100, 4, 100 },
	{ 100, 2, 1, 100, 4, 3, 100 },
	{ 100, 7, 100, 4, 100, 1, 5 },
	{ 100, 100, 4, 3, 1, 100, 7 },
	{ 100, 100, 100, 100, 7, 5, 100 }
};

void Shortestpath(int v, int cost[max][max], int distance[max], int node, bool found[]); //�ִܰ�� ã�� �Լ�
int choose(int distance[], int n, bool found[]);//�ش� ��忡���� �ִܰ�θ� ã�´�.
void print_(); //��������� ����Ѵ�.
void print_2(int distance[max]); //�� node�� distance�� ����Ѵ�.

int main() 
{
	print_(); //������� ���
	int distance[max]; //�� ������ distance ����
	bool found[max]; //�̹� ã�� ��带 true�� ����

	Shortestpath(0, cost, distance, max, found); //�ִܰ�θ� ã�´�.
}
void Shortestpath(int v, int cost[max][max], int distance[max],int node, bool found[]) 
{
	int i, u, w;
	
	for (i = 0; i < max; i++)//found�� false���� �ʱ�ȭ�ϰ� ���ϴ� �������� distance�� distance�� �־��ش�. -�ʱⰪ ����
	{
		found[i] = false;
		distance[i] = cost[v][i];
	}
	found[v] = true; //�������� �����ϱ⶧���� ������ true�� ǥ���Ѵ�.
	distance[v] = 0; //������ 0���� �Է��Ѵ�.
	for (i = 0; i < node - 1; i++) 
	{ 
		u = choose(distance, node, found);//�ּ� ����� �����Ѵ�.
		
		found[u] = true; //�ּҺ���� ��带 ã������ ����ġ�� ǥ���Ѵ�.
		for (w = 0; w < node; w++) {
			
			if (!found[w])//ǥ�õ������� �����߿� ������ ������ ����� ����� �������� ã����
			{
				if (distance[u] + cost[u][w] < distance[w])//�� ���� distance�� �����Ѵ�.
					distance[w] = distance[u] + cost[u][w];
			}
		}
		print_2(distance);//distance ���
	}
}
int choose(int distance[], int n, bool found[]) //�ּҺ���� ��带 ã�´�.
{
	int	temp, spot;
	spot = 0; //�ʱ�ȭ
	temp = 100; //temp�� 100���� �ʱ�ȭ
	for (int i = 0; i < n; i++) 
	{
		if (distance[i] < temp && !found[i]) //���� distance�� ���� temp���� �۰� �̹� ������ �ƴϸ� temp�� distance�� �ǰ� spot�� �� ��ġ�� �ȴ�.
		{
			temp = distance[i];
			spot = i;
		}
	}
	return spot;
}
void print_() //��������� ����Ѵ�.
{
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++)
			std::cout << cost[i][j] << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void print_2(int distance[max]) //distance�� ����Ѵ�.
{
	std::cout << "distance: ";
	for (int i = 0; i < max; i++)
		std::cout << distance[i] << " ";
	std::cout << std::endl;
}