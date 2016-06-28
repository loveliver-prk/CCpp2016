#include "Circle.h"



Circle::Circle(int ID,Point center,int radius):center(center),radius(radius)
{
	this->ID = ID;
}

void Circle::draw()
{
	std::cout << "��" << ID << "��ͼ��:\n"
		<< "����:" << "Բ\n"
		<< "Բ��:";
	center.draw();
	std::cout << "�뾶:" << radius;
	std::cout << "\n\n";
}

Shape * Circle::clone()
{
	return new Circle(*this);
}


Circle::~Circle()
{
}
