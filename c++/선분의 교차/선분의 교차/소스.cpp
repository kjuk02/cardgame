#include <iostream>
#include <fstream>
#include "hearder.h"
#include "Mypoint.h"

int main()
{
	std::ifstream instream;
	instream.open("input.txt");
	int num;
	instream >> num;
	for(int i=0;i<num;i++)
	{
		int x1, y1, x2, y2, x3, y3, x4, y4;
		instream >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		MyPoint p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4);
		MyLineSegment q1(p1, p2), q2(p3, p4);
		if (q1.improperIntersection(q2) || q2.improperIntersection(q1))
			std::cout << "2" << std::endl;
		else if (q2.properIntersection(q1) && q1.properIntersection(q2))
			std::cout << "1" << std::endl;
		else
			std::cout << "0" << std::endl;
	}
}