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
void Search_all(StudentInformation &si, StudentScore &ss)
{
	cout << "please enter find content: 1.student basic information  2.score information 0.exit" << endl;
	while(1)
	{
		int search;
		cin >> search;
		if(search == 1)
		{
			si.Search();
		}
		else if(search == 2)
		{
			ss.Search(si);
		}
		else if(search == 0)
			break;
		else
		{
			cout << "Input error, please enter again!!!" << endl;
		}
	}
}

void Delete_all(StudentInformation &si, StudentScore &ss)
{
 	int id;
 	cout << "please enter delete id:" << endl;
 	cin >> id;
 	StudentSystem *p = NULL;
 	p = &si;
 	p->Delete(id);
	p = &ss;
	p->Delete(id);
}

void Order(StudentScore &ss)
{
	int search;
	cout << "please select sort method: 1.overall score 2.Actual credits" << endl;
	cin >> search;
	if(search == 1)
	{
		ss.Sort_sec();
		ss.Print();
	}
	else if(search == 2)
	{
		ss.Sort_cre();
		ss.Print();
	}
	else
		cout << "input error!" << endl;
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
			Search_all(si, ss);
			break;
		case 3:
			Delete_all(si, ss);
			break;
		case 4:
			Order(ss);
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
