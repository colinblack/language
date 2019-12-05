#include <iostream>
#include <map>
#include <string>

using namespace std;

using std::map;
class A{
public:
    A(){
        std::cout <<  "constuct" << std::endl;
    }
    ~A(){
        std::cout <<  "destuct" << std::endl;
    }
};

int main(){
    map<int, int> m;
    //map<int, int> m{{1, 1}, {2, 1}, {3, 1}};
    //map<int, int> m{{1, 1}, {2, 1}};
    //map<int, int> m{{1, 1}, {2, 1}};
    std::cout << sizeof(m) << std::endl;
    map<string, A*> m1;
    m1["cp"] = new A;
    m1["colin"] = new A;
    m1["black"] = new A;
    

    return 0;
}
