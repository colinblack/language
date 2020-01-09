//
// Created by root on 18-12-31.
//

//删除vector中指定元素方式性能对比
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <time.h>
#include <sys/time.h>
#include <cstdlib>

using std::vector;

void  ErasePopBack(vector<int>& v)
{
   for(auto it = v.begin(); it != v.end();)
   {
      if(*it % 2 == 0)
      {
          std::swap(*it, v.back());
          v.pop_back();
      }
      else
      {
          ++it;
      }
   }
}

void Erase(vector<int>& v)
{
    for(auto it = v.begin(); it != v.end();)
    {
        if(*it % 2 == 0)
        {
            it = v.erase(it);
        }
        else
        {
            ++it;
        }
    }

}

void Reverse(vector<int>& v)
{
    auto rit = v.end();
    for(auto it = v.begin(); it != v.end() && it != rit;)
    {
        if(*it % 2 == 0)
        {
            --rit;
        //    std::cout << "prev:" << *it << "  " <<  *rit << std::endl;
            std::swap(*it, *rit);
       //     std::cout << "end:" << *it << " " << *rit << std::endl;
        }
        else
        {
            ++it;
        }
    }

    v.erase(rit, v.end());
}


void Removeif(vector<int>& v)
{
    v.erase(std::remove_if(v.begin(), v.end(), [&](auto i){return i % 2 == 0;}));
}




void seq(vector<int>& v)
{
    std::iota(v.begin(), v.end(), 0);
}

void random(vector<int>& v)
{
    for(int i = 0; i < v.size(); ++i)
    {
       v[i] = random() %  100000000;
    }
}


int main()
{
    timeval begin, end;

    vector<int> v(100);
    srand(time(nullptr));

    //random(v);
    seq(v);

    gettimeofday(&begin, nullptr);

    //ErasePopBack(v);
    //Erase(v);
    Removeif(v);
    //Reverse(v);

    gettimeofday(&end, nullptr);


    int interval = 1000000*(end.tv_sec - begin.tv_sec) + (end.tv_usec - begin.tv_usec);
    std::cout << "time: " << interval/1000000.0 << std::endl;

   //std::cout << "time: " << (double)(e-b) << std::endl;
/*
    for(auto& e : v)
    {
       std::cout << e << std::endl;
    }*/

    return 0;
}

