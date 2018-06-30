#include <iostream>

class Obj;

class ResCount
{
	friend class SmartPoint;
public:
	ResCount() :_p(nullptr), _cnt(0){}
	ResCount(Obj* p) :_p(p), _cnt(1){}
	~ResCount()
	{
		if (0 == _cnt) delete _p;
	}

private:
	Obj *_p;
	int _cnt;
};

class SmartPoint
{
public:
	SmartPoint(Obj* p)
	{
		_res_cnt = new ResCount(p);
	}
	SmartPoint(const SmartPoint& s)
	{
		_res_cnt = s._res_cnt;
		_res_cnt->_cnt++;
	}
	SmartPoint& operator=(const SmartPoint& s)
	{
		if (_res_cnt->_cnt == 0)
		{
			delete _res_cnt;
		}
		return *this;
	}
	~SmartPoint()
	{
		--_res_cnt->_cnt;
		if (_res_cnt->_cnt == 0)
		{
			delete _res_cnt;
		}
	}
private:
	ResCount* _res_cnt;
};

