#include <iostream>
using namespace std;

class Complax
{
public:
	Complax(double real = 0.0,double image = 0.0)
	{
		_real = real;
		_image = image;
	}

	Complax(const Complax& c)
	{
		_real = c._real;
		_image = c._image;
	}

	Complax& operator=(const Complax& c)
	{
		if(*this == c)
		{
			return *this;
		}

		_real = c._real;
		_image = c._image;

		return *this;

	}
	bool operator==(const Complax& c)
	{
		return (_real == c._real)&&(_image == c._image);		
	}
	void Print()
	{
		cout << "real= "<<_real<<"image="<<_image<<endl;
	}
private:
	bool IsEqual(const Complax& c)
	{
		return (_real == c._real)&&(_image == c._image);
	}
private:
	double _real;
	double _image;
};
int main()
{
	Complax c1(1.0, 2.0);
	Complax c2(c1);
	Complax c3;

	c3 = c1;
	c1.Print();
	c2.Print();
	c3.Print();

	system("pause");
	return 0;
}