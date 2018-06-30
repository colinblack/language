#include <iostream>
#include <fstream>
#include <cstdlib>

//int main()
//{
//	char buf[1024] = { 0 };
//	std::ifstream  in("test.txt");
//	while (in.getline(buf, sizeof(buf)))
//		;
//
//	for (auto i:buf)
//	{
//		std::cout << i;
//	}
//	return  0;
//}

// reading a text file
using namespace std;

int main() {
	char buffer[256];
	ifstream in("test.txt");
	if (!in.is_open())
	{
		cout << "Error opening file"; exit(1);
	}
	while (in.getline(buffer, sizeof(buffer)))
	{
		cout << strlen(buffer)  << "   buffer1   " << buffer[0] << endl;
	}

	return 0;
}