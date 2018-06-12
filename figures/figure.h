#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include "string.h"
using namespace std;

class Figure
{
private:
    string name;
public:
    Figure();
    Figure(string n) {name=n;}
    Figure(Figure &f){*this=f;}
    string GetName() {return name;}
    void SetName(string n) {name=n;}
    virtual void Print() {cout<<"Figure "<<name<<endl;}
    virtual double GetPerimeter() {return 0;}
    virtual double GetArea() {return 0;}
    virtual ~Figure(){}
};

#endif // FIGURE_H
