#include<iostream>

using namespace std;
int input();//크기 입력받고 홀수인지 판별
void hw1(int arrayA[][500], int num); //조건 판별
void hw2(int arrayA[][500], int num); //함수 출력
int main()
{
	int arrayA[500][500]; //행렬 넣어줄 배열 선언
	int num = 0; //크기 입력받는 변수
	num = input(); //변수 입력 및 홀수확인
	hw1(arrayA, num);//조건 판별
	hw2(arrayA, num);//함수출력
}
int input()//크기 입력받고 홀수인지 판별
{
	int numcase;
	while (1)
	{
		cout << "원하는 홀수매직스퀘어의 크기를 입력하시오" << endl;
		cin >> numcase;
		if (numcase % 2 == 0 || numcase < 0)
		{
			cout << "음수랑 짝수가 아닌수를 입력하시오" << endl;
			cout << endl;
		}
		else
			break;
	}
	return numcase;
}
void hw1(int arrayA[][500], int num)//조건 판별
{
	int x = 0, y;//초기화 
	y = num / 2; // y는 맨처음 맨위 중간값설정

	for (int i = 1; i <= num*num; i++)
	{
		arrayA[x][y] = i;

		if (i%num == 0) //다른수를 만날경우
			x = x + 1;
		else//왼쪽상단으로 이동
			x = x - 1, y = y - 1;
		if (x < 0)//행을 초과할때 
			x = num - 1;
		if (y < 0)//열을 초과할떄
			y = num - 1;
	}
}
void hw2(int arrayA[][500], int num)//함수 출력
{
	cout << endl;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
			cout << arrayA[i][j] << "\t";

		cout << endl;
	}
	cout << endl;
}