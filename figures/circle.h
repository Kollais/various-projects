#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "math.h"
#include "figure.h"
using namespace std;

class Circle : public Figure
{
    private:
    double x,y,r;
public:
    Circle(): Figure("circle"){x=y=r=0;}
    Circle(double x1,double y1,double r1)
    : Figure("circle")
    {
        x=x1; y=y1; r=r1;
    }
    virtual void Print()
    {
        Figure::Print();
        cout<<"Center and radius of circle:"<<endl;
        cout<<"("<<x<<","<<y<<")"<<endl;
        cout<<r<<endl;
    }
    virtual double GetPerimeter()
    {
        return 2*3.141592*r;
    }
    virtual double GetArea()
    {
        return 3.141592*r*r;
    }
    ~Circle(){}
};

#endif // CIRCLE_H
