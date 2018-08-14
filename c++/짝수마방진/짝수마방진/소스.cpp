#include<iostream>
#include<fstream>

void hw_function(int arr[][100], int num);
void hw_function2(int arr[][100], int num);
void hw_function3(int arr[][100], int num);
int main()
{
	std::ifstream instream;
	instream.open("input.txt");

	int num = 0, numcase = 0;
	instream >> num;

	for (int i = 0; i < num; i++)
	{
		int arr[100][100] = { {0,0} };
		instream >> numcase;
		if (numcase % 4 == 2)
		{
			hw_function2(arr, numcase);
			for (int a = 0; a < numcase; a++)
			{
				for (int b = 0; b < numcase; b++)
				{
					std::cout << arr[a][b] << " ";
				}
				std::cout << std::endl;
			}
		}
		else
		{
			hw_function(arr, numcase);
			for (int j = 0; j < numcase; j++)
			{
				for (int k = 0; k < numcase; k++)
				{
					std::cout << arr[j][k] << " ";
				}
				std::cout << std::endl;
			}
		}

	}
	instream.close();
	return 0;
}
void hw_function(int arr[][100], int num)
{
	int count_ = 1;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			arr[i][j] = count_++;

	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			if (i % 4 == j % 4 || ((i % 4) + (j % 4) == 3))
				arr[i][j] = num*num + 1 - arr[i][j];

}
void hw_function2(int arr[][100], int num)
{
	int R = (num - 2) / 4;
	int R2 = 1;
	int arr2[100][100] = { {0,0} };
	hw_function3(arr2, num / 2);
	int count = 1;
	int count2 = 1;
	for (int k = 0; k < (num / 2)*(num / 2); k++)
	{
		for (int i = 0; i < num / 2; i++)
			for (int j = 0; j < num / 2; j++)
				if (arr2[i][j] == count)
				{
					if (i < R + 1)
					{
						if (i == R && (i == (num / 4)) && (j == (num / 4)))
						{
							arr[2 * i][2 * j] = count2++;//0,0
							arr[2 * i + 1][2 * j] = count2++;//1,0
							arr[2 * i + 1][2 * j + 1] = count2++;//1,1
							arr[2 * i][2 * j + 1] = count2++;//0,1
						}
						else
						{
							arr[2 * i][2 * j + 1] = count2++; //2
							arr[2 * i + 1][2 * j] = count2++;//3
							arr[2 * i + 1][2 * j + 1] = count2++;//4
							arr[2 * i][2 * j] = count2++; //1
						}
					}
					else if (i == R + 1)
					{
						if ((i == ((num / 4) + 1)) && (j == (num / 4)))
						{
							arr[2 * i][2 * j + 1] = count2++; //2
							arr[2 * i + 1][2 * j] = count2++;//3
							arr[2 * i + 1][2 * j + 1] = count2++;//4
							arr[2 * i][2 * j] = count2++; //1
						}
						else
						{
							arr[2 * i][2 * j] = count2++;//0,0
							arr[2 * i + 1][2 * j] = count2++;//1,0
							arr[2 * i + 1][2 * j + 1] = count2++;//1,1
							arr[2 * i][2 * j + 1] = count2++;//0,1
						}
					}
					else
					{
						arr[2 * i][2 * j] = count2++;//0,0
						arr[2 * i + 1][2 * j + 1] = count2++;//1,1
						arr[2 * i + 1][2 * j] = count2++;//1,0
						arr[2 * i][2 * j + 1] = count2++;//0,1
					}
				}
		count++;
	}
}
void hw_function3(int arr[][100], int num)//조건 판별
{
	int x = 0, y;//초기화 
	y = num / 2; // y는 맨처음 맨위 중간값설정

	for (int i = 1; i <= num*num; i++)
	{
		arr[x][y] = i;

		if (i%num == 0) //다른수를 만날경우
			x = x + 1;
		else//왼쪽상단으로 이동
			x = x - 1, y = y + 1;
		if (x < 0)//행을 초과할때 
			x = num - 1;
		if (y >= num)//열을 초과할떄
			y = 0;
	}
}