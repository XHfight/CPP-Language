#include "StudentSystem.h"

//向文件中写入数据
void StudentInformation::OutputFile(ofstream &ouf)
{
	StudentNode *cur = _list;
	while(cur)
	{
	 	ouf << cur->_id << " " << cur->_name << " " << cur->_sex << " " << cur->_homeNum << " " \
			<< cur->_telephone << endl;
		cur = cur->_next;
	}
}


void StudentScore::OutputFile(ofstream &ouf)
{
	StudentScoreNode *cur = _slist;
	while(cur)
	{
		string str;
		char arr[10];
		sprintf(arr, "%d", (int)cur->_id);
		str+=arr;
		str+=" ";
		str+=cur->_classNum;
		str+=" ";
		str+=cur->_className;
		str+=" ";
		sprintf(arr, "%d", cur->_credit);
		str+=arr;
		str+=" ";
		sprintf(arr, "%d", cur->_grade_p);
		str+=arr;
		str+=" ";
		sprintf(arr, "%d", cur->_grade_s);
		str+=arr;
		str+=" ";
		sprintf(arr, "%d", cur->_grade_j);
		str+=arr;
		ouf << str << endl;
	
		cur = cur->_next;
	}
}

//读取A文件的信息，并调用Insert函数插入到链表中。
void StudentInformation::Init()
{
	ifstream inf ("A.txt",  ios::binary);
	if(!inf)
	{
		cout << "cannot open file" << endl;
		exit(1);
	}
	char ch;
	string str;
	while(inf.get(ch))
	{
		if(ch == '\n')
		{
			//读取到一行的内容
			//插入链表
			Insert(str);

		//	cout << str << endl;
			str = "";
			continue;
		}
		str += ch;
	}
	Insert(str);
	inf.close();
}

//把从A文件读取出来的学生信息插入到链表中
void StudentInformation::Insert(string str)
{
	char s[256];
	strcpy(s, str.c_str());
	char* arr[5] = {0}; 
	
	int i = 0;   //访问字符数组s
	int index = 0; //访问arr数组
	arr[index++] = s;
	while(s[i]  != '\0')
	{
		if(s[i] == ' ')
		{
			s[i] = '\0';
			++i;
			arr[index++] = &s[i];
		}
		else
		{
			++i;
		}
	}
	
	size_t id = atoi(arr[0]);
	string name(arr[1]);
	char sex[2];
	strcpy(sex, arr[2]);
	size_t homeNum  = atoi(arr[3]);
	string telephone(arr[4]);

//	cout << "id: " << id << endl;
//	cout << "name: " << name << endl;
//	cout << "sex: " << sex << endl;
//	cout << "homeNum: " << homeNum << endl;
//	cout << "telephone: " << telephone << endl;
	if(_list == NULL)
	{
		_list = new StudentNode(id, name, sex, homeNum, telephone);
	}
	else
	{
		StudentNode *end = _list;
		while(end->_next != NULL)
		{
			end = end->_next;
		}

		//找到最后一个结点
		end->_next = new StudentNode(id, name, sex, homeNum, telephone);
	}
}

//通过学号查找对应节点（节点存储着学生基本信息）
StudentNode *Search_id(const StudentInformation &si, size_t id)
{
	StudentNode *cur = si._list;
	while(cur)
	{
		if(cur->_id == id)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}

void StudentInformation::Search()
{
	cout << "please enter find method: 1.use id 2.use homeNumber 0.exit" << endl;
	while(1)
	{
		int search;
		cin >> search;
		switch(search)
		{
		case 1:
			{
				cout << "please enter id: " << endl;
				size_t id;
				cin >> id;
				StudentNode *ret = Search_id(*this, id);
				if(ret != NULL)
				{
					cout << "id: " << ret->_id << endl;
					cout << "name: " << ret->_name << endl;
					cout << "sex: " << ret->_sex << endl;
					cout << "homeNum: " << ret->_homeNum << endl;
					cout << "telephone: " << ret->_telephone << endl;
				}
				else
					cout << "not find !!!" << endl;	
			}
			break;
		case 2:
			{
				cout << "please enter homeNumber:"  << endl;
				size_t homeNum;
				cin >> homeNum;
				int flag = 0; //标志是否找到
				StudentNode *cur = _list;
				while(cur != NULL)
				{
					if(cur->_homeNum == homeNum)
					{
						flag = 1;
						cout << "id: " << cur->_id << endl;
						cout << "name: " << cur->_name << endl;
						cout << "sex: " << cur->_sex << endl;
						cout << "homeNum: " << cur->_homeNum << endl;
						cout << "telephone: " << cur->_telephone << endl;
					}
					cur = cur->_next;
				}
				
				if(flag == 0)	
					cout << "not find !!!" << endl;	
			}
			break;
		case 0:
			return;
			break;
		default:
			cout << "Input error, please enter again!!!" << endl;
		}
	}
}

void StudentScore::Init()
{
	ifstream inf("B.txt", ios::binary);
	if(inf)
	{
		string line;
		while(getline(inf, line))
		{
			cout << line << endl;
			Insert(line);
		}
	}
	inf.close();
}

void StudentScore::Insert(string str)
{
	char s[256];
	strcpy(s, str.c_str());
	char* arr[7] = {0}; 
	
	int i = 0;   //访问字符数组s
	int index = 0; //访问arr数组
	arr[index++] = s;
	while(s[i]  != '\0')
	{
		if(s[i] == ' ')
		{
			s[i] = '\0';
			++i;
			arr[index++] = &s[i];
		}
		else
		{
			++i;
		}
	}
	size_t id = atoi(arr[0]);
	char classNum[4];
	strcpy(classNum, arr[1]);
	string className(arr[2]);
	int credit = atoi(arr[3]);
	int grade_p = atoi(arr[4]);
	int grade_s = atoi(arr[5]);
	int grade_j = atoi(arr[6]);
//	int grade_all = atoi(arr[7]);
//	int credit_act = atoi(arr[8]);
	cout << "id: " << id << endl;
	cout << "classNum: " << classNum << endl;
	cout << "className: " << className << endl;
	cout << "credit: " << credit << endl;
	cout << "grade_p: " << grade_p << endl;
	cout << "grade_s: " << grade_s << endl;
	cout << "grade_j: " << grade_j << endl;
//	cout << "grade_all: " << grade_all << endl;
//	cout << "credit_act: " << credit_act << endl;
	if(_slist == NULL)
	{
		_slist = new StudentScoreNode(id, classNum, className, credit, \
										grade_p, grade_s, grade_j, 0, 0);
	}
	else
	{
		StudentScoreNode *end = _slist;
		while(end->_next != NULL)
		{
			end = end->_next;
		}
		//找到最后一个结点
		end->_next = new StudentScoreNode(id, classNum, className, credit, \
                                           grade_p, grade_s, grade_j, 0, 0);
	}
}

void StudentScore::Add()
{
	size_t id;
	char classNum[5];
	string className;
	int credit;  //学分
	int grade_p;
	int grade_s;
	int grade_j;
	cout << "please enter students' score information:" << endl;
	cout << "id:";
	cin >> id;
	cout << "class number:";
	cin >> classNum;
	cout << "class name:";
	cin >> className;
	cout << "credit:";
	cin >> credit;
	cout << "peacetime grade:"; //平时成绩
	cin >> grade_p;
	cout << "experiments grade:"; //实验成绩
	cin >> grade_s;
	cout << "examination grade:"; //卷面成绩
	cin >> grade_j;

	//向链表中插入结点
	if(_slist == NULL)
	{
		_slist = new StudentScoreNode(id, classNum, className, credit, \
										grade_p, grade_s, grade_j, 0, 0);
	}
	else
	{
		StudentScoreNode *end = _slist;
		while(end->_next != NULL)
		{
			end = end->_next;
		}
		//找到最后一个结点
		end->_next = new StudentScoreNode(id, classNum, className, credit, \
                                           grade_p, grade_s, grade_j, 0, 0);
	}

	ofstream ouf("B.txt", ios::binary);
	if(ouf)
	{
		OutputFile(ouf);
		//ouf << id << " " << classNum << " " << className << " " << credit << " " << \
			" " << grade_p << " " << grade_s << " " << grade_j << endl;
		ouf.close();
	}
}

void StudentScore::Delete()
{

}

void StudentScore::Search()
{
	size_t id;
	cout << "please enter id:";
	cin >> id;
	StudentScoreNode *cur = _slist;
	cout << "id:" << id << "name:" 
	while(cur)
	{
		if(cur->_id == id)
		{
			cout << id << " " << cur->_classNum << " " << cur->_className << " " << cur->_credit << " " << \
				" " << cur->_grade_p << " " << cur->_grade_s << " " << cur->_grade_j << endl;
		}
	}

}
