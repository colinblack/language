//箭头操作符的应用
//F:\workspace\project\majiang\yunnan_zhenxiong\loginsvr\LoginServer\GameServerExe\GameServerExeDlg.cpp p128
//m_spGameMainCreater->StartService( m_ServerConfig);

#include  <iostream>
class A{
public:
	void func1()
	{
		std::cout << "A::func1 \n" << std::endl;
	}

};

class B{
public:
	A* operator->(){
		return _p;
	}
public:
	A* _p = nullptr;
};

int main()
{
	B b;
	b->func1();

	return 0;
}