#include <iostream>
#include <exception>
#include <stdexcept>

void func()
{
    throw std::runtime_error("111");
}

int main()
{
    func();
    while (1)
        ;

    return 0;
}
