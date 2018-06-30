#include <iostream>
#include <vector>

using std::ostream;

class C
{
public:
	explicit C(const std::string& s){}
	/*std::ostream& operator<<(std::ostream & os)
	{
	os << this->a << std::endl;
	return os;
	}*/
	//friend ostream& operator<<(ostream & os, const C& c);
private:
	int a = 1;
};

////全局重载 需申明为友元
//ostream& operator<<(ostream & os, const C& c)
//{
//	os << c.a;
//	return os;
//}


int main()
{
	std::vector<C> vs;
	for (const C& elem: vs) 
	{
		std::cout << elem << std::endl;
	}

	return 0;
}