#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int front; int rear;
const char sizeQueue = 5;
char queue[sizeQueue];

void create_queue();
void Enqueue(int value);
void dequeue();
int queue_full();
int queue_empty();
void print_queue();

void create_queue() {
	front = 0;
	rear = 0;
}

void Enqueue(char item)
{

	if (queue_full())
	{
		cout << "queue is FULL" << endl;
		exit(1);
	}
	rear = ((rear + 1) % sizeQueue);
	queue[rear] = item;
}

int queue_full()
{
	if ((rear + 1) % sizeQueue == front)
		return 1;
	else
		return 0;
}

int queue_empty()
{
	if (front == rear)
		return 1;
	else
		return 0;
}

void dequeue()
{
	if (queue_empty())
		cout << "cueue Empty" << endl;
	else /* 에러 key를 반환 */
		front = ((front + 1) % sizeQueue);
}

void print_queue() {
	int i;
	if (queue_empty())
		cout << "Queue is Empty!\n";
	else {
		i = (front + 1) % sizeQueue;
		cout << "-- Print Queue --\n";
		while (i != (rear + 1)%sizeQueue) {
			cout << queue[i] << " ";
			i = (i + 1) % sizeQueue;
		}
	}
	cout << endl;
}
int main()
{
	char num;
	char input[5];
	create_queue();

	while (1)
	{

		cout << " 1.Enque 2.Deque 3.Displayque 4.exit \n";
		cin >> input;

		if (strcmp(input, "1") == 0) //3  enque
		{
			if (!queue_full()) {
				cout << "Enter char to Enque => ";
				cin >> num;
				Enqueue(num);
			}
			else
				cout << "Queue Full!\n";

		}
		else if (strcmp(input, "2") == 0) //4   deque
		{
			if (!queue_empty())
			{
				dequeue();
			}
			else
				cout << "Queue empty!\n";
		}
		else if (strcmp(input, "3") == 0) //6 displayque
		{
			print_queue();
		}

		else if (strcmp(input, "4") == 0) //나가기
			exit(0);

		else
			cout << "Bad Command!\n";
	}
	return 0;
}