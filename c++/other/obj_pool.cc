#include <iostream>
#include <memory>
#include <vector>
#include <functional>

template <class T>
class SimpleObjectPool
{
public:
    using DeleterType = std::function<void(T*)>;

    void add(std::unique_ptr<T> t)
    {
        pool_.push_back(std::move(t));
    }

    std::unique_ptr<T, DeleterType> get()
    {
        if (pool_.empty())
        {
            throw std::logic_error("no more object");
        }

        //every time add custom deleter for default unique_ptr
        std::unique_ptr<T, DeleterType>  ptr(pool_.back().release(), [this](T* t)
        {
            pool_.push_back(std::unique_ptr<T>(t));
        });

        pool_.pop_back();
        return std::move(ptr);
    }

    bool empty() const
    {
        return pool_.empty();
    }

    size_t size() const
    {
        return pool_.size();
    }

private:
    std::vector<std::unique_ptr<T>> pool_;
};

class A
{
    
};

class B
{
    
    
};

//测试代码：
int  main()
{
    SimpleObjectPool<A> p;
   
    p.add(std::unique_ptr<A>(new A()));
    p.add(std::unique_ptr<A>(new A()));
    {
        auto t = p.get();
        p.get();
    }

    {
        p.get();
        p.get();
    }

    std::cout << p.size() << std::endl;
    
/*
    p.add(std::unique_ptr<B>(new B()));
    p.add(std::unique_ptr<B>(new B()));
    
    {
        p.get();
        std::cout << p.size() << std::endl;
        p.get();
        std::cout << p.size() << std::endl;
    }
 */   
//  std::cout << p.size() << std::endl;
    return 0;
}