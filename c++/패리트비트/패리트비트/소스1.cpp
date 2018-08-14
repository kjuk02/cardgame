#include<iostream>

int main()
{
	int num; //숫자
	int mask = 1; //비교시 사용할 숫자
	int i; //for문에서 사용할 숫자2

	std::cout << "임의의 정수를 입력하시오:" << std::endl;
	std::cin >> num;
	std::cout << "입력한 수의 내부 저장 표현(이진수)는 다음과 같습니다.\n\n\t"<<std::endl;

	for (i = 32; i>0; i--)  //for문
	{
		if (i % 8)
			std::cout << " " << std::endl;
		std::cout << ((num & (mask << i - 1)) ? 1 : 0) << std::endl;
	}
}