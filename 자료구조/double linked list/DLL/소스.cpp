#include <iostream>
#include <cstdlib>
using namespace std;

typedef int EType;

class Node
{
private:
	EType item;
	Node* rLink;
	Node* lLink;
public:
	Node(void) : rLink(NULL), lLink(NULL) {}
	//Node(void)
	//{
	//	rLink = NULL;
	//	lLink = NULL;
	//}

	Node(EType inputItem) : item(inputItem), rLink(NULL), lLink(NULL) { }
	//Node(EType inputItem)
	//{
	//	item = inputItem;
	//	rLink = NULL;
	//	lLink = NULL;
	//}
	EType GetItem(void)
	{
		return item;
	}

	void SetRLink(Node* link)
	{
		rLink = link;
	}

	void SetLLink(Node* link)
	{
		lLink = link;
	}

	Node* GetLLink(void)
	{
		return lLink;
	}

	Node* GetRLink(void)
	{
		return rLink;
	}
	~Node() {}
};

class DoublyLinkedList
{
private:
	Node* head;

public:
	DoublyLinkedList(void) : head(NULL) {}

	void AddNode(EType item)
	{
		Node* newNode = new Node(item);
		if (head == NULL)
		{
			head = newNode;
			return;
		}
		Node* index = head;
		while (index->GetRLink() != NULL)
			index = index->GetRLink();
		index->SetRLink(newNode);
		newNode->SetLLink(index);
	}

	void DeleteNode(EType item)
	{
		Node* index = head;
		if (head == NULL)
			return;

		while (index->GetItem() != item)
			index = index->GetRLink();

		if (index == head && index->GetRLink() == NULL)  //지우려는 node가 head고 node갯수는 1개일 때
		{
			delete head;
			head = NULL;
		}

		else if (index == head)  //지우려는 node가 head일때
		{
			head = head->GetRLink();
			delete head->GetLLink();
			head->SetLLink(NULL);
		}

		else if (index->GetRLink() == NULL)  //지우려는 node가 맨 마지막 node일때
		{
			Node* temp = index->GetLLink();
			delete temp->GetRLink();
			temp->SetRLink(NULL);
		}

		else
		{
			index->GetLLink()->SetRLink(index->GetRLink());
			index->GetRLink()->SetLLink(index->GetLLink());
			delete index;
		}
	}

	void InsertNode(EType preItem, EType item)
	{
		if (head == NULL)
			return;
		Node* index = head;
		Node* newNode = new Node(item);
		while (index->GetItem() != preItem)
			index = index->GetRLink();

		if (index == head && index->GetRLink() == NULL)
		{
			head->SetRLink(newNode);
			newNode->SetLLink(head);
			return;
		}

		if (index->GetRLink() == NULL)
		{
			index->SetRLink(newNode);
			newNode->SetLLink(index);
			return;
		}

		else
		{
			index->GetRLink()->SetLLink(newNode);
			newNode->SetRLink(index->GetRLink());
			index->SetRLink(newNode);
			newNode->SetLLink(index);
		}
	}

	void PrintList(void)
	{
		if (head == NULL)
			return;
		Node* index = head;
		do
		{
			cout << index->GetItem() << " ";
			index = index->GetRLink();
		} while (index != NULL);

		cout << endl;
	}

	~DoublyLinkedList()
	{
		if (head != NULL)
		{
			Node* index = head;

			if (head->GetRLink() == NULL)  //node가 head 하나뿐일 경우
				delete head;
			do
			{
				index = index->GetRLink();
				delete index->GetLLink();
			} while (index->GetRLink() != NULL);
			delete index;
		}
	}
};



int main(int argc, char* argv[])
{
	DoublyLinkedList* l = new DoublyLinkedList();
	l->AddNode(1);
	l->AddNode(2);
	l->AddNode(3);
	l->AddNode(4);
	l->AddNode(5);
	l->PrintList();
	l->DeleteNode(3);
	l->PrintList();
	l->DeleteNode(1);
	l->PrintList();
	l->DeleteNode(5);
	l->PrintList();
	l->InsertNode(2, 10);
	l->PrintList();
	l->DeleteNode(2);
	l->DeleteNode(10);
	l->DeleteNode(4);
	delete l;
	return 0;
}