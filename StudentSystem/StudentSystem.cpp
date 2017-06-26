#include "StudentSystem.h"

//���ļ���д������
void StudentInformation::OutputFile(ofstream &ouf)
{
	StudentNode *cur = _list;
	while(cur)
	{
	 	ouf << cur->_id << " " << cur->_name << " " << cur->_sex << " " << cur->_homeNum << " " \
			<< cur->_telephone << "\r\n";
		cur = cur->_next;
	}
}

//���ļ���д������
void StudentScore::OutputFile(ofstream &ouf)
{
	StudentScoreNode *cur = _slist;
	while(cur)
	{
		ouf << cur->_id << " " << cur->_classNum << " " << cur->_className << " " << cur->_credit << " " << cur->_grade_p << " " << cur->_grade_s << " " << cur->_grade_j << " " << cur->_grade_all << " " << cur->_credit_act << "\r\n";

		cur = cur->_next;
	}
}

//��ȡA�ļ�����Ϣ��������Insert�������뵽�����С�
void StudentInformation::Init()
{
	ifstream inf ("A.txt", ios::binary);
	if(!inf)
	{
		cout << "cannot open file" << endl;
		exit(1);
	}
	string str;
	while(getline(inf, str))
	{
		Insert(str);
	}
	inf.close();
}

//�Ѵ�A�ļ���ȡ������ѧ����Ϣ���뵽������
void StudentInformation::Insert(string str)
{
	char s[256];
	strcpy(s, str.c_str());
	char* arr[5] = {0}; 
	
	int i = 0;   //�����ַ�����s
	int index = 0; //����arr����
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
	char sex[6];
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

		//�ҵ����һ�����
		end->_next = new StudentNode(id, name, sex, homeNum, telephone);
	}
}

//ͨ��ѧ�Ų��Ҷ�Ӧ�ڵ㣨�ڵ�洢��ѧ��������Ϣ��
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
	cout << "please enter find method: 1.use id 2.use homeNumber " << endl;
	
	int search;
	cin >> search;
	if(search == 1)
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
			cout << "*************************************"<<endl;
		}
		else
			cout << "not find !!!" << endl;	
	}
	else if(search == 2)
	{
		cout << "please enter homeNumber:"  << endl;
		size_t homeNum;
		cin >> homeNum;
		int flag = 0; //��־�Ƿ��ҵ�
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
				cout << "*************************************"<<endl;
			}
			cur = cur->_next;
		}
		if(flag == 0)	
			cout << "not find !!!" << endl;	
	}
	else
			cout << "Input error, please enter again!!!" << endl;
}

void StudentScore::Init()
{
	ifstream inf("B.txt", ios::binary);
	if(inf)
	{
		string line;
		while(getline(inf, line))
		{
			Insert(line);
		}
	}
	inf.close();
}

void StudentScore::Insert(string str)
{
	char s[256];
	strcpy(s, str.c_str());
	char* arr[9] = {0}; 
	
	int i = 0;   //�����ַ�����s
	int index = 0; //����arr����
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
	double grade_all = atof(arr[7]);
	double credit_act = atof(arr[8]);
//	cout << "id: " << id << endl;
//	cout << "classNum: " << classNum << endl;
//	cout << "className: " << className << endl;
//	cout << "credit: " << credit << endl;
//	cout << "grade_p: " << grade_p << endl;
//	cout << "grade_s: " << grade_s << endl;
//	cout << "grade_j: " << grade_j << endl;
//	cout << "grade_all: " << grade_all << endl;
//	cout << "credit_act: " << credit_act << endl;
	if(_slist == NULL)
	{
		_slist = new StudentScoreNode(id, classNum, className, credit, \
										grade_p, grade_s, grade_j, grade_all, credit_act);
	}
	else
	{
		StudentScoreNode *end = _slist;
		while(end->_next != NULL)
		{
			end = end->_next;
		}
		//�ҵ����һ�����
		end->_next = new StudentScoreNode(id, classNum, className, credit, \
                                           grade_p, grade_s, grade_j, grade_all, credit_act);
	}
}

void StudentInformation::Delete(size_t id)
{
	StudentNode *cur = _list;
	StudentNode *prev = NULL;
	while(cur)
	{
		if(cur->_id == id)
		{
			StudentNode *del = cur;
			if(cur == _list)
				_list = cur->_next;
			else
				prev->_next = cur->_next;
			delete del;
			break;
		}
		prev = cur;
		cur = cur->_next;
	}
	ofstream ouf("A.txt", ios::binary);
	if(ouf)
	{
		OutputFile(ouf);
		ouf.close();
	}
}

void StudentScore::Add()
{
	size_t id;
	char classNum[5];
	string className;
	int credit;  //ѧ��
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
	cout << "peacetime grade:"; //ƽʱ�ɼ�
	cin >> grade_p;
	cout << "experiments grade:"; //ʵ��ɼ�
	cin >> grade_s;
	cout << "examination grade:"; //����ɼ�
	cin >> grade_j;

	//�����ۺϳɼ���ʵ��ѧ��
	//1.�ۺϳɼ�
	double grade_all;
	if(grade_s == -1)
		grade_all = grade_p*0.3+grade_j*0.7;
	else
		grade_all = grade_p*0.15+grade_s*0.15+grade_j*0.7;
	//2.ʵ��ѧ��
	double credit_act; 
	int key = (int)(grade_all/10);
	switch(key)
	{
		case 10:
		case 9:
			credit_act = credit;
			break;
		case 8:
			credit_act = credit*0.8;
			break;
		case 7:
			credit_act = credit*0.75;
			break;
		case 6:
			credit_act = credit*0.6;
			break;
		default:
			credit_act = 0;
	}
	//�������в�����
	if(_slist == NULL)
	{
		_slist = new StudentScoreNode(id, classNum, className, credit, \
										grade_p, grade_s, grade_j, grade_all, credit_act);
	}
	else
	{
		StudentScoreNode *end = _slist;
		while(end->_next != NULL)
		{
			end = end->_next;
		}
		//�ҵ����һ�����
		end->_next = new StudentScoreNode(id, classNum, className, credit, \
                                           grade_p, grade_s, grade_j, grade_all, credit_act);
	}

	ofstream ouf("B.txt", ios::binary);
	if(ouf)
	{
		OutputFile(ouf);
		ouf.close();
	}
}

void StudentScore::Delete(size_t id)
{
	StudentScoreNode *cur = _slist;
	StudentScoreNode *prev = NULL;
	while(cur)
	{
		if(cur->_id == id)
		{
			StudentScoreNode *del = cur;
			if(cur == _slist)
			{
				_slist = cur->_next;
				cur = _slist;
			}
			else
			{
				prev->_next = cur->_next;
				cur = cur->_next;
			}
			delete del;
			continue;
		}
		prev = cur;
		cur = cur->_next;
	}
	//���޸ĺ������д���ļ�
	ofstream ouf("B.txt", ios::binary);
	if(ouf)
	{
		OutputFile(ouf);
		ouf.close();
	}
}


void StudentScore::Search(StudentInformation &si)
{
	size_t id;
	cout << "please enter id:";
	cin >> id;
	StudentScoreNode *cur = _slist;

	StudentNode *ret = Search_id(si, id);
	if(ret == NULL)
	{
		cout << "not find!!!" << endl;
		return;
	}

	cout << "id:" << id << "	" << "name:" << ret->_name << endl;  
	while(cur)
	{
		if(cur->_id == id)
		{
			cout << "classn_umber: " << cur->_classNum << " " << "class_name:" << cur->_className << \
				" " << "overall_score:" << cur->_grade_all << " "  << "actual_credits:"<< cur->_credit_act << endl;
		}
		cur = cur->_next;
	}
}

//���ۺϳɼ�����-->����
//����ð�����򣬲���������ָ��ı任��ֻ�������ݽ���
//1.������ͷ��ʼ����������һ��Ԫ�غͺ���ıȽϣ������߻�������ȥ����������ֱ������β��
//2.����β��ǰһλ����Ϊ���һ��Ԫ���Ѿ������ֵ�������ٴ����ˣ�3���ظ�1��2�� ��ֱ������β��������ͷ���ȱ����������
void StudentScore::Sort_sco()
{
	StudentScoreNode *p, *tail, *next;

	tail = NULL;
	
	while(tail != _slist)
	{
		p = _slist;
		while(p != tail && p->_next != tail)
		{
			next = p->_next;
			if(p->_grade_all < next->_grade_all)
			{
				swap(p->_id, next->_id);
				for(int i = 0; i < sizeof(p->_classNum)/sizeof(p->_classNum[0]); ++i)
				{
					swap(p->_classNum[i], next->_classNum[i]);
				}
				//swap(p->_classNum, next->_classNum); //���齻��linux��֧�֣�windows��֧��
				swap(p->_className, next->_className);
				swap(p->_credit, next->_credit);
				swap(p->_grade_p, next->_grade_p);
				swap(p->_grade_s, next->_grade_s);
				swap(p->_grade_j, next->_grade_j);
				swap(p->_grade_all, next->_grade_all);
				swap(p->_credit_act, next->_credit_act);
			}
			p = p->_next;
		}
		tail = p;
	}
}

void StudentScore::Sort_cre()
{
	StudentScoreNode *p, *tail, *next;

	tail = NULL;
	
	while(tail != _slist)
	{
		p = _slist;
		while(p != tail && p->_next != tail)
		{
			next = p->_next;
			if(p->_credit_act < next->_credit_act)
			{
				swap(p->_id, next->_id);
				for(int i = 0; i < sizeof(p->_classNum)/sizeof(p->_classNum[0]); ++i)
				{
					swap(p->_classNum[i], next->_classNum[i]);
				}
				swap(p->_className, next->_className);
				swap(p->_credit, next->_credit);
				swap(p->_grade_p, next->_grade_p);
				swap(p->_grade_s, next->_grade_s);
				swap(p->_grade_j, next->_grade_j);
				swap(p->_grade_all, next->_grade_all);
				swap(p->_credit_act, next->_credit_act);
			}
			p = p->_next;
		}
		tail = p;
	}
}

void StudentScore::Print()
{
	StudentScoreNode *cur = _slist;
	while(cur)
	{
		cout << cur->_id << "	" << cur->_classNum << "	" << cur->_className << "	" << cur->_credit << "	" << cur->_grade_p << "	" << cur->_grade_s << "	" << cur->_grade_j << "	" << cur->_grade_all << "	" << cur->_credit_act << endl;
		cur = cur->_next;
	}
}
