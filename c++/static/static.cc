#include <iostream>
#include <string>
#include <map>

using namespace std;

class CBusinessLog
{
public:
	CBusinessLog(const std::string & name)
        : m_name(name), m_fd(-1), m_day(0){
    }
    ~CBusinessLog(){
        std::cout << "name:= " << m_name << " destory" << std::endl;
    }

protected:
	std::string m_name;
	int m_fd;
	int m_day;
};

class CBusinessLogHelper
{
public:
    CBusinessLogHelper(){
        std::cout << "consturct" << std::endl;
    }
    ~CBusinessLogHelper(){
        std::cout << "desturct" << std::endl;
    }

    static map<string, CBusinessLog *> s_logInstance;
    static CBusinessLog * GetInstance(const std::string & name);
    static void destory();
};

map<string, CBusinessLog *> CBusinessLogHelper::s_logInstance;

CBusinessLog * CBusinessLogHelper::GetInstance(const std::string & name)
{
	map<string, CBusinessLog *>::iterator it = s_logInstance.find(name);
	if (it == s_logInstance.end())
	{
		s_logInstance[name] = new CBusinessLog(name);
	}
	return s_logInstance[name];
}
//必须要手动释放
void CBusinessLogHelper::destory(){
    auto itr = s_logInstance.begin();
    while(itr != s_logInstance.end()){
        delete itr->second;
        itr->second = nullptr;
        itr = s_logInstance.erase(itr);
    }
}


int main()
{
    string a = "colin";
    //CBusinessLogHelper h;
	CBusinessLogHelper::GetInstance(a);
    //h.GetInstance(a);
    a = "cp";
	CBusinessLogHelper::GetInstance(a);
    //h.GetInstance(a);
    a = "colinus";
	CBusinessLogHelper::GetInstance(a);
    //h.GetInstance(a);
    a = "black";
	CBusinessLogHelper::GetInstance(a);
    //h.GetInstance(a);
    a = "colinblack";
	CBusinessLogHelper::GetInstance(a);
    //h.GetInstance(a);
   
    CBusinessLogHelper::destory();
    while(1);
	
    return 0; 
}

