#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "string.h"
#include "math.h"
#include "figure.h"
using namespace std;

class Triangle : public Figure
{
private:
    double x1,y1,x2,y2,x3,y3;
public:
    Triangle(): Figure::Figure("triangle")
    {x1=x2=x3=y1=y2=y3=0;}
    Triangle(double x11,double y11,double x22,double y22,double x33,double y33) : Figure::Figure("triangle")
    {
        x1=x11; y1=y11; x2=x22;
        y2=y22; x3=x33; y3=y33;
    }
    virtual void Print()
    {
        Figure::Print();
        cout<<"Vertices of the triangle:"<<endl;
        cout<<"("<<x1<<","<<y1<<")"<<endl;
        cout<<"("<<x2<<","<<y2<<")"<<endl;
        cout<<"("<<x3<<","<<y3<<")"<<endl;
    }
    double Length(double x1, double y1, double x2, double y2)
    {
        return sqrt(powf(x2-x1,2)+powf(y2-y1,2));
    }
    virtual double GetPerimeter()
    {
        double d=0;
        d+=Length(x1,y1,x2,y2);
        d+=Length(x1,y1,x3,y3);
        d+=Length(x2,y2,x3,y3);
        return d;
    }
    virtual double GetArea()
    {
        double a,b,c,p;
        a=Length(x1,y1,x2,y2);
        b=Length(x1,y1,x3,y3);
        c=Length(x2,y2,x3,y3);
        p=(a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    ~Triangle(){}
};

#endif // TRIANGLE_H
