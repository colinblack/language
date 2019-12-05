#include <iostream>
#include <set>
#include <map>
#include <iterator>

using namespace std;

int main() {
    map<int, int> s;
    s[2] = 1;
    s[3] = 2;
    s[5] = 3;
    s[6] = 4;
    s[8] = 5;
    s[9] = 6;
    s[11] = 7;
    s[12] = 8;

    for(auto it = s.begin(); it != s.end();)
    {
        
        int a = it->first;
        ++it;
        int b = it->first;
        --it;
        
    
    
        if(a%2 == 0)
        {
            it = s.erase(it);
            it++;
        }
        else if(b%2==0)
        {
            it++;
            it = s.erase(it);
        }
        else
            it++;
    
    }
	
	for(auto& e : s)
	{
		cout << e.first << endl;
	}
	auto it = s.find(9);	
   
	cout << distance(s.begin(), it);
 
    return 0;

}
