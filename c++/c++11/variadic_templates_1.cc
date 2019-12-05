//可变参模板
#include <iostream>

struct A{
    A(int){std::cout << "A" << std::endl;}
};
struct C{
    C(){std::cout << "C" << std::endl;}
};

struct B{
    B(int, double){std::cout << "B" << std::endl;}
};

template <class T, class... Args>
T* Instance(Args... args)
{
    return new T(args...);
}

int main(){
    A* pa = Instance<A>(1);
    B* pb = Instance<B>(1, 2);
    C* pc = Instance<C>();
    return 0;
}
