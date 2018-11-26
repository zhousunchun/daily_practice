
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(std::vector<int> &arr, const int& i, const int& j)
{
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}

void bubbleSort(std::vector<int>&  arr)
{
    if(arr.empty() || arr.size()<2)
        return;

    for(int e = arr.size()-1;e>0; e--)
    {
        for(int i=0; i<e; i++)
        {
            if(arr[i] > arr[i+1])
            {
                swap(arr, i, i+1);
            }
        }
    }
}

void printer(const std::vector<int> & arr)
{
    for_each(arr.begin(),arr.end(),[](const int& val)->void{cout << val << " ";});
    std::cout << endl;
    std::cout << "*********************" << std::endl;
}

void system_sort(std::vector<int> &arr)
{
    std::sort(arr.begin(),arr.end(),[](int a, int b) {return a < b;}); // small to big
}

bool isEqual(const std::vector<int> vec1, const std::vector<int> vec2)
{
    if(vec1.size()!= vec2.size())
        return false;

    for(int index = 0; index < vec1.size(); ++index)
    {
        if(vec1[index] != vec2[index])
            return false;
    }

    return true;
}

int main()
{
    std::vector<int> vec;
    srand(time(0));
    for(int index = 0; index < 20; ++index)
    {
        vec.emplace_back(rand()%100);
    }
    printer(vec);

    std::vector<int> vec1, vec2;
    vec1.resize(vec.size());
    vec1.assign(vec.begin(),vec.end());
    vec2.resize(vec.size());
    vec2.assign(vec.begin(),vec.end());

    system_sort(vec1);
    printer(vec1);

    bubbleSort(vec2);
    printer(vec2);

    std::cout << (isEqual(vec1,vec2) ? "NICE" : "FUCKED!") << std::endl;

    return 0;
}

