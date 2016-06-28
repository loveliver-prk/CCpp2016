#include "Rectangle.h"



Rectangle::Rectangle(int ID, Point LU, Point RD):LU(LU),RD(RD)
{
	this->ID = ID;
}

Shape * Rectangle::clone()
{
	return new Rectangle(*this);
}


Rectangle::~Rectangle()
{
}

void Rectangle::draw()
{
	std::cout << "��" << ID << "��ͼ��:\n"
		<< "����:" << "����\n"
		<< "���Ͻ�:";
	LU.draw();
	std::cout << "���½�:";
	RD.draw();
	std::cout << "\n\n";
}
