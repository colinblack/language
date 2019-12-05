#include <iostream>
using namespace std;
template <typename T>
class S
{
public:
    T m;
    class A
    {
    public:
        A() {cout << "A";}
        void say() {cout << "hello";}
        ~A(){cout << "~A";}
    };
    static A obj;
};

template <typename T>
typename S<T>::A S<T>::obj;

int main() {
//    S<int>::obj.say();
      S<int> s;
}
