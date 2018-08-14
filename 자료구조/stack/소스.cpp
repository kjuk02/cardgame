#include <iostream>

const int stacksize = 4;
class Stack {
private:
	int stack[stacksize];
	int top;
public:
	Stack() { top = -1; }
	void create_stack();
	void push(int num);
	void pop();
	int isEmpty();
	int isFull();
	void display();
};

void Stack::create_stack() {
	top = -1;
}

int Stack::isEmpty() {
	if (top == -1)
		return 1;
	else
		return 0;
}

int Stack::isFull() {
	if (top == stacksize - 1)
		return 1;
	else
		return 0;
}

void Stack::push(int num)
{
	if (isFull())
	{
		std::cout << "stack is FULL" << std::endl;
		return;
	}
	else
		stack[++top] = num;
}

void Stack::pop() {
	if (isEmpty())
	{
		std::cout << "stack is Empty" << std::endl;
		return;
	}
	else
		stack[top--];
}

void Stack:: display() {
	int sp;
	sp = top;
	std::cout << "------list-------" << std::endl;
	while (sp != -1) {
		std::cout << stack[sp--] << " ";
	}std::cout << std::endl;
}

int main() {
	Stack s1;
	s1.pop();
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(30);
	s1.push(30);
	s1.push(30);
	s1.display();
	s1.pop();
	s1.display();
}