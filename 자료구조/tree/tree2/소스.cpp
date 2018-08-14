#include<iostream>
#include<string>
class Node { //Node ���� right,left,data�� �ִ�.
private:
	int data;
	Node* right;
	Node* left;
	friend class Tree;
public:
	Node() {}
	~Node() {}
};
class Tree { //tree���� root�� �Ѱ����� count
private:
	Node* root;
	int first = 0;
	int count = 0;
public:
	void insert_(int data); //insert �Լ�
	Node* insert_BST(Node* ptr, int data); //insert ����Լ�
	void search_(int data); //search �Լ�
	Node* search_BST(Node* ptr, int data); //search ����Լ�
	void delete_(int data); //delete �Լ�
	Node* delete_BST(Node* ptr, int data);//delete ����Լ�
	Node* find_min(Node* ptr);//���� ���� �� ã��
	Node* find_max(Node* ptr);//���� ū �� ã��
	void drawTree(); //Ʈ�� �׸��� �Լ�
	void drawTree_BST(Node* ptr, int level); //Ʈ�� �׸��� ����Լ�
};
void Tree::drawTree()//root�� NULL�� �ƴϸ� drawTree_BST�� �����Ű�� NULL�̸� Tree�� ���ٰ� ����Ѵ�.
{
	Node* ptr = root;
	if (ptr != NULL)
		drawTree_BST(ptr, 1);
	else
		std::cout << "Tree not Exist" << std::endl;
}
void Tree::drawTree_BST(Node* ptr, int level) //draw tree ����Լ� ���� ���� ���� ����Ͽ� �ش�
{
	if (ptr != 0 && level <= count) {
		drawTree_BST(ptr->right, level + 1);
		for (int i = 1; i <= (level - 1); i++)
			std::cout << "      ";
		std::cout << ptr->data;
		if (ptr->left != 0 && ptr->right != 0) std::cout << " <" << std::endl;
		else if (ptr->right != 0) std::cout << " /" << std::endl;
		else if (ptr->left != 0) std::cout << " \\" << std::endl;
		else std::cout << std::endl;
		drawTree_BST(ptr->left, level + 1);
	}
}
Node* Tree::find_min(Node* ptr) //right subtree���� ���� ������ ���� 
{
	if (ptr->left == NULL)
	{
		return ptr;
	}
	else
		find_min(ptr->left);
}
Node* Tree::find_max(Node* ptr) //left subtree���� ���� ū�� ���� 
{
	if (ptr->right == NULL)
	{
		return ptr;
	}
	else
		find_min(ptr->right);
}
void Tree::delete_(int data) //delete �Լ�
{
	Node* ptr = root;
	delete_BST(ptr, data);
}
Node* Tree::delete_BST(Node* ptr, int data) //delete ��� �Լ� root�� �����Ҷ��� root�� �ƴ� ��带 �����Ҷ��� ������. ������ ���ڰ� ���ٸ� Not Found�� ����Ѵ�.
{
	if (ptr != NULL) {
		if (data == root->data)
		{
			if ((ptr->left == NULL) && (ptr->right == NULL))
			{
				first = 0;
				Node* p = ptr;
				delete(p);
				root = NULL;
				count--;
			} /*leaf*/
			else if (ptr->left == NULL)
			{
				Node* p = ptr;
				ptr = find_min(ptr->right);
				root = ptr;
				delete(p); // rightchild only
				count--;
			}
			else if (ptr->right == NULL)
			{
				Node* p = ptr;
				ptr = find_max(ptr->left);
				root = ptr;
				delete(p); /*left child only */
				count--;
			}
			else
			{
				int data2;
				Node* temp = find_min(ptr->right);/*both child exists */
				data2 = temp->data;
				ptr->right = delete_BST(ptr->right, data2);
				ptr->data = data2;
				root = ptr;
				count--;
			}
		}
		else
		{
			if (data < ptr->data)
				ptr->left = delete_BST(ptr->left, data);/* move to the node */
			else if (data > ptr->data)
				ptr->right = delete_BST(ptr->right, data); /* arrived at the node*/
			else if ((ptr->left == NULL) && (ptr->right == NULL))
			{
				ptr = NULL; delete(ptr); count--;
			} /*leaf*/	
			else if (ptr->left == NULL) {
				Node* p = ptr; ptr = ptr->right; delete(p); count--; // rightchild only
			}
			else if (ptr->right == NULL) {
				Node* p = ptr; ptr = ptr->left; delete(p); count--; /*left child only */
			}
			else
			{
				Node* temp = find_min(ptr->right);/*both child exists */
				ptr->data = temp->data;
				ptr->right = delete_BST(ptr->right, ptr->data);
			}
		}
	}
	else std::cout << "Not found" << std::endl;
	return ptr;
}
void Tree::search_(int data) //search�Լ� data�������� �ִٰ� ����ϰ� ������ ���ٰ� ����Ѵ�.
{
	Node* ptr = root;
	if (search_BST(ptr, data) != NULL)
		std::cout << "data in Tree" << std::endl;
	else
		std::cout << "Not Found" << std::endl;
}	
Node* Tree::search_BST(Node* ptr, int data)	//search ����Լ�
{
	if (ptr == NULL)
		return ptr; //search unsuccessful
	else {
		if (data == ptr->data)
			return ptr;
		else if (data < ptr->data)
			ptr = search_BST(ptr->left, data); //search leftsubtree
		else if (data > ptr->data)
			ptr = search_BST(ptr->right, data); //search rightsubtree
	}
	return ptr;
}
void Tree::insert_(int data) //insert �Լ�
{
	Node* ptr = root;
	insert_BST(ptr, data);
}
Node* Tree::insert_BST(Node* ptr, int data) //insert ����Լ�
{
	Node* temp = NULL;
	if (ptr == NULL&&first == 0) {
		temp = new Node(); //�����Ҵ�
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		root = temp; 
		first = 1; //root�� ���ִ��� Ȯ�����ش�.
		count++;
		return temp;
	}
	else if (ptr == NULL)
	{
		temp = new Node();
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		count++;
		return temp;
	}
	else if (data < ptr->data)
		ptr->left = insert_BST(ptr->left, data);//ũ�⸦ ���Ͽ� �˸��� ��ġ�� �����Ѵ�.
	else if (data > ptr->data)
		ptr->right = insert_BST(ptr->right, data);//ũ�⸦ ���Ͽ� �˸��� ��ġ�� �����Ѵ�.
	return ptr;
}
int main()
{
	Tree mtree; //Tree ����
	int num; //���� �Է¹��� ���� ����
	std::string input;
	while (1)
	{
		std::cout << " (1. Insert, 2. Delete, 3.Search, 4.Print 5.End) " << std::endl;
		std::cin >> input;
		std::cout << std::endl;
		if (input == "1")
		{
			std::cout << "���ϴ� ���ڸ� �����ּ��� : ";
			std::cin >> num;
			mtree.insert_(num);//num�� insert �����ش�.
			std::cout << "Tree�� " << num << "�� �����ϴ�." << std::endl;
		}
		else if (input == "2")
		{
			std::cout << "�����ϰ���� ���ڸ� �����ּ���.: ";
			std::cin >> num;
			mtree.delete_(num); //num�� delete���ش�.
		}
		else if (input == "3")
		{
			std::cout << "ã����� ���ڸ� �����ּ���.: ";
			std::cin >> num;
			mtree.search_(num); //num�� ã�´�.
		}
		else if (input == "4")
			mtree.drawTree(); //mtree�� �׷��ش�.
		else if (input == "5")
			exit(1);
	}
	return 0;

}