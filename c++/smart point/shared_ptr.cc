#include <iostream>

template<class T>
class CSharedPtr;

template<class T>
class CResource
{
private:
	friend class CSharedPtr<T>;
	CResource(T* p) : obj(p), count(1){}
	~CResource(){ delete obj;}

private:
	std::size_t count;
	T* obj; 
};


template<class T>
class CSharedPtr
{
public:
	CSharedPtr(T* p) : res(new CResource<T>(p)){}
	~CSharedPtr()
	{
		__sync_fetch_and_sub(&res->count, 1);
		if(res->count == 0)
		{
			std::cout << "delete" << std::endl;
			delete res;
		}
	}
	CSharedPtr(const CSharedPtr<T>& ptr)
		: res(ptr.res)
	{
		__sync_fetch_and_add(&res->count, 1);
	}

	CSharedPtr& operator=(const CSharedPtr<T>& ptr)
	{
		if(ptr.res != res)
		{
			__sync_fetch_and_add(&ptr.res->count, 1);
			__sync_fetch_and_sub(&res->count, 1);
			if(res->count == 0)
			{
				delete res;
				std::cout << "delete" << std::endl;
			}
			else
				std::cout << "left: " << res->count << std::endl;
			res = ptr.res;
		}

		return *this;
	}

private:
	CResource<T>* res;
};


int main()
{
    int *i = new int(2);
    {
    	CSharedPtr<int> ptr1(i);
        {
    		CSharedPtr<int> ptr2(ptr1);
            {
    			CSharedPtr<int> ptr3 = ptr2;
            }
        }
    }

	return 0;
}
