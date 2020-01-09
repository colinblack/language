#include  <iostream>
#include  <vector>
using namespace std;
void Printvector(vector<int> &l)
{
    vector<int>::iterator it = l.begin();
    while (it != l.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}
void Testvector()
{
    vector<int> l;
	l.reserve(10);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);

    Printvector(l);
	std::cout << "capacity: " << l.capacity() << std::endl;
}
int main()
{
    Testvector();
    return 0;
}
