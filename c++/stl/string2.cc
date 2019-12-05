#include <iostream>
#include <string>


using namespace std;
void fun()
{
    string str;
	string c = "c";
	string b = "d";
    str += c + "a" + b + "b";

    cout << str;
}

int main()
{
	fun();

	return 0;
}
