#include "AddStudent.h"
#include <iostream>
#include <string>
#include "Student.h"
#include "Mainmenu.h"
#include <conio.h>
AddStudent* AddStudent::_instance = 0;
AddStudent::AddStudent()
{
}


AddStudent * AddStudent::instance()
{
	if (_instance == 0)
		_instance = new AddStudent;
	return _instance;
}

void AddStudent::showInformation(std::map<Student, int>&studentList)
{
	if (isActive)
	{
		system("cls");
		std::cout << "������ѧ�ţ��������Ա��ÿո����,����back�ص����˵�\n";
		isActive = false;
	}
}

void AddStudent::getInformation(std::map<Student, int>&studentList,State*&nowState)
{
	if (isActive)return;
	std::string stuID, name,sex;
	std::cin >> stuID;
	if (stuID == "back")
	{
		nowState = Mainmenu::instance();
		nowState->setActive(true);
		return;
	}
	std::cin>> name >> sex;
	Student stu(stuID, sex, name);
	studentList.insert(std::pair<Student,int>(stu,1));
	std::cout << "����ɹ��������������\n";
	_getch();
	setActive(true);
}

AddStudent::~AddStudent()
{
}
