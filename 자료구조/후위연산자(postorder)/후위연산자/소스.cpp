#include <iostream> //표준 라이브러리의 하나로 입출력함수를 쓰기위한 header file
#include "infix.h" //class를 선언해준 header file

using namespace std;

int main()
{
	infix infix2;//class 선언
	char num;
	char input[5];
	infix2.create_stack(); //스택 생성
	int len = 0; //길이 계산
	while (1)
	{
		cout << "1.계산할 식을 넣어주세요. 2.나가기 \n";
		cin >> input;
		if (strcmp(input, "1") == 0) //푸쉬
		{
			infix2.hw3(); //stack,stack2,compare,compare2 초기화
			cout << "0) Enter data :";
			cin >> infix2.compare2; //postfix 할 수식을 받아온다
			cout << "1) Echo data(infix form) :" << " ";
			cout << infix2.compare2 << endl;
			len = strlen(infix2.compare2);//수식의 길이를 측정한다.
			cout << "2) Conversion (postfix form) :" << " ";
			infix2.hw(len);//postfix 수식을 넣어서 정리 해준다
			cout << endl;
			len = strlen(infix2.compare);//수식을 Result하기위해 길이를 측정해준다
			cout << "3) Result :" << " ";
			infix2.hw2(len);//Result 값을 출력하여줍니다.
		}
		else if (strcmp(input, "2") == 0) //나가기
			exit(0);

		else
			cout << "Bad Command!\n"; //명령어가 올바르지않습니다.
	}
	return 0;
}