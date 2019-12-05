#include <iostream>
#include <string>
#include <set>
#include <cmath>
 
struct PointCmp {
        bool operator()(const int& lhs, const int& rhs) const { 
                    return lhs < rhs; 
        }
};
 
int main()
{
    std::set<int, PointCmp> z = {1, 2, 3, 4, 5};
    for(auto& p: z) 
        std::cout << '(' << p << ')';
    std::cout << '\n';

    if(z.count(5) > 0)
        std::cout << "haha" << std::endl;
}
