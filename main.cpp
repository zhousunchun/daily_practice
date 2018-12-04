
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <getopt.h>


using namespace std;

void printer(const std::vector<int> & arr);

static struct option long_options[] =
{
    {"method",required_argument, NULL, 'm'}
};

void swap(std::vector<int> &arr, const int& i, const int& j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectionSort(std::vector<int> & arr)
{
    std::cout << "The result of selectionSort method"<< std::endl;
    if(arr.empty()||arr.size()<2)
    {
        return ;
    }

    for(int i=0; i<arr.size()-1; i++)
    {
        int minIndex = i;
        for(int j=i+1; j<arr.size(); ++j)
        {
            minIndex = arr[j] < arr[minIndex]?j:minIndex;
        }
        swap(arr,i, minIndex);
    }
}

void bubbleSort(std::vector<int>&  arr)
{
    std::cout << "The result of bubbleSort method"<< std::endl;
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

int main(int argc,char *argv[])
{
    std::vector<int> vec;
    srand(time(0));
    std::cout << "Generate a random array" << std::endl;
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

    std::cout << "Utilize system provided method to sort the array"<< std::endl;
    system_sort(vec1);
    printer(vec1);

    int option=getopt_long(argc,argv,"m:",long_options, 0);
    if(-1 == option)
    {
        std::cerr << "parser parameter error!"<< std::endl;
    }

    switch(option)
    {
    case 'm':
    {
        stringstream arg;
        std::string m_arg;
        arg<<optarg;
        arg>>m_arg;

        if(m_arg=="bubbleSort")
        {
            bubbleSort(vec2);
            printer(vec2);
        }
        else if(m_arg=="selectionSort")
        {
            selectionSort(vec2);
            printer(vec2);
        }
        else
        {
            std::cerr<<"This program does not contain this sort method" << std::endl;
            return -1;
        }
    }
        break;
    default:
        {
            std::cerr<<"This program can't parse this option" << std::endl;
            return -1;
        }
        break;
    }


    std::cout << (isEqual(vec1,vec2) ? "NICE" : "FUCKED!") << std::endl;

    return 0;
}

