#include<iostream>
#include<fstream>

#define Max 10
class Node{
	friend class list;
private:
	int vertex;
	Node* next;
public:
	Node(int value) :vertex(value), next(NULL) {}
	~Node(){}
};
class list {
private:
	Node* graph[Max];
	bool visited[Max];
	Node* front;
	Node* rear;
public:
	void listinit();
	void init2();
	void insert(int num1, int num2);
	void dfs(int v);
	void bfs(int v);
	void enqueue(int num);
	int dequeue();
};
void list::init2()
{
	for(int i=0;i<Max;++i)
	visited[i] = false;
}
void list::enqueue(int num)
{
	Node* ptr = new Node(num);
	if (front == NULL)
	{
		front = ptr;
		rear = ptr;
	}
	else
	{
		rear->next = ptr;
		rear = ptr;
	}
}
int list::dequeue()
{
	Node* ptr = front;
	int p;
	if (ptr == NULL)
		std::cout << "비어있습니다." << std::endl;
	else
	{
		p = ptr->vertex;
		front = front->next;
		delete(ptr);
	}
	return p;
}
void list::listinit()
{
	for (int i = 0; i < Max; ++i)
		graph[i] = NULL;
	front = NULL;
	rear = NULL;
}
void list::bfs(int v)
{
	Node* w;
	int h;
	visited[v] = true;
	std::cout << v << " ";
	enqueue(v);
	while (front)
	{
		h= dequeue();
		for (w=graph[h]; w; w = w->next)
		{
			if (!visited[w->vertex])
			{
				visited[w->vertex] = true;
				enqueue(w->vertex);
				std::cout << w->vertex << " ";
			}
		}
	}
}
void list::dfs(int v)
{
	Node* w;
	visited[v] = true;
	std::cout << v<<" " ;
	for (w = graph[v]; w; w = w->next)
	{
		if (!visited[w->vertex])
			dfs(w->vertex);
	}
}
void list::insert(int num1, int num2)
{
	if (graph[num1]==NULL)
	{
		Node* temp = new Node(num1);
		graph[num1] = temp;
	}
	if (graph[num2] == NULL)
	{
		Node* temp = new Node(num2);
		graph[num2] = temp;
	}
	Node* p = graph[num1];
	Node* temp1 = new Node(num2);
	while (p->next)
		p = p->next;
	p->next = temp1;
	
	p = graph[num2];
	Node* temp2 = new Node(num1);
	while (p->next)
		p = p->next;
	p->next = temp2;
}
int main()
{
	list mlist;
	std::ifstream instream;
	instream.open("input.txt");
	int num1, num2;
	mlist.listinit();
	mlist.init2();
	for (int i = 0; i < Max; ++i)
	{
		instream >> num1 >> num2;
		mlist.insert(num1, num2);
	}
	mlist.dfs(0);
	mlist.init2();
	std::cout << std::endl;
	mlist.bfs(0);
	instream.close();
	return 0;
}