#include <iostream>

using namespace std;

class Node
{
private:
	int data;
	Node *next;
	friend class List;
};

class List
{
private:
	Node *head;
public:
	List()
	{
		head = 0;
	}
	//~List();
	void insertNode(int num);
	void deleteNode(int num);
	bool isEmpty();
	void printList();
	void searchList(int num);
	void range();
	void invert();
};
void List::invert()
{
	Node* middle = NULL;
	Node* trail = NULL;

	while (head != 0)
	{
		trail = middle;
		middle = head;
		head = head->next;
		middle->next = trail;
	}
	head = middle;
}
void List::range()
{
	Node* p = NULL;
	Node* q = NULL;
	Node* s = NULL;
	int temp = 0;
	Node* temp2 = NULL;
	p = head;
	q = head;
	if (!isEmpty())
	{
		while (p ->next!= 0)
			p = p->next;
		
		temp2 = p;
		while (temp2!=head)
		{
			while (q != temp2)
			{
				if (q->data > q->next->data)
				{
					temp = q->next->data;
					q->next->data = q->data;
					q->data = temp;
				}
				s = q;
				q = q->next;
			}
			temp2 = s;
			q = head;
		}
	}
	else
		cout << "List is empty!!" << endl;
}
bool List::isEmpty()
{
	if (head == 0)
		return true;
	else
		return false;
}

void List::searchList(int num)
{
	Node *p = NULL;

	if (head != 0)
	{
		p = head;
		while (p != 0 && p->data != num)
			p = p->next;

		if (p)
			cout << p->data << " is found" << endl;
		else
			cout << num << " is not in the list." << endl;
	}
	else
		cout << "List is empty" << endl;
}
void List::insertNode(int num)
{
	Node *temp = new Node();
	temp->data = num;
	Node *p = new Node();
	Node *q = new Node();
	p = NULL;
	q = NULL;
	if (head == 0)
	{
		head = temp;
	}
	else 
	{
		temp->next = head;
		head = temp;
	}
	cout << temp->data << endl;
}

void List::printList()
{
	Node *p = NULL;
	if (!isEmpty()) {
		p = head;
		cout << "List: ";
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else
		cout << "List is empty!\n";
}
void List::deleteNode(int num)
{
	Node *p = NULL;
	Node *q = NULL;

	if (head != 0 && head->data == num)
	{
		p = head;
		head = head->next;
		delete p;
	}
	else {
		p = head;
		while (p != 0 && p->data != num) {
			q = p;
			p = p->next;
		}
		if (p != 0) {
			q->next = p->next;
			delete p;
		}
		else
			cout << num << " is not in the list\n";
	}
}


int main(void)
{
	List mList;
	int num = 0;
	char input[20];
	while (1)
	{
		cout << " ( 1. insert, 2. delete, 4. list, 3. search, 5.quit 6.range 7.invert) " << endl;
		cin >> input;
		cout << endl;
		if (strcmp(input, "1")== 0)
		{
			cout << "넣고 싶은 수를 써주세요 : ";
			cin >> num;
			mList.insertNode(num);
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
			mList.searchList(num);
		}
		else if (strcmp(input, "4") == 0)
		{
			cout << "리스트를 전부 출력합니다" << endl;
			mList.printList();
		}
		else if (strcmp(input, "5") == 0)
		{
			cout << "프로그램을 종료 합니다. ";
			break;
		}
		else if (strcmp(input, "6") == 0)
		{
			mList.range();
		}
		else if (strcmp(input, "7") == 0)
		{
			mList.invert();
		}
	}

	return 0;
}