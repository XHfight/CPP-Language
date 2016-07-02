#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(double real = 0.0, double image = 0.0)
	{
		_real = real;
		_image = image;
	}

	~Complex()
	{
	
	}
	void Display()
	{
		cout << _real << "+(" << _image << ")i" <<endl;
	}

	Complex operator+(const Complex& c)
	{
		Complex ret;
		ret._real = _real + c._real;
		ret._image = _image + c._image;
		return ret;
	}

	Complex operator-(const Complex& c)
	{
		return Complex(_real-c._real, _image-c._image);
	}

	Complex operator*(const Complex& c)
	{
		Complex ret;
		ret._real = _real*c._real-_image*c._image;
		ret._image = _image*c._real + _real*c._image;
		return ret;
	}

	Complex operator/(const Complex& c)
	{
		Complex ret;
		ret._real = (_real*c._real+_image*c._image)/(c._real*c._real+c._image*c._image);
		ret._image = (_image*c._real-_real*c._image)/(c._real*c._real+c._image*c._image);
		return ret;
	}

	Complex operator+=(const Complex& c)
	{

		_real += c._real;
		_image += c._image;
		return *this;
	}

	Complex operator-=(const Complex& c)
	{
		_real -= c._real;
		_image -= c._image;
		return *this;
	}

	Complex operator*=(const Complex& c)
	{
		_real = _real*c._real-_image*c._image;
		_image = _image*c._real + _real*c._image;
		return *this;
	}

	Complex operator/=(const Complex& c)
	{
		_real = (_real*c._real+_image*c._image)/(c._real*c._real+c._image*c._image);
		_image = (_image*c._real-_real*c._image)/(c._real*c._real+c._image*c._image);
		return *this;
	}

private:
	double _real;
	double _image;
};

int main()
{
	Complex c1(1.0, 2.0);
	c1.Display();
	Complex c2(2.0, 3.0);
	c2.Display();
//	Complex c3 = c1+c2;
//	Complex c3 = c1-c2;

//	c3.Display();
	system("pause");
	return 0;
}