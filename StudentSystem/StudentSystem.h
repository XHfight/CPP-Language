#ifndef __STUDENTSYSTEM_H__
#define __STUDENTSYSTEM_H__

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct StudentNode   //存储学生信息的结构体
{
	size_t _id;  //学号
	string _name;
	char _sex[6];
	size_t _homeNum; //宿舍号
	string _telephone;
	StudentNode* _next;

	StudentNode(size_t id, string name, const char* sex, size_t homeNum, string telephone)
		:_id(id)
		,_homeNum(homeNum)
		,_next(NULL)
	{
		_name = name;
		strcpy(_sex, sex);
		_telephone = telephone;
	}
}; 

struct StudentScoreNode  //存储学生成绩信息
{
	size_t _id;
	char _classNum[5];
	string _className;
	int _credit;  //学分
	int _grade_p;
	int _grade_s;
	int _grade_j;
	int _grade_all;
	int _credit_act;
	StudentScoreNode *_next;

	StudentScoreNode(size_t id, char *classNum, string className, int credit, int grade_p, \
			int grade_s, int grade_j, int grade_all, int credit_act)
						:_id(id)
						,_className(className)
						,_credit(credit)
						,_grade_p(grade_p)
						,_grade_s(grade_s)
						,_grade_j(grade_j)
						,_grade_all(grade_all)
						,_credit_act(credit_act)
						,_next(NULL)
	{
		strcpy(_classNum, classNum);
	}

};


class StudentSystem
{
public:
	virtual void Delete(size_t id)
	{}
};

class StudentInformation: public StudentSystem
{
friend StudentNode *Search_id(const StudentInformation &si, size_t id);
public:
	StudentInformation()
		:_list(NULL)
	{}
	
	~StudentInformation()
	{
		StudentNode* cur = _list;
		while(cur)
		{
			StudentNode *del = cur;
			cur = cur->_next;
			delete del;
		}
		_list = NULL;
	}

	void Init();
	void Search();
	void Delete(size_t id);

private:
	void OutputFile(ofstream &ouf);
	void Insert(string str);
private:
	StudentNode* _list;  //链表，存储学生的基本信息
};

class StudentScore:public StudentSystem
{
public:
	StudentScore()
		:_slist(NULL)
	{}

	~StudentScore()
	{
		StudentScoreNode* cur = _slist;
		while(cur)
		{
			StudentScoreNode *del = cur;
			cur = cur->_next;
			delete del;
		}
		_slist = NULL;
	}
	void Init();
	void Search(StudentInformation &si);
	void Delete(size_t id);
	void Add();
	void Sort_sec();
	void Sort_cre();
	void Print();
private:
	void OutputFile(ofstream &ouf);
	void Insert(string str);
private:
	StudentScoreNode *_slist; //链表，存储学生的成绩信息
};

#endif
