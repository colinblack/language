//ģ��ģ���������

#include <iostream>
#include <vector>

using std::vector;


//����ģ��ģ����������
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


//����ģ��ģ����������
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
	A<B<int>> y(i); // ���������һ��ģ���࣬�������������ͣ� �����Ҫ�������ͣ� ��ʹ��ģ��ģ�����


	C<int, B> z(i);
	return 0;
}