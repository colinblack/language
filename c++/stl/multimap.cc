#include <algorithm> 
#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <utility>

int main(){
    std::multimap<int, int> m;
    m.insert(std::make_pair(1,2));
    m.insert(std::make_pair(3,2));
    m.insert(std::make_pair(2,9));
    m.insert(std::make_pair(1,3));
    m.insert(std::make_pair(1,5));

    for(std::multimap<int, int>::iterator it = m.begin(); it != m.end(); ++it){
        std::cout << it->first << " " << it->second << std::endl;
    }

    std::multimap<int, int>::reverse_iterator rit = m.rbegin();
    std::cout << rit->first << " " << rit->second << std::endl;

    return 0;
}
