#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <iostream>
#include "math.h"
#include "figure.h"
using namespace std;

class Ellipse : public Figure
{
    private:
    double a,b,x,y;
public:
    Ellipse(): Figure("ellipse"){a=b=x=y=0;}
    Ellipse(double a1,double b1,double x1,double y1)
    : Figure("ellipse")
    {
        a=a1; b=b1; x=x1; y=y1;
    }
    virtual void Print()
    {
        Figure::Print();
        cout<<"Center and big and small semi-axises of ellipse:"<<endl;
        cout<<"("<<x<<","<<y<<")"<<endl;
        cout<<a<<" "<<b<<endl;
    }
    virtual double GetPerimeter()
    {
        double l;
        l=4*(3*(a+b)-sqrt((3*a+b)*(a+3*b)));
        return l;
    }
    virtual double GetArea()
    {
        return 3.141592*a*b;
    }
    ~Ellipse(){}
};

#endif // ELLIPSE_H
