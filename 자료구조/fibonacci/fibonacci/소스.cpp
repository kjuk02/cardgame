#include<iostream>

using namespace std;

int fibo(int num)
{
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	else
		return fibo(num - 1) + fibo(num - 2);
}
int main()
{
	cout << fibo(6) << endl;
}

//int recusive(int a, int b)
//{
//	if (a == 0)
//	{
//		return b;
//	}
//	else
//	{
//		return recusive(a-1, b+1);
//	}
//}
//int main()
//{
//	cout << recusive(4, 7) << endl;
//	return 0;
//}