#include<iostream>
#include "infix.h"
using namespace std;
void infix::create_stack() //스텍 생성
{
	top = -1;
}
void infix::push(int num) //값 입력
{
	++top;
	stack[top] = num;
}
int infix::pop()  //제거
{
	return stack[top--];
}
int infix::isFull()//stack이 꽉차있는지 확인
{
	if (top == 99)
		return 1;
	else
		return 0;
}
int infix::isEmpty()//stack이 비어있는지 확인
{
	if (top == -1)
		return 1;
	else
		return 0;
}
void infix::hw(int len)//postfix를 해준다.
{
	int numcase = 0;
	for (int i = 0; i < len; i++) //수식의 길이만큼 for문을 돌려준다
	{
		if (((int)compare2[i] == 43) || ((int)compare2[i] == 45) || ((int)compare2[i] == 47) || ((int)compare2[i] == 42) || ((int)compare2[i] == 40))//*,/,+,-,(일경우 작동된다.
		{
			if ((int)stack[top] == 40)//stack[top]이 (일경우 pop해주고 들어오는 수를 push해준다.
			{
				push(compare2[i]);
			}
			else if ((int)compare2[i] == 40)//들어오는수가 (일경우 push
			{
				push(compare2[i]);
			}
			else if (((int)stack[top] == 47) || ((int)stack[top] == 42))//*,/일 경우 stack에있는걸 출력해주고 pop해준다.
			{
				compare[numcase] =(char) stack[top];//출력이 됄경우 compare에 수식을 쌓아준다.
				numcase++;
				cout << (char)stack[top] << " "; //연산자 출력
				pop();//연산자를 출력해준뒤 제거
				push(compare2[i]);//비교해준 연산자를 stack에 넣어준다
			}
			else if ((int)stack[top] == 43 || (int)stack[top] == 45)//stack에있는 연산자가 +,-일 경우 
			{
				if (((int)compare2[i] == 47) || ((int)compare2[i] == 42))//+,-일경우 stack쌓기
				{
					push(compare2[i]);
				}
				else//출력이 됄경우 compare에 수식을 쌓아준다. 
				{
					compare[numcase] = (char)stack[top];
					numcase++;
					cout << (char)stack[top] << " ";//연산자 출력
					pop();//연산자를 출력해준뒤 제거
					push(compare2[i]);//비교해준 연산자를 stack에 넣어준다
				}
			}
			else
				push(compare2[i]);//stack에 넣어준다
		}
		else if (((int)compare2[i] == 41))// )가 들어올경우 전부다 출력해준다.
		{
			while (int(stack[top])!=40)
			{
				compare[numcase] = (char)stack[top]; //출력할 경우 compare에 쌓아준다.
				numcase++;
				cout << (char)stack[top] << " "; //연산자 출력
				pop();//제거
			}
			pop();
		}
		else
		{
			compare[numcase] = (char)compare2[i]; //출력할 경우 compare에 쌓아준다.
			numcase++;
			cout << (char)compare2[i] << " ";//숫자 출력
		}
	}
	while (top > -1)//stack에 수식이 쌓여있으면 전부 출력해준다.
	{
		compare[numcase] = (char)stack[top];//출력할 경우 compare에 쌓아준다.
		numcase++;
		cout << (char)stack[top] << " ";//연산자 출력
		pop();//제거
	}
}
void infix::hw2(int len)//Result를 출력 해준다.
{
	int sum = 0;//계산한 수를 전부 더해준다
	int num = 0;//char형의 숫자를 변환시켜줄 변수
	for (int m = 0; m < len; m++)
	{
		if ((int)compare[m] == 42)//*일 경우
		{
			sum = (((int)stack[top]) * ((int)stack[top - 1])); //수식을 계산해준다.
			pop();//계산한 수식 제거
			pop();//계산한 수식 제거
			push(sum);//결과를 stack에 저장
		}
		else if ((int)compare[m] == 47)// /일 경우
		{
			sum = (((int)stack[top - 1]) / ((int)stack[top]));//수식을 계산해준다.
			pop();//계산한 수식 제거
			pop();//계산한 수식 제거
			push(sum);//결과를 stack에 저장
		}
		else if ((int)compare[m] == 43)// +일 경우
		{
			sum = (((int)stack[top- 1]) + ((int)stack[top]));//수식을 계산해준다.
			pop();//계산한 수식 제거
			pop();//계산한 수식 제거
			push(sum);//결과를 stack에 저장
		}
		else if ((int)compare[m] == 45)// -일 경우
		{
			sum = (((int)stack[top - 1]) - ((int)stack[top]));//수식을 계산해준다.
			pop();//계산한 수식 제거
			pop();//계산한 수식 제거
			push(sum);//결과를 stack에 저장
		}
		else//숫자가 나올경우 stack에 쌓아준다
		{
			num = (int)compare[m] - 48; //아스키코드값을 변환시켜준다.
			push(num);//숫자를 stack에 저장
		}
	}
	cout << stack[top] << endl; //최종적으로는 stack에 result값이 top에쌓이기 때문에 stack2[top2]을 출력해준다.
	pop();
}
void infix::hw3()//stack,stack2,compare,compare2,top,top2 초기화해준다.
{
	for (int k = 0; k < 100; k++)
	{
		stack[k] = 0;
		compare[k] = 0;
		compare2[k] = 0;
	}
	top = -1;
}