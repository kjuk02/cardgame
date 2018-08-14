#include "MST.h"

int main()
{
	mst spanning;
	while (1)
	{
		int command;
		cout << "1.printMatrix  2.prim MST  3.kruskal MST : ";
		cin >> command;

		switch (command)
		{
			int num;
		case 1:
			spanning.printGraph();
			cout << endl;
			break;
		case 2:
			cout << "Insert number : ";
			cin >> num;
			if (num >= MAX)
			{
				cout << "Number is bigger than graph number.\n";
			}
			else
			{
				spanning.init();
				spanning.prim(num);
			}
			cout << endl;
			break;
		case 3:
			spanning.init();
			spanning.kruskal();
			cout << endl;
			break;
		default:
			cout << "Wrong command." << endl;
			cout << "press any key." << endl;
			cout << endl;
		}
	}

}
