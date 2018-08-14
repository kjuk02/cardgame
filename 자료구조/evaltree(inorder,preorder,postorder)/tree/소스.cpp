#include<iostream>
#include<string>
#include<cmath>
char prec[7][2] = { '^',3 ,'(',0,')',127,'*',2,'/',2,'+',1,'-',1 };
class Node {
private:
	char data = NULL;
	int priority = NULL;
	Node* left;
	Node* right;
	friend class Tree;
public:
	Node() {}
};
class Tree {
private:
	Node* head;
	int reverse = 0;
public:
	Tree() { head = NULL; }
	~Tree() {}
	void del();
	void delete_(Node* ptr);
	void insert(std::string input);
	void choice(char num);
	void operand(char value);
	int operator_(char value);
	void print(int num);
	void inorder(Node* ptr);
	void postorder(Node* ptr);
	void preorder(Node* ptr);
	void Evaluation();
	int evaltree(Node* ptr);
	int hw(char num);
	int hw2(char num);
};
void Tree::del()
{
	Node* ptr = head;
	delete_(ptr);
	std::cout << std::endl;
	head = NULL;
}
void Tree::delete_(Node* ptr)
{
	if (ptr == NULL)
		return;

	delete_(ptr->left);
	delete_(ptr->right);

	std::cout << " del Tree data : " << ptr->data;
	delete ptr;
}
void Tree::insert(std::string input)
{
	for (int i = 0; i < input.size(); i++)
		choice(input[i]);
}
int Tree::hw(char num)
{
	for (int i = 0; i < 7; i++)
		if (num == prec[i][0])
			return 1;

	return 0;
}
int Tree::hw2(char num)
{
	if ('0' <= num&&num <= '9')
		return 0;
	else
		return 1;
}
int Tree::evaltree(Node* ptr)
{
	int value = NULL;
	int left = NULL;
	int right = NULL;
	if (ptr != NULL)
	{
		if (hw(ptr->data) == 0)
			value = ptr->data - '0';
		else
		{
			left = evaltree(ptr->left);
			right = evaltree(ptr->right);

			switch (ptr->data)
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
			case'^':
				value = pow(left, right);
				break;
			default:
				std::cout << "요런건 없지요" << std::endl;
			}
		}
	}
	else
	{
		value = 0;
		return 0;
	}

	return value;
}
void Tree::Evaluation()
{
	Node* ptr = head;
	std::cout << "Evaluation : " << evaltree(ptr) << std::endl;
}
void Tree::choice(char num)
{
	if (num == prec[0][0] || num == prec[1][0] || num == prec[2][0] || num == prec[3][0] || num == prec[4][0] || num == prec[5][0] || num == prec[6][0])
		operator_(num);
	else
		operand(num);
}
void Tree::operand(char value)
{
	Node* temp = new Node();
	Node* p = NULL;
	temp->data = value;
	temp->priority = 126;
	if (head == NULL)
		head = temp;
	else
	{
		p = head;
		while (p->right != NULL)
			p = p->right;
		p->right = temp;
	}
}
int Tree::operator_(char value)
{
	Node* temp = new Node();
	Node* p = NULL;
	Node* q = NULL;
	int num = 0;
	temp->data = value;
	for (int i = 0; i < 7; i++)
	{
		if (value == prec[i][0])
		{
			temp->priority = prec[i][1];
			break;
		}
	}
	if (temp->priority == 0)
	{
		reverse += 3;
		return 0;
	}
	if (temp->priority == 127)
	{
		reverse -= 3;
		return 0;
	}
	p = head;
	if (reverse>0)
	{
		p = head;
		while (num != reverse&&p->right->priority != 126)
			p = p->right, num += 3;
		temp->priority += reverse;
		if (head == NULL)
			head = temp;
		else if (p->priority >= temp->priority)
		{
			temp->left = p;
			p = temp;
		}
		else
		{
			temp->left = p->right;
			p->right = temp;
		}
	}
	else
	{
		if (head->priority >= temp->priority)
		{
			temp->left = head;
			head = temp;
		}
		else
		{
			temp->left = head->right;
			head->right = temp;
		}
	}
	return 0;
}
void Tree::print(int num)
{
	Node* p = NULL;
	if (head == NULL)
		std::cout << "Not Tree Node";
	else if (num == 1)
	{
		std::cout << "Inorder Traversal :";
		p = head;
		inorder(p);
	}
	else if (num == 2)
	{
		std::cout << "PostOrder Traversal :";
		p = head;
		postorder(p);
	}
	else
	{
		std::cout << "Preorder Traversal :";
		p = head;
		preorder(p);
	}
	std::cout << std::endl;
}
void Tree::inorder(Node* ptr)
{
	if (ptr) {
		inorder(ptr->left);
		if (hw2(ptr->data) == 0)
			std::cout << ptr->data - '0';
		else
			std::cout << ptr->data;
		inorder(ptr->right);
	}
}
void Tree::postorder(Node* ptr)
{
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		if (hw2(ptr->data) == 0)
			std::cout << ptr->data - '0';
		else
			std::cout << ptr->data;
	}
}
void Tree::preorder(Node* ptr)
{
	if (ptr) {
		if (hw2(ptr->data) == 0)
			std::cout << ptr->data - '0';
		else
			std::cout << ptr->data;
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
int main()
{
	Tree mtree;
	std::string num;
	std::string input;
	while (1)
	{
		std::cout << " ( 1.insert, 2.Evaluation, 3.Inorder Traversal, 4.PostOrder Traversal, 5.Preorder Traversal ,6.Delete ,7.quit ) " << std::endl;
		std::cin >> input;
		std::cout << std::endl;
		if (input == "1")
		{
			std::cout <<"수식을 써주세요. : ";
			std::cin >> num;
			mtree.insert(num);
			std::cout << "Tree에 " << num << "이 들어갔습니다." << std::endl;
		}
		else if (input == "2")
			mtree.Evaluation();
		else if (input == "3")
			mtree.print(1);
		else if (input == "4")
			mtree.print(2);
		else if (input=="5")
			mtree.print(3);
		else if (input == "6")
			mtree.del();
		else if (input=="7")
		{
			std::cout << "프로그램을 종료 합니다. ";
			break;
		}
	}
	return 0;
}