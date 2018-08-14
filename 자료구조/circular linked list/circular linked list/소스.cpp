#include <iostream>
#include<cstdlib>

using namespace std;

class Node
{
private:
	int data;
	Node* link = NULL;
	friend class List;
public:

};

class List
{
private:
	Node* head;
public:
	List()
	{
		head = NULL;
	}
	//~List();
	Node* concatenate(Node* mList2);
	Node* thisNode();
	Node* split(Node* mList2, int data);
	void invert();
	void insertNode(int num);
	void deleteNode();
	bool isEmpty();
	void printList();
	void split_printList();
	void searchList(int num);
	void length();
	void search_deleteNode(int num);
	~List()
	{
	}
};
Node* List::split(Node* mList2, int data)
{
	Node* p = NULL;
	Node* q = NULL;
	Node* temp = NULL;
	temp = head;
	while (temp)
	{
		if (temp->data == data)
		{
			p = temp;
			q = temp->link;
			p->link = head->link;
			head->link = q;
			break;
		}
		temp = temp->link;
	}
	return mList2 = p;
}
Node* List::thisNode()
{
	return head;
}
Node* List::concatenate(Node* mList2)/* 리스트 ptr1 뒤에 리스트 ptr2가 접합된 새 리스트를 생성한다.     ptr1이 가리키는 리스트는 영구히 바뀐다.*/
{
	Node* p = NULL;
	Node* q = NULL;
	if (head == 0)
		return mList2;
	else
	{
		p = head->link;
		head->link = mList2->link;
		mList2->link = p;
		return head;
	}
}
void List::invert() /* head가 가리키고 있는 리스트를 역순으로 만든다. */
{
	Node* middle = NULL;
	Node* trail = NULL;
	while (head)
	{
		trail = middle;
		middle = head;
		head = head->link;
		middle->link = trail;
	}
	head = trail;
}

void List::length()
{
	Node* temp = NULL;
	int count = 0;

	if (head)
	{
		temp = head;
	}
	do
	{
		count++;
		temp = temp->link;
	} while (temp != head);
	cout << count << endl;
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

	if (head != NULL)
	{
		p = head;
		while (p != 0 && p->data != num)
		{
			p = p->link;
			if (p == head)
				p = 0;
		}
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
	if (head == NULL)
	{
		head = temp;
		head->link = temp;
	}
	else
	{
		temp->link = head->link;
		head->link = temp;
	}
	cout << temp->data << endl;
}

void List::printList()
{
	Node *p = NULL;
	if (!isEmpty()) {
		p = head;
		cout << "List: ";
		do {
			cout << p->data << " ";
			p = p->link;
		} while (p != head);
		cout << endl;
	}
	else
		cout << "List is empty!\n";
}
void List::deleteNode()
{
	Node *p = NULL;
	if (head == NULL)
		cout << "List is empty!\n";
	else {
		if (head->link != head)
		{
			p = head->link;
			head->link = p->link;
			cout << p->data << "을 삭제합니다." << endl;
			delete[] p;
		}
		else
			cout << "List in only head\n";
	}
}
void List::search_deleteNode(int num)
{
	Node *p = NULL;
	if (head == NULL)
		cout << "List is empty!\n";
	else {
		if (head->link != head)
		{
			p = head->link;
			head->link = p->link;
			cout << p->data << "을 삭제합니다." << endl;
			delete[] p;
		}
		else
			cout << "List in only head\n";
	}
}
int main(void)
{
	List mList;
	List mList2;
	int num = 0;
	char input[20];
	while (1)
	{
		cout << " ( 1. insert, insert2 concatenate split split_list2. delete, 3. list, 4. search, 5.length, 6.invert, .quit) " << endl;
		cin >> input;
		cout << endl;
		if (strcmp(input, "insert") == 0)
		{
			cout << "넣고 싶은 수를 써주세요 : ";
			cin >> num;
			mList.insertNode(num);
			cout << "list에 " << num << "이 들어갔습니다." << endl;
		}
		else if (strcmp(input, "insert2") == 0)
		{
			cout << "넣고 싶은 수를 써주세요 : ";
			cin >> num;
			mList2.insertNode(num);
			cout << "list에 " << num << "이 들어갔습니다." << endl;
		}
		else if (strcmp(input, "split") == 0)
		{
			cout << "분리하고싶은숫자를 넣어주세요 : ";
			cin >> num;
			mList.split(mList2.thisNode(), num);
		}
		else if (strcmp(input, "split_list") == 0)
		{
			mList2.printList();
		}
		else if (strcmp(input, "concatenate") == 0)
		{
			mList.concatenate(mList2.thisNode());
		}
		else if (strcmp(input, "delete") == 0)
			mList.deleteNode();
		else if (strcmp(input, "invert") == 0)
		{
			cout << "List를 역순으로 바꿔줍니다." << endl;
			mList.invert();
		}
		else if (strcmp(input, "search") == 0)
		{
			cout << "찾으시는 수를 써주세요 : ";
			cin >> num;
			mList.searchList(num);
		}
		else if (strcmp(input, "list") == 0)
		{
			cout << "리스트를 전부 출력합니다" << endl;
			mList.printList();
		}
		else if (strcmp(input, "length") == 0)
		{
			cout << "총 길이를 출력합니다." << endl;
			mList.length();
		}
		else if (strcmp(input, "quit") == 0)
		{
			cout << "프로그램을 종료 합니다. ";
			exit(1);
		}
	}

	return 0;
}