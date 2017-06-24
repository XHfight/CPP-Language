#include "StudentSystem.h"

//主界面展示
void ShowInterface()
{
	cout << "****************** welcome to use Student Information Management System *************" << endl;
	cout << "----------------   1. data input function"<< endl;
	cout << "----------------   2. Search function" << endl;
	cout << "----------------   3. delete function" << endl;
	cout << "----------------   4. sort function" << endl;
	cout << "----------------   0. exit" << endl;
	cout << "Please select the operating:" << endl;
}

//把所有的查找方法封装成一个函数
void Search_all(StudentSystem *p, StudentInformation &si, StudentScore &ss)
{
	cout << "please enter find content: 1.student basic information  2.score information 0.exit" << endl;
	while(1)
	{
		int search;
		cin >> search;
		if(search == 1)
		{
			p = &si;
			p.Search();
		}
		else if(search == 2)
		{
			p = &ss;
			p.Search();
		}
		else if(search == 0)
			break;
		else
		{
			cout << "Input error, please enter again!!!" << endl;
		}
	}
}
//程序运行函数
void Runing()
{
	StudentInformation si;
	si.Init();
	StudentScore ss;
	ss.Init();
	while(1)
	{
		ShowInterface();
		int search;
		cin >> search;
		switch(search)
		{
		case 1:
			ss.Add();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 0:
			return;
			break;
		default:
			system("clear");
			//system("cls"); //清屏函数
			cout << "Input error, please enter again" << endl;
		}
	}
}

int main()
{
	Runing();
	return 0;
}
