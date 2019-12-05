//placement  new

#include <iostream>
#include <cstdlib>

class A{
    public:
        A():a(1){std::cout << "A()" << std::endl;}
        ~A(){std::cout << "~A()" << std::endl;}
        int a;
};


template <class Type, int Num = 1>
Type *CreateObj()
{
    Type *p = (Type *)malloc(sizeof(Type)*Num);
    Construct(p, Num);

    return p;
}

template <class Type>
void Construct(Type *p, int num)
{
    for (int i = 0; i < num; ++i)
    {
        new ((void *)(p + i)) Type();
    }
}

template <class Type>
void DestoryObj(Type *p, int num)
{
    Type* tmp = p;
    for (int i = 0; i < num; ++i, ++tmp)
    {
        tmp->~Type();
    }
    free((void *)p);
}



int main(){
	A*p = CreateObj<A, 5>();
	DestoryObj(p, 5);

    return 0;
}
