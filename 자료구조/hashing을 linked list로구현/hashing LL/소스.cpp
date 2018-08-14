#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;

const int SIZE = 10;
const int divi = 10;

class Node {
	int data;
	Node *next;
	friend class Hash;
};
class Hash {
private:
	Node *head[SIZE];
	int key;
public:
	Hash()
	{
		for (int i = 0; i<SIZE; i++)
			head[i] = 0;
		
	 key = 0;
	}
	void insert_(int value)
	{
		Node *temp = new Node();
		Node *p;
		temp->data = value;
		key = value%divi;
		if (head[key] == 0)
		{
			head[key] = temp;
		}
		else
		{
			p = head[key];
			while (p->next != 0)
			{
				p = p->next;
			}
			p->next = temp;
		}
	}
	void delete_(int value)
	{
		key = value%divi;
		Node *p, *q;
		p = NULL;
		q = NULL;
		if (head[key]->data == value)
		{
			p = head[key];
			head[key] = head[key]->next;
			delete p;
		}
		else
		{
			p = head[key];
			while (p != 0 && p->data != value)
			{
				q = p;
				p = p->next;
			}
			if (p != 0)
			{
				q->next = p->next;
				delete p;
			}
			else
				cout << value << "없다" << endl;
		}
	}

	void search_(int value)
	{
		key = value%divi;
		Node *p;
		if (head[key] != 0)
		{
			p = head[key];
			while (p->next != 0 && p->data != value)
				p = p->next;
			if (p->data == value)
				cout << p->data << "는" << key << "테이블에 있다" << endl;
			else if (p->next == 0)
				cout << value << "는" << key << "테이블에 없다" << endl;
		}
		else
			cout << "테이블이 빔" << endl;
	}

	void printtable()
	{
		Node *p;
		for (int i = 0; i<SIZE; i++)
		{
			if (head[i] != 0)
			{
				p = head[i];
				while (p != 0)
				{
					cout << p->data << " ";
					p = p->next;
				}
			}
			else
				cout << "Empty";

			cout << endl;
		}


	}
};


int main()
{
	Hash h;

	h.insert_(1);
	h.insert_(2);
	h.insert_(3);
	h.insert_(4);
	h.insert_(11);
	h.insert_(14);
	h.insert_(24);
	h.delete_(14);
	h.search_(14);
	h.printtable();
	return 0;
}
