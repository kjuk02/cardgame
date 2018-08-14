#include<iostream>
#include<fstream>

void hw_5(std::ifstream& fin);

int main()
{
	std::ifstream		fin;
	int num;

	fin.open("input.txt");
	fin>>num;

	for(int i=0;i<num;++i)
		hw_5(fin);

	fin.close();

	return 0;
}
 // &실체넘김
void hw_5(std::ifstream& fin)
{
	int start_num;
	int end_num;

	fin >> start_num >> end_num;
	int sum = 0;
	for(int i=start_num;i <= end_num; ++i) 
		sum+=i;

	std::cout << sum << std::endl;
	
}