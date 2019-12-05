#include <iostream>

class A {
    public:
        virtual void func(){std::cout << "A" << std::endl;}
        A():a(1){}
    protected:
        int a;


};


class B : public A{
    public:
        virtual void func(){std::cout << "B" << std::endl;}
        B(){}
        void printf(){std::cout << a << std::endl;}

};

class C : public B{
    public:
        C(){}
        void printf(){std::cout << a << std::endl;}

};


class D{
public:
    static int a;
    static void func();
    
};

void D::func(){
    D::a = 1;
}

int main(){
    A* a = new C;
    a->func();
    
    D::func();

    return 0;
}
