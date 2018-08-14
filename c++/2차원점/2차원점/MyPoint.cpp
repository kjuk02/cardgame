#include <cstdlib>
#include <cmath>
#include "MyPoint.h"
// constructors
MyPoint::MyPoint()	:x(0), y(0) // set default to origin (0,0)
{
}
MyPoint::MyPoint(int coordX, int coordY)	: x(coordX), y(coordY)
{
}
MyPoint::MyPoint(const MyPoint p)
{
	x = p.x;
	y = p.y;
}
// accessor functions
int MyPoint::getX() const
{
	return x;
}
int MyPoint::getY() const
{
	return y;
}
// mutator functions
void MyPoint::setX(int coordX)
{
	x = coordX;
}
void MyPoint::setY(int coordY)
{
	y = coordY;
}
bool MyPoint::operator== (const MyPoint& p) const
{
	if (x == p.x&&y == p.y)
		return 1;
	else
		return 0;
}
bool MyPoint::operator!= (const MyPoint& p) const
{
	return !operator==(p);
}
// 직선거리(Euclidean distance)의 제곱을 계산
int MyPoint::dist2sqr(const MyPoint& p) const
{
	return pow(x - p.x, 2) + pow(y - p.y, 2);
}
// 직각거리(rectilinear distance)를 계산
int MyPoint::dist1(const MyPoint& p) const
{
	return abs(x - p.x) + abs(y - p.y);
}