#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>  


using std::vector;

struct Item
{
	int i;
	Item(int a): i(a)
	{
	}
};

struct Demo
{
	int a_;
	int b_;
	vector<Item> v_;
	Demo()
	{
		a_ = 0;	
		b_ = 0;
		std::cout << "no param " << std::endl;
	}

	Demo(int a, int b, vector<Item>& v)
	{
		a_ = a;	
		b_ = b;
		v_ = v;
		std::cout << "param " << std::endl;
	}
	Demo(const Demo& obj)
	{
		a_ = obj.a_;	
		b_ = obj.b_;
		v_ = std::move(obj.v_);
		std::cout << "copy construct " << std::endl;
	}
	Demo& operator= (const Demo& obj)
	{
		a_ = obj.a_;
		b_ = obj.b_;
		v_ = std::move(obj.v_);
		std::cout << "copy operator " << std::endl;
	}

};


int main()
{
	vector<Item> v;
	v.push_back(Item(1));
	std::unordered_map<unsigned, Demo> m;
	m.insert({1, Demo(1, 2, v)});
	m[1] = Demo(1, 2, v);
	std::cout << m[1].a_ << " " << m[1].b_ << " " << m[1].v_.size() << " " << v.size() << std::endl;	
	return 0;
}
