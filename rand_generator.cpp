
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;
class RandNumber
{
public:
    RandNumber()
    {
        srand(time(0));
    }
    double get(int begin=0, int end = 1)
    {
        return (double)rand()/RAND_MAX * (end-begin) + begin;
    }
};

int main()
{
    RandNumber r,t;
    for(int i = 0; i < 10; ++i)
    {
        std::cout <<r.get() <<std::endl;
    }
    return 0;
}


