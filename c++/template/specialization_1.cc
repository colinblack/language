#include <iostream>
using namespace std;
//http://www.cppblog.com/SmartPtr/archive/2007/07/04/27496.html

//class specialization
template<class T>
class Compare
{
public:

	Compare(T a, T b) :_a(a), _b(b){}
	static bool IsEqual(const T& lh, const T& rh)
	{
		cout << "nomal" << endl;
		return lh == rh;
	}
private:
	T _a;
	T _b;
};

//1.绝对类型特化
template<>
class Compare<float>
{
public:
	static bool IsEqual(const float& lh, const float& rh)
	{
		cout << "specialization" << endl;
		return abs(lh - rh) < 10e-3;
	}
};

//2.特化为指针或者引用
template <class T>
class Compare<T*>
{
public:
	static bool IsEqual(const T* p1, const T* p2)
	{
		cout << "specialization T*" << endl;
		return Compare<T>::IsEqual(*p1, *p2);
	}
};


//3.特化为另一模板类
template <class T1>
class Special{
public:
	Special(T1 a, T1 b) :_a(a), _b(b){}
	T1 _a;
	T1 _b;
};

template <class T>
class Compare<Special<T>>{
public:
	static bool IsEqual(Special<T> l, Special<T> r)
	{
		cout << "specialization template" << endl;
		return (Compare<T>::IsEqual(l._a, r._a) && Compare<T>::IsEqual(l._b, r._b));
	}

};


//function specialization
template <class T>
T max(T a, T b)
{
	return a > b ? a : b;
}


template <>
int max<int>(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	//Compare<float> test;
	//test.IsEqual(2.5,2.6);
	//Compare<int> test1(2,5);
	//test1.IsEqual(2, 5);
	//
	//int a = 1, b = 2;
	//Compare<int*> test2;
	//test2.IsEqual(&a, &b);
  
	Special<int> s1(1,2), s2(3,4);
	Compare<Special<int>> test3;
	test3.IsEqual(s1, s2);

	max(5, 2);
	max(5.5, 2.2);

	return 0;
}