#include <iostream>
#include<cstdlib>
#include<string>

using namespace std;

class Node
{
private:
	string data;
	Node* next = NULL;
	//friend class List;
	friend class List;
public:
};
class List
{
private:
	Node* head;
	Node* head2;
	Node* front;
	Node* rear;
public:
	List()
	{
		head = NULL;
		front = NULL;
		rear = NULL;
	}
	void insert(string num);
	void deleteNode();
	bool isEmpty();
	void printList();
	void invert();
	void concatenate();
	void concatenate_list();
	int Queue_isEmpty();
	void enqueue(string num);
	void dequeue();
	void displayQueue();

};
void List::deleteNode()
{
	Node * p = NULL;
	if (head == 0)
		cout << "empty" << endl;
	else
	{
		p = head;
		head = head->next;
		cout << p->data << "삭제되었습니다." << endl;
		delete p;
	}
}
void List::invert() /* head가 가리키고 있는 리스트를 역순으로 만든다. */
{
	Node* middle = NULL;
	Node* trail = NULL;
	while (head2)
	{
		trail = middle;
		middle = head2;
		head2 = head2->next;
		middle->next = trail;
	}
	head2 = middle;
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
bool List::isEmpty()
{
	if (head == 0)
		return true;
	else
		return false;
}
void List::insert(string num)
{
	Node *temp = new Node();
	Node* p = NULL;
	Node* q = NULL;
	temp->data = num;
	if (head == NULL)
	{
		head = temp;
	}
	else /*if (temp->data < head->data)*/
	{
		temp->next = head;
		head = temp;
	}
	//else
	//{
	//	p = head;
	//	while ((p != 0) && (temp->data > p->data))
	//	{
	//		q = p;
	//		p = p->next;
	//	}
	//	if (p != 0)
	//	{
	//		temp->next = p;
	//		q->next = temp;
	//	}
	//	else
	//		q->next = temp;
	//}
}
void List::concatenate()/* 리스트 ptr1 뒤에 리스트 ptr2가 접합된 새 리스트를 생성한다.     ptr1이 가리키는 리스트는 영구히 바뀐다.*/
{
	Node* p = NULL;
	Node* q = NULL;
	Node* temp = NULL;
	temp = front;
	if (head == 0)
		head = temp;
	else
	{
		p = head;
		while (p->next != 0)
			p = p->next;
		p->next = temp;
	}
	p = head;
	while (p != 0)
	{
		string s;
		s = p->data;

		Node* temp = new Node();
		Node* p2 = NULL;
		Node* q2 = NULL;
		temp->data = s;
		if (head2 == NULL)
		{
			head2 = temp;
		}
		else if (temp->data < head2->data)
		{
			temp->next = head2;
			head2 = temp;
		}
		else
		{
			p2 = head2;
			while ((p2 != 0) && (temp->data > p2->data))
			{
				q2 = p2;
				p2 = p2->next;
			}
			if (p2 != 0)
			{
				temp->next = p2;
				q2->next = temp;
			}
			else
				q2->next = temp;
		}

		p = p->next;
	}
}
void List::concatenate_list()
{
	Node *p = NULL;
	if (!isEmpty()) {
		p = head2;
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
void List::enqueue(string num)
{
	Node *temp = new Node;
	temp->data = num;
	if (front == 0)
	{
		front = temp;
		rear = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
	cout << temp->data << "가 List에 들어갑니다." << endl;
}
void List::dequeue()
{
	Node *p;

	p = front;

	if (front == rear)
	{
		front = 0;   rear = 0;
	}
	else
		front = front->next;

	cout << p->data << "삭제되었습니다." << endl;
	delete p;
}
void List::displayQueue()
{
	Node* p;

	if (!isEmpty())
	{
		cout << "LIst:";
		p = front;
		while (p)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else  cout << "Queue is empty!\n";
}
int List::Queue_isEmpty()
{
	if (front == 0)
		return 1;
	else
		return 0;
}
int main(void)
{
	List mlist;
	string num;
	char input[20];
	while (1)
	{
		cout << " ( 1. push, 2. pop, 3. stackdiplay, 4. enqueue, 5. dequeue, 6. queuedisplay, 7. concat, 8. concatdisplay, 9. concatdisplay_invert ,10. exit ) " << endl;
		cin >> input;
		cout << endl;
		if (strcmp(input, "1") == 0)
		{
			cout << "넣고 싶은 문자를 써주세요 : ";
			cin >> num;
			mlist.insert(num);
			cout << "list에 " << num << "이 들어갔습니다." << endl;
		}
		else if (strcmp(input, "2") == 0)
			mlist.deleteNode();
		else if (strcmp(input, "3") == 0)
		{
			cout << "List를 전부 출력합니다" << endl;
			mlist.printList();
		}
		else if (strcmp(input, "4") == 0)
		{
			cout << "넣고 싶은 문자를 써주세요.:";
			cin >> num;
			mlist.enqueue(num);
		}
		else if (strcmp(input, "5") == 0)
			mlist.dequeue();
		else if (strcmp(input, "6") == 0)
		{
			cout << "List를 전부 출력합니다" << endl;
			mlist.displayQueue();
		}
		else if (strcmp(input, "7") == 0)
			mlist.concatenate();
		else if (strcmp(input, "8") == 0)
		{
			mlist.concatenate_list();
		}
		else if (strcmp(input, "9") == 0)
		{
			mlist.invert();
			mlist.concatenate_list();
		}
		else if (strcmp(input, "10") == 0)
		{
			exit(1);
		}
	}
	return 0;
}