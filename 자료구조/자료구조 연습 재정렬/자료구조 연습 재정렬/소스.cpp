#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;


class Node {
private:
	int data;
	Node *next;

	Node *prev;
public:
	Node()
	{
		this->data = 0;
		this->next = NULL;
		this->prev = NULL;
	}
	Node(int val)
	{
		this->data = val;
		this->prev = NULL;
		this->next = NULL;
	}
	friend class List;
};

class List {
private:
	Node* head;
public:
	List() {
		head = NULL;
	}

	void insertlist(int key);
	void deletelist(int key);
	void fowardlist();
	void backwardlist();
	void searchlist(int key);
	void displaylist();
	int isempty();
	void plus(List *l2);
	void set_insert(int data, int key);
	void set_insertt(int data, int key);
	Node *get_head();
	void bubble();
	int length();
	~List();

};
int List::length()
{
	Node* temp;

	int count = 0;
	if (head)
	{
		temp = head;
		do {
			count++;
			temp = temp->next;
		} while (temp != NULL);
	}
	return count;
}

void List::bubble()
{
	Node* p, *q;
	p = head;
	q = head;
	int temp;
	if (!isempty())
	{
		while (p->next != 0)
			p = p->next;
		while (p != 0)
		{
			while (q != p)
			{
				if (q->data >= q->next->data)
				{
					temp = q->data;
					q->data = q->next->data;
					q->next->data = temp;
				}
				q = q->next;
			}
			p = p->prev;
			q = head;
		}
	}
	else
		cout << "List is empty!!" << endl;
}
Node* List::get_head()
{
	return head;
}
void List::plus(List *l2)
{

	Node* temp = head;
	if (isempty())
	{
		if (l2->isempty())
		{
			head = NULL;
			return;
		}
		else
		{
			head = l2->get_head();
			return;
		}
	}
	else
	{
		if (!l2->isempty())
		{
			for (temp = head; temp->next; temp = temp->next);
			temp->next = l2->get_head();
			l2->get_head()->prev = temp;
		}
		else
			return;

	}
}
int List::isempty()
{
	if (head == 0)
		return 1;
	else
		return 0;
}
void List::insertlist(int key)
{
	Node* temp = new Node(key);
	Node*p, *q;
	if (head == 0)
		head = temp;
	else if (temp->data<head->data)
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else
	{
		p = head;
		q = head;
		while (p != 0 && temp->data>p->data)
		{
			q = p;
			p = p->next;

		}
		if (p != 0)
		{
			temp->next = p;
			temp->prev = q;
			q->next = temp;
			p->prev = temp;
		}
		else
		{
			q->next = temp;
			temp->prev = q;
		}
	}

}
void List::set_insert(int data, int key)
{
	Node* temp = new Node(data);
	Node*p, *q;
	int i = 0;
	if (key == 0)

	{
		if (head == 0) {
			cout << "List is empty!!" << endl;
			return;
		}
		else
		{
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
	}
	else
	{
		p = head;
		q = head;
		while (p != 0 && key>i)
		{
			q = p;
			p = p->next;
			i++;
		}
		if (p != 0)
		{
			temp->next = p;
			temp->prev = q;
			q->next = temp;
			p->prev = temp;
		}
		else
		{
			q->next = temp;
			temp->prev = q;
		}
	}

}
void List::set_insertt(int data, int key)
{
	Node* temp = new Node(data);
	Node*p, *q;
	int i = 0;
	if (key == 0)

	{
		if (head == 0) {
			cout << "List is empty!!" << endl;
			return;
		}
		else
		{
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
	}
	else
	{
		p = head;
		q = head;
		while (p != 0 && (key - 1)>i)
		{
			q = p;
			p = p->next;
			i++;
		}
		if (p != 0)
		{
			temp->next = p;
			temp->prev = q;
			q->next = temp;
			p->prev = temp;
		}
		else
		{
			q->next = temp;
			temp->prev = q;
		}
	}

}
void List::deletelist(int key)
{
	Node *p, *q;
	if (head == 0)
		cout << "List is empty!!" << endl;
	else
	{
		if (head->data == key)
		{
			if (head->next != 0)
			{
				p = head; head = head->next; head->prev = NULL;

				delete p;
			}
			else
				head = 0;
		}
		else
		{
			q = head; p = head;

			while (p != 0 && p->data != key)
			{
				q = p; p = p->next;

			}
			if (p != 0)
			{
				if (p->next != 0)
				{
					q->next = p->next;
					p->next->prev = q;
					delete p;
				}
				else
				{
					q->next = NULL;
					delete p;
				}
			}
			else
				cout << key << "is not in the list" << endl;
		}

	}
}
void List::fowardlist()
{
	if (!isempty())
	{
		Node *p = head;
		cout << "------Forward list---------" << endl;
		while (p != 0)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else
		cout << "List is empty" << endl;

}
void List::backwardlist()
{
	if (!isempty())
	{
		Node* p = head;
		cout << "----------Backward list---------" << endl;
		while (p->next != 0)
			p = p->next;
		while (p != 0)
		{
			cout << p->data << " ";
			p = p->prev;
		}
		cout << endl;
	}
	else
		cout << "List is empty" << endl;
}
void List::searchlist(int key)
{
	if (!isempty())
	{
		Node *p = head;

		while (p != 0 && p->data != key)
		{
			p = p->next;

		}

		if (p != 0)
			cout << p->data << " is in the list" << endl;
		else
			cout << key << " is not in the list" << endl;
	}
	else
		cout << "List is empty" << endl;
}
List::~List()
{
	Node *p;
	while (head != 0)
	{
		p = head;
		head = head->next;
		delete p;
	}
}
int main()
{
	List l, l2;
	char input[20];
	int num, s, x;
	while (1)
	{
		cout << "Enter command(length,bub,se,in,in2,pop1,exit,back1,fo1,in2):";
		cin >> input;
		if (strcmp(input, "in") == 0)
		{

			cin >> num;
			l.insertlist(num);

		}
		else if (strcmp(input, "in1") == 0) {
			cin >> num >> s;
			l.set_insert(num, s);
		}
		else if (strcmp(input, "in2") == 0) {
			cin >> num >> s;
			l.set_insertt(num, s);
		}
		else if (strcmp(input, "length") == 0)
		{

			x = l.length();
			cout << x << endl;
		}
		else if (strcmp(input, "se") == 0)
		{
			cin >> num;
			l.searchlist(num);
		}
		else if (strcmp(input, "bub") == 0)
		{
			l.bubble();
		}
		else if (strcmp(input, "pop1") == 0)
		{
			cin >> num;
			l.deletelist(num);

		}


		else if (strcmp(input, "fo1") == 0)

			l.fowardlist();

		else if (strcmp(input, "back1") == 0)

			l.backwardlist();

		else  if (strcmp(input, "p1") == 0)
		{

			cin >> num;
			l.insertlist(num);
		}
		else if (strcmp(input, "s1") == 0)
		{
			cin >> num;
			l.searchlist(num);
		}
		else if (strcmp(input, "pop1") == 0)
		{
			cin >> num;
			l.deletelist(num);

		}
		else if (strcmp(input, "fo1") == 0)
			l.fowardlist();
		else if (strcmp(input, "back1") == 0)
			l.backwardlist();
		else if (strcmp(input, "exit") == 0)
		{
			l.~List();
			exit(0);
		}
		else
			cout << "Bad Command!" << endl;
	}
	return 0;
}