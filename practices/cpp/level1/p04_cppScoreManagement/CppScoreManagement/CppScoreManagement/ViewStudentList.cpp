#include "ViewStudentList.h"
#include "KeyBoardValue.h"
#include "Mainmenu.h"
#include <conio.h>
#include <iostream>
ViewStudentList* ViewStudentList::_instance = 0;

ViewStudentList::ViewStudentList()
{
}


ViewStudentList * ViewStudentList::instance()
{
	if (_instance == 0)
		_instance = new ViewStudentList;
	return _instance;
}

void ViewStudentList::showInformation(std::map<Student, int>&studentList)
{
	if (isActive)
	{
		system("cls");
		std::cout << "C++�ɼ���\n";
		std::cout << "ѧ��            ����               �Ա�       �ɼ�\n";
		for (auto stu :studentList)
			stu.first.showInformation();
		std::cout << "��5�������˵�\n";
		isActive = false;
	}
}

void ViewStudentList::getInformation(std::map<Student, int>&studentList,State*& nowState)
{
	if (isActive)return;
	int op = _getch();
	if (op == _num5)
	{
		nowState = Mainmenu::instance();
		nowState->setActive(true);
	}
}
ViewStudentList::~ViewStudentList()
{

}

