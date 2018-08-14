#include<iostream>
#include<fstream>
#include<vector>
struct finalcompare {
	int vort;
	int value;
};
#define top compare.size()-1
int main()
{
	std::ifstream instream;
	instream.open("input.txt");

	std::vector<int>compare;
	int shortcost[100][100] = { { 0,0 } };
	int midcost[100] = { 0, };
	int finalcost[100] = { 0, };
	int max;
	finalcost[0] = 999;
	midcost[0] = 999;
	instream >> max;
	for (int i = 0; i < max; ++i)
		for (int j = 0; j < max; ++j)
			instream >> shortcost[i][j];
	for (int i = 1; i < max; ++i)
	{
		if (i == 1)
			compare.push_back(i);
		if (shortcost[0][i] < shortcost[0][compare[top]])
		{
			compare.pop_back();
			compare.push_back(i);
		}
		midcost[i] = shortcost[0][i];
	}
	int found = compare[top];
	finalcost[compare[top]] = shortcost[0][compare[top]];
	compare.clear();
	int max_ = max - 2;
	while (max_ > 0)
	{
		int compare1 = 0;
		int compare2 = 0;
		finalcompare finalcompare_;
		finalcompare_.value = 999;
		finalcompare_.vort = 999;
		for (int i = 0; i < max; ++i)
		{
			if (finalcost[i] != 0)
				continue;
			compare1 = midcost[i];
			compare2 = finalcost[found] + shortcost[found][i];
			if (compare1 <= compare2)
			{
				if (finalcompare_.value > compare1)
				{
					finalcompare_.vort = i;
					finalcompare_.value = compare1;
				}
				if (midcost[i] > compare1)
					midcost[i] = compare1;
			}
			else
			{
				if (finalcompare_.value > compare2)
				{
					finalcompare_.vort = i;
					finalcompare_.value = compare2;
				}
				if (midcost[i] > compare2)
					midcost[i] = compare2;
			}
		}
		midcost[finalcompare_.vort] = finalcompare_.value;
		finalcost[finalcompare_.vort] = finalcompare_.value;
		found = finalcompare_.vort;
		--max_;
		for (int i = 0; i < max; ++i)
			if (midcost[i] != 0)
			{
				if (midcost[i] == 999)
					std::cout << 0 << " ";
				else
					std::cout << midcost[i] << " ";
			}
		std::cout << std::endl;
	}
	for (int i = 0; i < max; ++i)
		if (midcost[i] != 0)
		{
			if (midcost[i] == 999)
				std::cout << 0 << " ";
			else
				std::cout << midcost[i] << " ";
		}
	std::cout << std::endl;
	return 0;
}