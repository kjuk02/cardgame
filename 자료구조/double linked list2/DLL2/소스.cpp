#include<iostream>

using namespace std;

class Node {
private:
	int data;
	Node* next = NULL;
	Node* prev = NULL;
	friend class List;
};
class List {
private:
	Node* head = NULL;
public:
	void insert(int num);
	void deleteNode(int num);
	bool isempty();
	void insearch(int num);
	void forwardList();
	void backwardList();
};
void List::forwardList()
{
	Node* p = NULL;

	if (isempty())
		cout << "not list" << endl;
	else
	{
		p = head;
		while (p!= 0)
		{
			cout << "data :" << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}
void List::backwardList()
{
	Node* p = NULL;

	if (isempty())
		cout << "not list" << endl;
	else
	{
		p = head;
		while (p->next!= 0)
		{
			p = p->next;
		}
		while (p!= 0)
		{
			cout << "data :" << p->data << " ";
			p = p->prev;
		}
		cout << endl;
	}
}
void List::insearch(int num)
{
	Node* p = NULL;
	Node* q = NULL;

	p = head;
	if (!isempty())
	{
		if (p->data == num)
		{
			cout << "found number" << p->data << endl;
		}
		else
		{
			while (p != 0 && p->data != num)
			{
				q = p;
				p = p->next;
			}
			if (p != 0)
			{
				cout << "foun number" << p->data << endl;
			}
			else
			{
				cout << "not list" << endl;
			}
		}
	}
	else
		cout << "List is empty" << endl;
}
void List::deleteNode(int num)
{
	Node* p = NULL;
	Node* q = NULL;
	p = head;
	if (!isempty())
	{
		if (p->data == num)
		{
			q = p;
			p = p->next;
			head = p;
			cout << "삭제 대상" << q->data << endl;
			delete q;
		}
		else
		{
			while (p != 0 && p->data != num)
			{
				q = p;
				p = p->next;
			}
			if (p != 0)
			{
				if (p->next != 0)
				{
					q->next = p->next;
					p->next->prev = q;
				}
				else
				{
					q->next = NULL;
				}
				cout << "삭제 대상" << p->data << endl;
				delete p;
			}
			else
			{
				cout << "not list" << endl;
			}
		}
	}
	else
	{
		cout << "LIst is Empty" << endl;
	}
}
void List::insert(int num)
{
	Node* p = NULL;
	Node* q = NULL;
	Node* temp = new Node();
	temp->data = num;

	if (head == 0)
		head = temp;
	else
	{
		p = head;
		if (temp->data <= head->data)
		{
			temp->next = p;
			p->prev = temp;
			head = temp;
		}
		else
		{
			while (p != 0 && temp->data > p->data)
			{
				q = p;
				p = p->next;
			}
			if (p != 0)
			{
				q->next = temp;
				temp->prev = q;
				temp->next = p;
				p->prev = temp;
			}
			else
			{
				q->next = temp;
				temp->prev = q;
			}
		}
	}
}
bool List::isempty()
{
	if (head == 0)
		return 1;
	else
		return 0;
}
int main()
{
	List mList;
	int num = 0, num2;
	char input[20];
	while (1)
	{
		cout << " ( 1. insert, 2. delete, 3. search, 4.forwardList, 5.backwardList, 6.quit ) " << endl;
		cin >> input;
		cout << endl;
		if (strcmp(input, "1") == 0)
		{
			cout << "넣고 싶은 수를 써주세요 : ";
			cin >> num;
			mList.insert(num);
			cout << "list에 " << num << "이 들어갔습니다." << endl;
		}
		else if (strcmp(input, "2") == 0)
		{
			cout << "지우고 싶은 수를 써주세요 : ";
			cin >> num;
			mList.deleteNode(num);
		}
		else if (strcmp(input, "3") == 0)
		{
			cout << "찾으시는 수를 써주세요 : ";
			cin >> num;
			mList.insearch(num);
		}
		else if (strcmp(input, "4") == 0)
		{
			mList.forwardList();
		}
		else if (strcmp(input, "5") == 0)
			mList.backwardList();
		else if (strcmp(input, "6") == 0)
		{
			cout << "프로그램을 종료 합니다. ";
			break;
		}
	}
	return 0;
}