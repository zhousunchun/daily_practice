#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
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



class LeastSquare
{
    double a,b;
public:
    LeastSquare(const vector<double> &x, const vector<double> & y)
    {
        double t1=0, t2=0, t3=0, t4=0;
        for(int i=0; i<x.size(); ++i)
        {
            t1+=x[i]*x[i];
            t2 +=x[i];
            t3 += x[i]*y[i];
            t4 += y[i];
        }
        a = (t3*x.size() - t2*t4)/(t1*x.size()-t2*t2);
        b = (t1*t4-t2*t3)/(t1*x.size()-t2*t2);
    }
    double getY(const double x) const
    {
        return a*x +b;
    }
    void print() const
    {
        cout << "y = "<< a << "x + "<<b<<"\n";
    }
};


int main()
{
    std::vector<double> x;
    std::vector<double> y;
    double beta_1 =1, beta_2 = 2;
    srand(time(0));
    RandNumber r;
    std::cout << "Generate a random array x and y" << std::endl;
    for(int index = 0; index < 200; ++index)
    {
        x.emplace_back(r.get(0,100));
        y.emplace_back(beta_2+x.back()*beta_1+r.get(-1,1));
    }

    LeastSquare ls(x,y);
    ls.print();

    cv::Mat M(400,400,CV_8UC3,cv::Scalar(255,255,255));
    for(size_t index =0; index <x.size(); ++index)
    {
        cv::circle(M,cv::Point(10*x[index],10*y[index]),2,cv::Scalar(0,0,0));
    }


    cv::imshow("test",M);

    cv::waitKey();

    return 0;
}
