#include <iostream>


class Complex
{
	int real, imag;
	explicit
		Complex(int re, int im = 0) :real(re), imag(im){}
	Complex& operator+(const Complex& x)
	{
		return Complex(real + x.real, imag+x.imag);
	}


};


int main()
{

	return 0;
}