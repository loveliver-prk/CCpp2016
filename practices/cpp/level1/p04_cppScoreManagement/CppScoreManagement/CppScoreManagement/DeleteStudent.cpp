#include "DeleteStudent.h"
#include <iostream>
#include <string>
#include "State.h"
#include "Mainmenu.h"
#include <conio.h>
DeleteStudent* DeleteStudent::_instance = 0;
DeleteStudent::DeleteStudent()
{
}


DeleteStudent * DeleteStudent::instance()
{
	if (_instance == 0)
		_instance = new DeleteStudent;
	return _instance;
}

void DeleteStudent::showInformation(std::map<Student, int>&studentList)
{
	if (isActive)
	{
		system("cls");
		std::cout << "��ѡѧ��������\n";
		std::cout << "ѧ��            ����               �Ա�       �ɼ�\n";
		for (auto stu : studentList)
			stu.first.showInformation();
		std::cout << "������Ҫɾ����ѧ����ѧ��,����back�ص����˵�\n";
		isActive = false;
	}
}

void DeleteStudent::getInformation(std::map<Student, int>&studentList, State *&nowState)
{
	std::string stuID;
	std::cin >> stuID;
	if (stuID == "back")
	{
		nowState = Mainmenu::instance();
		nowState->setActive(true);
		return;
	}
	
	for (auto stu = studentList.begin();stu != studentList.end();stu++)
		if (stu->first.getStuID() == stuID)
		{
			studentList.erase(stu);
			std::cout << "ɾ���ɹ��������������\n";
			_getch();
			setActive(true);
			return;
		}
	std::cout << "δ�ҵ���ѧ��,����������\n";
}

DeleteStudent::~DeleteStudent()
{
}
