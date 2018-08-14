#include <iostream>

typedef struct //element ����ü ����� �Ӽ����δ� row col dir �� �ִ� ���� �� �� ������ ��Ÿ����.
{
	short int row;
	short int col;
	short int dir;
}element;

typedef struct //offsets ����ü ����� �Ӽ����δ� vert horiz �� �ִ� ������ �������ش�.
{
	short int vert;
	short int horiz;
}offsets;

element stack[100]; //stack ����
element pop(); //stack�� �ִ� ���߿� ���ϴ� ��ġ�� ���� ��ȯ���ش�.
int top;
void create_stack(); //top�� -1�� ������ش�.
void push(int row, int col, int dir); //�� �� ���� �׾��ֱ�
void movesert(offsets move[]);//move�� �̵��Ҷ��� ��ġ�����־��ش�.
void runner(int maze[6][6], int mark[6][6]); //���� ã�� �Լ�
void print(int mark[6][6]); //path�� ���� ���
int main()
{
	create_stack();
	int maze[6][6] = { 0,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,0,1,1,1,1,0,1,0,0,1,1,1,1,1,1,0 }; //�̷μ���
	int mark[6][6] = { 1,0,0,0,0,0,  0,0,0,0,0,0,  0,0,0,0,0,0,  0,0,0,0,0,0,  0,0,0,0,0,0,  0,0,0,0,0,0 };// (0,0)�� ���̱⶧���� 1�� ǥ��, ���� ã���� ǥ���Ѵ�.
	push(0, 0, 2); //�ʱ� ��ġ ����
	runner(maze, mark);//����ã�� �Լ�
	print(mark);//path�� ���� ���
	return 0;
}
void print(int mark[6][6])//path�� ���� ���
{
	std::cout << "row" << "\t" << "col" << std::endl;
	std::cout << "�ѤѤѤѤѤ�" << std::endl;
	for (int i = 0; i < 6; i++)//mark ���
	{
		for (int j = 0; j < 6; j++)
		{
			if(mark[i][j]!=0)
			std::cout << i<<"\t"<< j << std::endl;
		}
	}
	std::cout << "\n\n";
	std::cout << "Marked Matrix" << std::endl;
	std::cout << "�ѤѤѤѤѤ�" << std::endl;
	for (int i = 0; i < 6; i++)//mark ���
	{
		for (int j = 0; j < 6; j++)
			std::cout << mark[i][j] << " ";
		std::cout << std::endl;
	}
}
void runner(int maze[6][6], int mark[6][6])//���� ã�� �Լ�
{
	element temp; //element��� ����ü�� form�� ���� temp�� ����
	offsets move[8];//offsets�̶�� ����ü�� form�� ���� move�� ����
	movesert(move);
	int found = 0, dir = 0;
	while (!found)
	{
		temp = pop(); //stack�� �ִ� ���߿� ���ϴ� ��ġ�� ���� ��ȯ���ش�.
		int row = temp.row; //�ʱⰪ �Է�
		int col = temp.col; //�ʱⰪ �Է�
		dir = temp.dir; //�ʱⰪ �Է�
		int next_row = 0; //���� �� ��ġ
		int next_col = 0; //���� �� ��ġ
		while (dir < 8 && !found) //�ð�������� ���� �ִ��� Ȯ���ϰ� ��ǥ�� �����Ͽ����� Ȯ���Ѵ�. 
		{
			next_row = row + move[dir].vert;  next_col = col + move[dir].horiz; //��ġ�� �̵���Ű�鼭 ���� �ִ��� Ȯ���Ѵ�.
			if (next_row == 5 && next_col == 5)  //5,5 �� �ⱸ�� �����Ͽ��� ��� found�� 1�� �־��༭ �����Ͽ����� �˷��ش�.
			{
				found = 1;//����
				mark[next_row][next_col] = 1; //���İ� �� ǥ��
				push(row,	col, dir);
				push(next_row, next_col, dir); //ã�� ���� �־��ش�.
			}
			else if (!maze[next_row][next_col] && !mark[next_row][next_col]) //maze�� ���� ������ �ľ��ϰ� mark�� ���� �����Դ������� �ľ��Ѵ�.
			{
				mark[next_row][next_col] = 1; //���İ� �� ǥ��
				push(row, col, dir); //ã�� ���� �־��ش�.
				row = next_row; //������ �����־��ش�.
				col = next_col; //������ ���� �־��ش�.
				dir = 0; //������ �ʱ�ȭ ���ش�.
			}
			else
				dir++;   //�ð�������� ��ġ�� �ľ��ϵ��� dir�� 1�� �����ش�.
		}
	}
}
void movesert(offsets move[]) {
	move[0].vert = -1; move[0].horiz = 0;/*N*/  move[1].vert = -1; move[1].horiz = 1; /*NE*/  move[2].vert = 0; move[2].horiz = 1; /*E */move[3].vert = 1; move[3].horiz = 1; /*SE */move[4].vert = 1; move[4].horiz = 0;// S     
	move[5].vert = 1; move[5].horiz = -1;   /*SW*/  move[6].vert = 0; move[6].horiz = -1; /*W*/move[7].vert = -1; move[7].horiz = -1;  /*NW*/
}//move�� �̵��Ҷ��� ��ġ ���� �־��ش�.
void create_stack() { top = -1; }//���� ����
void push(int row, int col, int dir) { ++top; stack[top].row = row; stack[top].col = col; stack[top].dir = dir; } //��� �� ������ �־��ش�.
element pop() { return stack[top--]; }//stack�� �ִ°��߿� ���ϴ� ��ġ�� ���� ��ȯ�Ѵ�.