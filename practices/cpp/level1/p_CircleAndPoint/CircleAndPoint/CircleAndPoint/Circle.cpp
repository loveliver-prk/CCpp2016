#include "Circle.h"



Circle::Circle( Point center, int radius) :center(center), radius(radius)
{
}

void Circle::move(int x,int y)
{
	center = center + Point(x,y);
}

void Circle::draw()
{
	std::cout << "Բ��:";
	center.draw();
	std::cout << "�뾶:" << radius;
	std::cout << "\n\n";
}

Circle::~Circle()
{
}
