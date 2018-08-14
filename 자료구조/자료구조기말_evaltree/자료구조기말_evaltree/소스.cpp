#include<iostream>
char prec[5][2] = { '^',3,'*',2,'/',2,'+',1,'-',1 };
class Node {
private:
	char data;
	int prio;
	Node *left; 
	Node *right;
	Node(char value) :data(value),prio(100), left(NULL), right(NULL) {}
	Node(char value, int prio_) :data(value), prio(prio_), left(NULL), right(NULL) {}
	friend class Tree;
};
class Tree {
private:
	Node *root;
public:
	void evalprint();
	void print(int num);
	void choice(char num);
	void operator_(char num,int prio);
	void operand_(char num);
	int evalTree(Node* p);
	int check(char num);
	void inorder(Node* ptr);
	void postorder(Node* ptr);
	void preorder(Node* ptr);
	Tree() { root = 0; }
	~Tree() {};
};
void Tree::evalprint()
{
	Node* ptr = root;
	if (ptr != NULL)
	{
		std::cout << evalTree(ptr) << std::endl;
	}
	else
		std::cout << "입력됀 수식이 업습니다." << std::endl;
}
int Tree::check(char num)
{
	for (int i = 0; i < 5; ++i)
	{
		if (prec[i][0] == num)
			return 0;
	}
	return 1;
}
int Tree::evalTree(Node* p)
{
	int value=0;
	int left=0;
	int right=0;
	if (p != NULL)
	{
		if (check(p->data))
			value = p->data - '0';
		else
		{
			left = evalTree(p->left);
			right = evalTree(p->right);
			switch (p->data)
			{
				case '+': 
					value = left + right;
					break;
				case '-': 
					value = left - right;
					break;
				case '*': 
					value = left*right;
					break;
				case '/': 
					value = left / right;
					break;
			}
		}
	}
	return value;
}
void Tree :: choice(char num)
{
	for (int i = 0; i < 5; ++i)
		if (prec[i][0] == num)
		{
			operator_(num,prec[i][1]);
			return;
		}
	operand_(num);
}
void Tree::operand_(char num)
{
	Node* temp = new Node(num);
	if (root == NULL)
		root = temp; 
	else
	{
		Node* p = root;
		while (p->right != NULL)
			p = p->right;
		p->right = temp;
	}
}
void Tree::operator_(char num,int prio)
{
	Node* temp = new Node(num,prio);
	Node* p = root;
	if (root->prio >= temp->prio)
	{
		temp->left = root;
		root = temp;
	}
	else
	{
		temp->left = root->right;
		root->right = temp;
	}
}
void Tree::print(int num)
{
	Node* ptr = root;
	switch (num)
	{
		case 0:
			inorder(ptr);
			break;
		case 1:
			postorder(ptr);
			break;
		case 2:
			preorder(ptr);
			break;
		defalut:
			std::cout << "그런거 없어요" << std::endl;
	}
	std::cout << std::endl;
}
void Tree::inorder(Node *ptr)
{
	if (ptr) {
			inorder(ptr->left);
			std::cout << ptr->data;
			inorder(ptr->right);
	} 
}
void Tree::postorder(Node *ptr)
{
	if (ptr)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		std::cout << ptr->data;
	}
}
void Tree::preorder(Node *ptr)
{
	if (ptr)
	{
		std::cout << ptr->data;
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
int main()
{
	Tree MTree;
	MTree.choice('8');
	MTree.choice('+');
	MTree.choice('9');
	MTree.choice('-');
	MTree.choice('2');
	MTree.choice('*');
	MTree.choice('3');
	MTree.print(0);
	MTree.print(1);
	MTree.print(2);
	MTree.evalprint();
	return 0;
}