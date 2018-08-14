#include<iostream>
#include<fstream>
#include<cstdlib>

#define MaxSize 7
struct hashtable
{
	int key;
	bool empty;
};
hashtable htable[MaxSize];
int hash(int key) { return key%MaxSize; }

int findKey(int key, int& index, int number) // Linear Probing으로 확장
{
	bool found = false;
	bool loop = true;
	index = hash(key);
	int index_ = index;
	if (number == 0)
	{
		while (htable[index].empty == true && loop == true)
		{
			index = (index + 1) % MaxSize;
			if (index == index_)
				loop = false;
		}

	}
	else if (number == 1)
	{
		while (htable[index].key != key && loop == true)
		{
			index = (index + 1) % MaxSize;
			if (index == index_)
				loop = false;
		}
	}
	else
	{
		while (htable[index].key != key && loop == true)
		{
			index = (index + 1) % MaxSize;
			if (index == index_)
				loop = false;
		}
		if (loop == true)
			std::cout << "found " << key << std::endl;
		else
			std::cout << "not found" << std::endl;
		return 0;
	}
	if (loop == true)
		found = true;
	return found;
}
void searchKey(int key) { int index; findKey(key, index, 3); }
int insertKey(int key)
{
	int index = 0;
	int check = findKey(key, index, 0);
	if (check == false)
		return false;// no duplicated key
	else
	{
		htable[index].key = key;
		htable[index].empty = true;
		return true;
	}
}
void deleteKey(int key)
{
	int index = 0;
	int check = findKey(key, index, 1);
	if (check == false)
		std::cout << "그런거 없습니다." << std::endl;
	else
		htable[index].empty = false; // marking
}
void printtable()
{
	std::cout << "(";
	for (int i = 0; i < MaxSize; ++i)
	{
		if (htable[i].empty == true)
			std::cout << htable[i].key;
		else
			std::cout << "_";
		if (i != MaxSize - 1)
			std::cout << ",";
	}
	std::cout << ")" << std::endl;
}
int main()
{
	int num = 0;
	int input = 0;
	while (1)
	{
		std::cout << " ( 1.find, 2.insert, 3.delete, 4.quit) " << std::endl;
		std::cin >> input;
		std::cout << std::endl;
		switch(input)
		{
			case 1:
				std::cout << "찾으시는 수를 써주세요 : ";
				std::cin >> num;
				searchKey(num);
				break;
			case 2:
				std::cout << "넣고 싶은 수를 써주세요 : ";
				std::cin >> num;
				insertKey(num);
				printtable();
				break;
			case 3:
				std::cout << "지우고 싶은 수를 써주세요 : ";
				std::cin >> num;
				deleteKey(num);
				printtable();
				break;
			case 4:
				std::cout << "프로그램을 종료 합니다. " << " ";
				exit(1);
			defalut :
				std::cout << "잘못 입력하셨습니다." << std::endl;
		}
	}
	return 0;
}