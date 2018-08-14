#include <iostream>

using namespace std;

class Node
{
private:
	int data;
	Node* next;
	Node* prev;
	friend class List;
};

class List
{
private:
	Node* head;
public:
	List()
	{
		head = 0;
	}
	//~List();
	void insertNode(int num);
	void deleteNode(int num);
	bool isEmpty();
	void searchList(int num);
	void forwardList();
	void backwardList();
	void insertbefore(int num, int data);
	void insertafter(int num, int data);
	int length(int num);
	void length2(int num);
	void printlist();
	void deletelength(int num);
	void Re_position();
	int length3();
};
int List::length3()
{
	Node *p = NULL;
	int count = 1;
	if (!isEmpty()) {
		p = head;
		while (p) {
			p = p->next;
			count++;
		}
		return count;
	}
}
void List::Re_position()
{
	Node* temp = NULL;
	Node* p = NULL;
	Node* q = NULL;
	Node* s = NULL;
	int count = length3();
	if (length3() > 1)
	{
		for (int i = 0; i < length3() - 2; i++)
		{
			for (int j = 0; j < length3() - 2; j++)
			{
				p = head;
				int k = 0;
				while (k != j)
				{
					q = p;
					p = p->next;
					k++;
				}
				if ((p->data > p->next->data) && p == head)
				{
					temp = p->next;
					p->next = temp->next;
					p->prev = temp;
					head = temp;
					temp->next = p;
				}
				else {
					while (p->data > p->next->data)
					{
						temp = p->next;
						p->next = temp->next;
						p->prev = temp;
						q->next = temp;
						temp->prev = q;
						temp->next = p;
						q = temp;
						if (p->next == NULL)
							break;
					}
				}
			}
		}

	}
	else
		cout << "숫자가 하나뿐이여" << endl;
}
void List::deletelength(int num)
{
	int data = length(num);
	Node *p = NULL;
	Node *q = NULL;
	if (head == 0)
	{
		cout << "List is empty" << endl;
	}
	else {
		if (head->data == data)
		{
			if (head->next != 0)
			{
				p = head;
				head = head->next;
				head->prev = 0;
				delete p;
			}
			else
				head = 0;
		}
		else {
			p = head;
			while (p != 0 && p->data != data) {
				q = p;
				p = p->next;
			}
			if (p != 0 && p->next != NULL) {
				q->next = p->next;
				p->next->prev = q;
				delete p;
			}
			else if (p != 0 && p->next == NULL)
			{
				q->next = NULL;
				delete p;
			}
			else
				cout << num << " is not in the list\n";
		}
	}
}
void List::length2(int num)
{
	int count = 1;
	Node *p = NULL;
	if (!isEmpty())
	{
		p = head;
		while (p !=0 && count !=num)
		{
			p = p->next;
			count++;
		}
		if (p != 0)
		{
			cout << "found:" << count << " " << "value: " << p->data << endl;
		}
		else
		{
			cout << "List is empty!\n";
		}
	}
	else
		cout << "List is empty!\n";
}
void List::printlist()
{
	int count = 1;
	Node *p = NULL;
	if (!isEmpty())
	{
		p = head;
		cout << "-----  Print List  -----\n";
		while (p != 0)
		{
			cout << "now position: " << count << " " << "value: " << p->data << endl;
			p = p->next;
			count++;
		}
	}
	else
		cout << "List is empty!\n";
}
void List::insertafter(int num, int data)
{
	Node* temp = new Node();
	temp->data = data;
	Node* p = NULL;
	Node* q = NULL;
	if (num == 1)
	{
		if (head != 0)
		{
			p = head;
			temp->next = p;
			p->prev = temp;
			head = temp;
		}
		else
			head = temp;
	}
	else
	{
		if (head == 0)
		{
			cout << "List is empty" << endl;

		}
		else
		{
			if (length(num) == 0)
			{
				cout << "not position " << endl;
			}
			else {
				q = head;
				p = head;
				while (p != 0 && p->data != length(num))
				{
					p=p->next;
					q=p->next;
				}
				if (q != 0) {
					temp->next = q;
					temp->prev = p;
					p->next = temp;
					q->prev = temp;
				}
				else
				{
					p->next = temp;
					temp->prev = p;
					temp->next = NULL;
				}
			}
		}
	}
	cout << temp->data << endl;
}
void List::insertbefore(int num, int data)
{
	Node* temp = new Node();
	temp->data = data;
	Node* p = NULL;
	Node* q = NULL;
	if (num == 1)
	{
		if (head != 0)
		{
			p = head;
			temp->next = p;
			p->prev = temp;
			head = temp;
		}
		else
			head = temp;
	}
	else
	{
		if (head == 0)
		{
			cout << "List is empty" << endl;

		}
		else
		{
			if (length(num) == 0)
			{
				cout << "not position " << endl;
			}
			else {
				p = head;
				while (p != 0 && p->data != length(num))
				{
					q = p;
					p = p->next;
				}
				if (p != 0) {
					temp->next = p;
					temp->prev = q;
					p->prev = temp;
					q->next = temp;
				}
				else
				{
					q->next = temp;
					temp->prev = q;
					temp->next = NULL;
				}
			}
		}
	}
	cout << temp->data << endl;
}
int List::length(int num)
{
	Node* p = NULL;
	int count = 1;
	if (head != 0)
	{
		p = head;
		while (p != 0 && count != num)
		{
			p = p->next;
			count++;
		}
		if (p != 0)
			return p->data;
		else
			return 0;
	}
}
void List::forwardList()
{
	Node *p = NULL;
	if (!isEmpty())
	{
		p = head;
		cout << "-----  Forward List  -----\n";
		while (p != 0)
		{
			cout << p->data <<" ";
			p = p->next;
		}
		cout << endl;
	}
	else
		cout << "List is empty!\n";
}
void List::backwardList()
{
	if (!isEmpty())
	{
		Node* p;
		p = head;
		while (p->next != 0)
			p = p->next;
		cout << "----- Backward List -----\n";
		while (p != 0)
		{
			cout << p->data << " ";
			p = p->prev;
		}
		cout << endl;
	}
	else
		cout << "List is empty!\n";
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
	Node* p = NULL;

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
	Node* temp = new Node();
	temp->data = num;
	Node* p = NULL;
	Node* q = NULL;
	if (head == 0)
	{
		head = temp;
	}
	else if (temp->data <= head->data) {
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else
	{
		p = head;
		while ((p != 0) && (p->data < temp->data))
		{
			q = p;
			p = p->next;
		}
		if (p != 0) {
			temp->next = p;
			temp->prev = q;
			p->prev = temp;
			q->next = temp;
		}
		else
		{
			q->next = temp;
			temp->prev = q;
			temp->next = NULL;
		}
	}
	cout << temp->data << endl;
}
void List::deleteNode(int num)
{
	Node *p = NULL;
	Node *q = NULL;
	if (head == 0)
	{
		cout << "List is empty" << endl;
	}
	else {
		if (head->data == num)
		{
			if (head->next != 0)
			{
				p = head;
				head = head->next;
				head->prev = 0;
				delete p;
			}
			else
				head = 0;
		}
		else {
			p = head;
			while (p != 0 && p->data != num) {
				q = p;
				p = p->next;
			}
			if (p != 0 && p->next != NULL) {
				q->next = p->next;
				p->next->prev = q;
				delete p;
			}
			else if (p != 0 && p->next == NULL)
			{
				q->next = NULL;
				delete p;
			}
			else
				cout << num << " is not in the list\n";
		}
	}
}
int main(void)
{
	List mList;
	int num = 0, num2;
	char input[20];
	while (1)
	{
		cout << " ( 1. insert, 2. delete, 3. search, 4.forwardList, 5.backwardList, 6.insertbefore, 7.insertafter ,8.length ,9.lengthdelete ,10.RE_postion, 11.quit ) " << endl;
		cin >> input;
		cout << endl;
		if (strcmp(input, "1") == 0)
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
			mList.forwardList();
		else if (strcmp(input, "5") == 0)
			mList.backwardList();
		else if (strcmp(input, "6") == 0)
		{
			mList.printlist();
			cout << "넣고 싶은 위치와 숫자를 써주세요" << endl;
			cout << "넣고 싶은 위치 :" << " ";
			cin >> num2;
			cout << "넣고 싶은 숫자 :" << " ";
			cin >> num;
			mList.insertbefore(num2, num);
		}
		else if (strcmp(input, "7") == 0)
		{
			mList.printlist();
			cout << "넣고 싶은 위치와 숫자를 써주세요" << endl;
			cout << "넣고 싶은 위치 :" << " ";
			cin >> num2;
			cout << "넣고 싶은 숫자 :" << " ";
			cin >> num;
			mList.insertafter(num2, num);
		}
		else if (strcmp(input, "8") == 0)
		{
			cout << "찾으시는 위치를 써주세요 : ";
			cin >> num;
			mList.length2(num);
		}
		else if (strcmp(input, "9") == 0)
		{
			mList.printlist();
			cout << "삭제를 원하는 위치를 써주세요 : ";
			cin >> num;
			mList.deletelength(num);
		}
		else if (strcmp(input, "10") == 0)
		{
			mList.Re_position();
		}
		else if (strcmp(input, "11") == 0)
		{
			cout << "프로그램을 종료 합니다. ";
			break;
		}
	}

	return 0;
}