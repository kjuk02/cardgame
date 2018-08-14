#include<iostream>
#include<fstream>
#include<string>
int main()
{
	std::ifstream instream;

	instream.open("input.txt");

	int num = 0;
	instream >> num;

	for (int i = 0; i < num; i++)
	{
		std::string input;
		int num_input;
		instream >> input >> num_input;
		std::string time;
		int NUM_TIME = 0;
		for (int j = 0; j < input.size(); j++)
		{
			if ('0' <= input.at(j) && input.at(j) <='9')
				time += input.at(j);
			else if (input.at(j) == 'P'&&input.at(j + 1) == 'M')
				NUM_TIME = 1;
		}
		int alltime = 0;
		int change = 0;
		if (NUM_TIME == 0)
		{
				alltime += ((int(time[0]) - 48) * 10 + (int(time[1]) - 48)) * 60 + (int(time[2]) - 48) * 10 + (int(time[3]) - 48);
				
				alltime += num_input ;
			
				while (alltime>720)
				{
					alltime -= 720;
					change++;
					if (change % 2 == 0)
						NUM_TIME = 0;
					else
						NUM_TIME = 1;
				}
				if (alltime /60 < 10)
				{
					if (alltime % 60>10)
						std::cout << 0 << alltime / 60 << ":" << alltime % 60;
					else
						std::cout << 0 << alltime / 60 << ":" << 0 << alltime % 60;

					if (NUM_TIME == 1)
						std::cout << "PM" << std::endl;
					else
						std::cout << "AM" << std::endl;
				}
				else
				{
					if (alltime % 60>10)
						std::cout << alltime / 60 << ":" << alltime % 60;
					else
						std::cout << 0 << alltime / 60 << ":" << 0 << alltime % 60;

					if (NUM_TIME == 1)
						std::cout << "PM" << std::endl;
					else
						std::cout << "AM" << std::endl;
				}
		}
		else
		{
			alltime += ((int(time[0]) - 48) * 10 + (int(time[1]) - 48)) * 60 + (int(time[2]) - 48) * 10 + (int(time[3]) - 48);
			
			alltime += num_input;
		
			while(alltime >720)
			{
				alltime -= 720;
				change++;
				if (change % 2 == 0)
					NUM_TIME = 1;
				else
					NUM_TIME = 0;
			}
			if (alltime / 60 < 10)
			{
				if(alltime%60>10)
				std::cout << 0 << alltime / 60 << ":" << alltime % 60;
				else
					std::cout << 0 << alltime / 60 << ":" <<0<< alltime % 60;
				if (NUM_TIME == 1)
					std::cout << "PM" << std::endl;
				else
					std::cout << "AM" << std::endl;
			}
			else
			{
				if(alltime%60>10)
				std::cout << alltime / 60 << ":" << alltime % 60;
				else
					std::cout << 0 << alltime / 60 << ":" << 0 << alltime % 60;
				if (NUM_TIME == 1)
					std::cout << "PM" << std::endl;
				else
					std::cout << "AM" << std::endl;
			}
		}
	}
	instream.close();

	return 0;
}