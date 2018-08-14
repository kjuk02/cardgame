#include<iostream>
#include<string>
#include<cmath>
int stack[9];
int top;

void create_stack();
int push(int);
int pop();
int isFull();
int isEmpty();
void displayStack();
void search(int num);
int main()
{
	create_stack();
	std::string input;
	int count = 1;
	while (1)
	{
		std::cout << "(1. Insert, 2. Delete, 3. Empty, 4. Full, 5. Quit) " << std::endl;
		std::cin >> input;
		std::cout << std::endl;
		if (input=="1")
		{

			int num;
			if (count == 0)
			{
				push(8);
				push(6);
				push(4);
				push(2);
				push(5);
				push(3);
				count = 1;
			}
		    std::cout << "원하는 숫자를 넣어주세요" << std::endl;
			std::cin >> num;
			push(num);
			displayStack();
		}
		else if (input=="2")
		{
			pop();
			displayStack();
		}
		else if (input == "3")
		{
			if (isEmpty())
				std::cout << "Heap is empty" << std::endl;
			else
				std::cout << "Heap is exist" << std::endl;
		}
		else if (input=="4")
		{
			if (isFull())
				std::cout << "Heap is FULL" << std::endl;
			else
				std::cout << "Heap can input number" << std::endl;
		}
		else if (input == "5")
		{
			exit(1);
		}
	}
}

void create_stack()
{
	top = 0;
}   //stack create 
int isFull()
{
	if (top == 8)
		return 1;
	else
		return 0;
}
int isEmpty()
{
	if (top == 0)
		return 1;
	else
		return 0;
}
int push(int num)
{
	int i;
	if (isFull()) {
		std::cout << "Heap is full....\n" << std::endl;
		return 0;
	}
	i = ++top;
	while ((i != 1) && (num > stack[i / 2]))
	{
		stack[i] = stack[i / 2];
		i = i / 2;
	}
	stack[i] = num;
}
int pop()
{
	int parent, child;
	int item, temp;

	item = stack[1];
	temp = stack[top--];
	parent = 1;
	child = 2;
	while (child <= top) {
		if ((child < top) && (stack[child] < stack[child + 1]))
			child++; /* find largest child */
		if (temp >= stack[child]) break;
		stack[parent] = stack[child];
		parent = child;
		child = child * 2;
	}
	stack[parent] = temp;
	return item;
}
void displayStack()
{
	int sp;
	if (isEmpty())
		std::cout << "Stack is empty!" << std::endl;
	else
	{
		sp = 1;
		while (sp != top + 1)
		{
			std::cout << stack[sp] << " ";
			++sp;
		}
		std::cout << "\t";
		std::cout <<"depth: "<<int(log2(top))<< std::endl;
	}
}
void search(int num)
{
	int sp;
	if (isEmpty())
		std::cout << "Stack is empty!" << std::endl;
	else
	{
		sp = 1;
		while (sp != top + 1 && stack[sp] != num)
			++sp;
		if (sp != top + 1)
			std::cout << stack[sp] << std::endl;
		else
			std::cout << "not exist" << std::endl;
	}
}