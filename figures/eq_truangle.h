#ifndef EQ_TRIANGLE_H
#define EQ_TRIANGLE_H

#include <iostream>
#include "math.h"
#include "figure.h"
using namespace std;

class Eq_triangle : public Figure
{
private:
    double x1,y1,x2,y2,x3,y3;
public:
    Eq_triangle(): Figure("eq_triangle"){x1=x2=x3=y1=y2=y3=0;}
    Eq_triangle(double x11,double y11,double x22,double y22,double x33,double y33) : Figure("eq_triangle")
    {
        x1=x11; y1=y11; x2=x22;
        y2=y22; x3=x33; y3=y33;
    }
    virtual void Print()
    {
        Figure::Print();
        cout<<"Vertices of the eq_triangle:"<<endl;
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
        d+=3*Length(x1,y1,x2,y2);
        return d;
    }
    virtual double GetArea()
    {
        double a,p;
        a=Length(x1,y1,x2,y2);
        p=(3*a)/2;
        return sqrt(p*3*(p-a));
    }
    ~Eq_triangle(){}
};

#endif // EQ_TRIANGLE_H
