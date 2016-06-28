#include "InputScore.h"
#include <iostream>
#include <string>
#include "Student.h"
#include "Mainmenu.h"
#include <conio.h>
InputScore* InputScore::_instance = 0;
InputScore::InputScore()
{
	
}


InputScore * InputScore::instance()
{
	if (_instance == 0)
		_instance = new InputScore;
	return _instance;
}

void InputScore::showInformation(std::map<Student, int>&studentList)
{
	if (isActive)
	{
		system("cls");
		isInputScoreFinish = false;
		for(auto stu:studentList)
			if (stu.first.getScore() == -1.0)
			{
				std::cout << "ѧ��:" << stu.first.getStuID()
					<< "\n����:" << stu.first.getName()
					<< "\n�Ա�:" << stu.first.getSex()
					<< "\n��ȷ�Ϻ�����ɼ�,����back�������˵�\n";
				setActive(false);
				nowStudent = stu.first;
				return;
			}
		isInputScoreFinish = true;
	}
}

void InputScore::getInformation(std::map<Student, int>&studentList, State *&nowState)
{
	if (isInputScoreFinish)
	{
		std::cout << "����ѧ���ĳɼ�����¼����ϣ���������ص����˵�\n";
		_getch();
		nowState = Mainmenu::instance();
		nowState->setActive(true);
		return;
	}
	if (isActive)return;
	std::string op;
	std::cin >> op;
	if (op == "back")
	{
		nowState = Mainmenu::instance();
		nowState->setActive(true);
		return;
	}
	double score = atof(op.c_str());
	auto pos = studentList.find(nowStudent);
	studentList.erase(pos);
	studentList.insert(std::pair<Student, int>(*nowStudent.setScore(score), 1));
	std::cout << "�ɼ�¼��ɹ��������������¼��\n";
	setActive(true);
	_getch();
}

InputScore::~InputScore()
{
}
