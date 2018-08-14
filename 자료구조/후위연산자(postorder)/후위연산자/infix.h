#include<iostream>

class infix {
private:
	int stack[100];//*,/,+,-의 연산자들을 넣어줍니다.
	int top;//stack의 가장높은 인덱스가 top이다.
public:
	char compare2[100];//Echo data의 수식을 다 넣어준다.
	char compare[100];//postfix의 수식을 다 넣어준다.

	void create_stack();//스택 생성
	void push(int num);//스택에 num을 넣어준다.
	int pop();//스택에있는 인덱스를 제거해준다.
	int isFull();//스택이 차있는지 확인하다.
	int isEmpty();//스택이 없는지 확인한다.

	void hw(int len);//postfix를 해준다.
	void hw2(int len);//Result를 출력 해준다.
	void hw3();//stack,compare,compare2,top 초기화해준다.
};