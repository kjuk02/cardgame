#include<iostream>
#include<string>
class Node { //Node 에는 right,left,data가 있다.
private:
	int data;
	Node* right;
	Node* left;
	friend class Tree;
public:
	Node() {}
	~Node() {}
};
class Tree { //tree에는 root와 총갯수인 count
private:
	Node* root;
	int first = 0;
	int count = 0;
public:
	void insert_(int data); //insert 함수
	Node* insert_BST(Node* ptr, int data); //insert 재귀함수
	void search_(int data); //search 함수
	Node* search_BST(Node* ptr, int data); //search 재귀함수
	void delete_(int data); //delete 함수
	Node* delete_BST(Node* ptr, int data);//delete 재귀함수
	Node* find_min(Node* ptr);//가장 작은 값 찾기
	Node* find_max(Node* ptr);//가장 큰 값 찾기
	void drawTree(); //트리 그리는 함수
	void drawTree_BST(Node* ptr, int level); //트리 그리는 재귀함수
};
void Tree::drawTree()//root가 NULL이 아니면 drawTree_BST를 실행시키고 NULL이면 Tree가 없다고 출력한다.
{
	Node* ptr = root;
	if (ptr != NULL)
		drawTree_BST(ptr, 1);
	else
		std::cout << "Tree not Exist" << std::endl;
}
void Tree::drawTree_BST(Node* ptr, int level) //draw tree 재귀함수 가장 우측 부터 출력하여 준다
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
Node* Tree::find_min(Node* ptr) //right subtree에서 가장 작은것 선택 
{
	if (ptr->left == NULL)
	{
		return ptr;
	}
	else
		find_min(ptr->left);
}
Node* Tree::find_max(Node* ptr) //left subtree에서 가장 큰것 선택 
{
	if (ptr->right == NULL)
	{
		return ptr;
	}
	else
		find_min(ptr->right);
}
void Tree::delete_(int data) //delete 함수
{
	Node* ptr = root;
	delete_BST(ptr, data);
}
Node* Tree::delete_BST(Node* ptr, int data) //delete 재귀 함수 root를 삭제할때와 root가 아닌 노드를 삭제할때로 나뉜다. 삭제할 숫자가 없다면 Not Found를 출력한다.
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
void Tree::search_(int data) //search함수 data가있으면 있다고 출력하고 없으면 없다고 출력한다.
{
	Node* ptr = root;
	if (search_BST(ptr, data) != NULL)
		std::cout << "data in Tree" << std::endl;
	else
		std::cout << "Not Found" << std::endl;
}	
Node* Tree::search_BST(Node* ptr, int data)	//search 재귀함수
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
void Tree::insert_(int data) //insert 함수
{
	Node* ptr = root;
	insert_BST(ptr, data);
}
Node* Tree::insert_BST(Node* ptr, int data) //insert 재귀함수
{
	Node* temp = NULL;
	if (ptr == NULL&&first == 0) {
		temp = new Node(); //동적할당
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		root = temp; 
		first = 1; //root가 들어가있는지 확인해준다.
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
		ptr->left = insert_BST(ptr->left, data);//크기를 비교하여 알맞은 위치로 접근한다.
	else if (data > ptr->data)
		ptr->right = insert_BST(ptr->right, data);//크기를 비교하여 알맞은 위치로 접근한다.
	return ptr;
}
int main()
{
	Tree mtree; //Tree 선언
	int num; //값을 입력받을 변수 선언
	std::string input;
	while (1)
	{
		std::cout << " (1. Insert, 2. Delete, 3.Search, 4.Print 5.End) " << std::endl;
		std::cin >> input;
		std::cout << std::endl;
		if (input == "1")
		{
			std::cout << "원하는 숫자를 적어주세요 : ";
			std::cin >> num;
			mtree.insert_(num);//num을 insert 시켜준다.
			std::cout << "Tree에 " << num << "이 들어갔습니다." << std::endl;
		}
		else if (input == "2")
		{
			std::cout << "삭제하고싶은 숫자를 적어주세요.: ";
			std::cin >> num;
			mtree.delete_(num); //num을 delete해준다.
		}
		else if (input == "3")
		{
			std::cout << "찾고싶은 숫자를 적어주세요.: ";
			std::cin >> num;
			mtree.search_(num); //num을 찾는다.
		}
		else if (input == "4")
			mtree.drawTree(); //mtree를 그려준다.
		else if (input == "5")
			exit(1);
	}
	return 0;

}