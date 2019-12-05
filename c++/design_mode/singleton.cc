#include <iostream>
#include <pthread.h>

//饿汉模式
template <class T>
class CHSingleton
{
protected:
    CHSingleton(){
        std::cout << "new CHSingleton" << std::endl;
        _destory.init();
    }

    ~CHSingleton(){
        std::cout << "delete CHSingleton" << std::endl;
    }
public:
    static T *Instance() { return _instance; }
    class CDestory
    {
    public:
        CDestory(){
            std::cout << "CDestory" << std::endl;
        }
        ~CDestory()
        {
            std::cout << "~CDestory" << std::endl;
            delete CHSingleton::_instance;
            CHSingleton::_instance = nullptr;
        }
        static void init(){std::cout << "init destory class " << std::endl;}
    };

private:
     thread_local static T *_instance;
     static  CDestory _destory;
};

template <class T>
 thread_local T* CHSingleton<T>::_instance = new T;

template <class T>
typename CHSingleton<T>::CDestory CHSingleton<T>::_destory; //typename告诉编译器CHSingleton<T>::CDestory是个类型不是成员变量, 但是没有初始化, 因为没有用到_destory, 不会去初始化
                                                            //https://stackoverflow.com/questions/25656001/the-initialization-of-a-static-instance-of-a-nested-class-in-template-class


class A : public CHSingleton<A>{
private:
    friend class CHSingleton<A>;
    A(){
        std::cout << "new A" << std::endl;
    }
    ~A(){
        std::cout << "delete A" << std::endl;
    }

};

void* func1(void *){
    std::cout << pthread_self() << std::endl;
    std::cout << "instance: " << A::Instance() << std::endl; 
}

void* func2(void *){
    std::cout << pthread_self() << std::endl;
    std::cout << "instance: "<< A::Instance() << std::endl; 
}

int main(){
    pthread_t pid_1; 
    pthread_t pid_2; 
    pthread_create(&pid_1, NULL, func2, NULL);
    pthread_create(&pid_2, NULL, func2, NULL);


    pthread_join(pid_1, NULL);
    pthread_join(pid_2, NULL);
	return 0;
}
