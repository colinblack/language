#include <iostream>
#include <memory>

using namespace std;

class Test {
public:
    Test(int a = 0) : m_a(a) {}
    ~Test() {
        cout << "Calling destructor" << endl;
    }

public:
    int m_a;
};

void Fun()
{
    int a = 0, b = 5, c;
    if(a == 0) {
        throw "Invalid divisor";
    }
    c = b / a;
    return;
}

int main()
{
    try {
        auto_ptr<Test> p(new Test(5));
        Fun();
        cout << p->m_a << endl;
    }
    catch(...) {
        cout << "Something has gone wrong" << endl;
    }

    return 0;
}
