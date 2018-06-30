//模板模板参数测试

#include <iostream>
#include <vector>

using std::vector;


//不用模板模板参数的情况
template <class T1>
class B{
public:
	B(T1 b) :_b(b){}
private:
	T1 _b;
};


template <class T>
class A{
public:
	A(T a) :_a(a){}
private:
	T _a;
};


//用了模板模板参数的情况
template <class T, template<class T> class T1>
class C{
public:
	C(T1<T> c) :_c(c){}

private:
	T1<T> _c;
};


int main()
{
	vector<int> h;
	A<vector<int>> x(h);

	B<int> i(5);
	A<B<int>> y(i); // 如果参数是一个模板类，必须后面带有类型， 如果想要不带类型， 可使用模板模板参数


	C<int, B> z(i);
	return 0;
}