#include <iostream>
#include <thread>

//c++11创建线程

void threadFunc(){
    std::cout << "subThread" << std::endl;
}

class Obj{
public:
    void operator ()(){
        std::cout << "subThread" << std::endl;
    }
};

int main(){
    //1. 使用全局或类的静态函数创建
    //std::thread t1(threadFunc);
    //2. 使用函数对象
/*     Obj b;
    std::thread t2();
    t2.join(); */

    //3. 使用lambda
    auto l = []{
        std::cout << "subThread" << std::endl;
    };
    std::thread t3(l);
    //t3.join();
    t3.detach();
    if(t3.joinable()){
        t3.detach();
    }

    return 0;    
}