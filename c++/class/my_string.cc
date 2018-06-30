//一个深拷贝的string类
#include <iostream>
#include <cstring>


namespace cp{
	class string{
	public:
		string(char* str) :_str(str), _len(strlen(str)){}
		~string(){ delete _str; }
		string(string& str){
			_str = new char[str._len+1];
			strcpy(_str, str._str);
			_len = str._len;
		}
		string& operator= (const string& str){
			if (this == &str)
			{
				return *this;
			}
			delete _str;
			_str = new char[str._len+1];
			strcpy(_str, str._str);
			_len = str._len;
			return *this;
		}


	private:
		int _len;
		char* _str;
	};
}



int main()
{

	return 0;
}
