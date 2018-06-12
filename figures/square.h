#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "math.h"
#include "figure.h"
using namespace std;

class Square : public Figure
{
private:
    double x1,y1,x2,y2,x3,y3,x4,y4;
public:
    Square(): Figure("square"){x1=x2=x3=x4=y1=y2=y3=y4=0;}
    Square(double x11,double y11,double x22,double y22,double x33,double y33,double x44,double y44)
    : Figure("square")
    {
        x1=x11; y1=y11; x2=x22; y2=y22;
        x3=x33; y3=y33; x4=x44; y4=y44;
    }
    virtual void Print()
    {
        Figure::Print();
        cout<<"Vertices of the square:"<<endl;
        cout<<"("<<x1<<","<<y1<<")"<<endl;
        cout<<"("<<x2<<","<<y2<<")"<<endl;
        cout<<"("<<x3<<","<<y3<<")"<<endl;
        cout<<"("<<x4<<","<<y4<<")"<<endl;
    }
    double Length(double x1, double y1, double x2, double y2)
    {
        return sqrt(powf(x2-x1,2)+powf(y2-y1,2));
    }
    virtual double GetPerimeter()
    {
        double d=0;
        d+=4*Length(x1,y1,x2,y2);
        return d;
    }
    virtual double GetArea()
    {
        double d;
        d=Length(x1,y1,x2,y2);
        return d*d;
    }
    ~Square(){}
};

#endif // SQUARE_H
