#include <set>
#include <iostream>

using std::multiset;

struct compare{
    bool operator()(const int k1, const int k2){
        return k1 < k2; 
    }

};


class A{
    public:
        static int a;
        void fun(){a = 1;}
};
int A::a = 0;

int main(){
    multiset<int, compare> s;
    s.insert(5);
    s.insert(4);
    s.insert(3);
    s.insert(2);
    s.insert(1);
   

    auto it = s.begin();
    //std::cout << *it << std::endl;
    s.erase(*it);
    s.insert(8);

    for(auto& i : s){
        std::cout <<  i << std::endl;
    
    }

    if(s.count(10) > 0)
        std::cout << "haha" << std::endl;


    return 0;
}



