#include <iostream>

typedef struct //element 구조체 만들기 속성으로는 row col dir 가 있다 각각 행 열 방향을 나타낸다.
{
	short int row;
	short int col;
	short int dir;
}element;

typedef struct //offsets 구조체 만들기 속성으로는 vert horiz 가 있다 방향을 설정해준다.
{
	short int vert;
	short int horiz;
}offsets;

element stack[100]; //stack 선언
element pop(); //stack에 있는 값중에 원하는 위치의 값을 반환해준다.
int top;
void create_stack(); //top을 -1로 만들어준다.
void push(int row, int col, int dir); //행 열 방향 쌓아주기
void movesert(offsets move[]);//move에 이동할때의 위치값을넣어준다.
void runner(int maze[6][6], int mark[6][6]); //길을 찾는 함수
void print(int mark[6][6]); //path와 길을 출력
int main()
{
	create_stack();
	int maze[6][6] = { 0,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,0,1,1,1,1,0,1,0,0,1,1,1,1,1,1,0 }; //미로설정
	int mark[6][6] = { 1,0,0,0,0,0,  0,0,0,0,0,0,  0,0,0,0,0,0,  0,0,0,0,0,0,  0,0,0,0,0,0,  0,0,0,0,0,0 };// (0,0)은 길이기때문에 1로 표시, 길을 찾으면 표시한다.
	push(0, 0, 2); //초기 위치 설정
	runner(maze, mark);//길을찾는 함수
	print(mark);//path와 길을 출력
	return 0;
}
void print(int mark[6][6])//path와 길을 출력
{
	std::cout << "row" << "\t" << "col" << std::endl;
	std::cout << "ㅡㅡㅡㅡㅡㅡ" << std::endl;
	for (int i = 0; i < 6; i++)//mark 출력
	{
		for (int j = 0; j < 6; j++)
		{
			if(mark[i][j]!=0)
			std::cout << i<<"\t"<< j << std::endl;
		}
	}
	std::cout << "\n\n";
	std::cout << "Marked Matrix" << std::endl;
	std::cout << "ㅡㅡㅡㅡㅡㅡ" << std::endl;
	for (int i = 0; i < 6; i++)//mark 출력
	{
		for (int j = 0; j < 6; j++)
			std::cout << mark[i][j] << " ";
		std::cout << std::endl;
	}
}
void runner(int maze[6][6], int mark[6][6])//길을 찾는 함수
{
	element temp; //element라는 구조체의 form을 가진 temp를 선언
	offsets move[8];//offsets이라는 구조체의 form을 가진 move를 선언
	movesert(move);
	int found = 0, dir = 0;
	while (!found)
	{
		temp = pop(); //stack애 있는 값중에 원하는 위치의 값을 반환해준다.
		int row = temp.row; //초기값 입력
		int col = temp.col; //초기값 입력
		dir = temp.dir; //초기값 입력
		int next_row = 0; //다음 행 위치
		int next_col = 0; //다음 열 위치
		while (dir < 8 && !found) //시계방향으로 길이 있는지 확인하고 목표에 도달하였는지 확인한다. 
		{
			next_row = row + move[dir].vert;  next_col = col + move[dir].horiz; //위치를 이동시키면서 길이 있는지 확인한다.
			if (next_row == 5 && next_col == 5)  //5,5 즉 출구에 도달하였을 경우 found에 1을 넣어줘서 도착하였음을 알려준다.
			{
				found = 1;//도착
				mark[next_row][next_col] = 1; //거쳐간 길 표시
				push(row,	col, dir);
				push(next_row, next_col, dir); //찾은 길을 넣어준다.
			}
			else if (!maze[next_row][next_col] && !mark[next_row][next_col]) //maze를 통해 길인지 파악하고 mark를 통해 전에왔던길인지 파악한다.
			{
				mark[next_row][next_col] = 1; //거쳐간 길 표시
				push(row, col, dir); //찾은 길을 넣어준다.
				row = next_row; //현재의 행을넣어준다.
				col = next_col; //현재의 열을 넣어준다.
				dir = 0; //방향을 초기화 해준다.
			}
			else
				dir++;   //시계방향으로 위치를 파악하도록 dir에 1을 더해준다.
		}
	}
}
void movesert(offsets move[]) {
	move[0].vert = -1; move[0].horiz = 0;/*N*/  move[1].vert = -1; move[1].horiz = 1; /*NE*/  move[2].vert = 0; move[2].horiz = 1; /*E */move[3].vert = 1; move[3].horiz = 1; /*SE */move[4].vert = 1; move[4].horiz = 0;// S     
	move[5].vert = 1; move[5].horiz = -1;   /*SW*/  move[6].vert = 0; move[6].horiz = -1; /*W*/move[7].vert = -1; move[7].horiz = -1;  /*NW*/
}//move에 이동할때의 위치 값을 넣어준다.
void create_stack() { top = -1; }//스텍 생성
void push(int row, int col, int dir) { ++top; stack[top].row = row; stack[top].col = col; stack[top].dir = dir; } //행과 열 방향을 넣어준다.
element pop() { return stack[top--]; }//stack에 있는값중에 원하는 위치의 값을 반환한다.