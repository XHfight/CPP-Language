#include <iostream>
using namespace std;
class Test1
{
public:
    Test1(int n)
    {
        num=n;
    }//��ͨ���캯��
	Test1(const Test1& t)
	{
		num = 0;
	}
private:
    int num;
};
class Test2
{
public:
    explicit Test2(int n)
    {
        num=n;
    }//explicit(��ʽ)���캯��
private:
    int num;
};
int main()
{
    Test1 t1=12;//��ʽ�����乹�캯��,�ɹ�
    Test2 t2=12;//�������,������ʽ�����乹�캯��
    Test2 t2(12);//��ʽ���óɹ�
    return 0;
}
