//使用RAII惯用法封装互斥锁
#include <iostream>
#include "unistd.h"
#include "types.h"
#include "pthread.h"

typedef int pthread_mutex_t ;

class Critical
{
private:
	friend class Lock;
public:
	Critical(){ pthread_mutex_init(&_critical_section, nullptr); }
	~Critical(){ pthread_mutex_destroy(&_critical_section); }
private:
	void acquire(){ pthread_mutex_lock(&_critical_section); }
	void realse(){ pthread_mutex_unlock(&_critical_section);}

private:
	pthread_mutex_t _critical_section;
};

class Lock
{
public:
	Lock(Critical& c) :_c(c)
	{
		_c.acquire();
	}
	~Lock()
	{
		_c.realse();
	}
	
private:
	Critical& _c;
};

