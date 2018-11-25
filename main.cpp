#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printer(const int & val)
{
    std::cout << val << " ";
}

struct functor
{
    void operator()(const int& obj)
    {
        cout << obj << " ";
    }
};

int main()
{
    std::vector<int> vec{4,5,2,1,0};

    // method 1
    std::cout <<"method 1" << std::endl;
    for(int index = 0; index < vec.size(); ++index)
    {
        std::cout << vec[index] << " ";
    }
    std::cout <<endl;
    std::cout << "***************" << std::endl;

    std::cout << "method 2" << std::endl;
    for(auto iter = vec.begin(); iter != vec.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << endl;
    std::cout << "***************" << std::endl;

    // method 3
    std::cout << "method 3" << std::endl;
    for(auto elem: vec)
    {
        cout << elem << " ";
    }
    std::cout <<endl;
    std::cout << "***************" << std::endl;

    // method 4
    std::cout << "method 4" << std::endl;
    for_each(vec.begin(),vec.end(),printer);
    std::cout <<endl;
    std::cout << "***************" << std::endl;

    // method 5
    std::cout << "method 5" << std::endl;
    for_each(vec.begin(), vec.end(), functor());
    std::cout <<endl;
    std::cout << "***************" << std::endl;

    // method 6
    std::cout << "method 6" << std::endl;
    for_each(vec.begin(), vec.end(), [](const int& val)->void{cout << val << " ";});
    std::cout <<endl;
    std::cout << "***************" << std::endl;

    return 0;
}

