#include <iostream>
#include <typeinfo>

class A{
    public:
        virtual void fun(){};

};


class B : public A{
    public:
        virtual void fun(){};

};


int main(){
    A* a = new B;
    const std::type_info& t = typeid(a);
    std::cout << typeid(*a).name() << std::endl;
        

    return 0;
}
