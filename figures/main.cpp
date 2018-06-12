#include <iostream>
#include <fstream>
#include <stdio.h>
#include "figure.h"
#include "triangle.h"
#include "eq_truangle.h"
#include "rectangle.h"
#include "square.h"
#include "rhomb.h"
#include "circle.h"
#include "ellipse.h"

using namespace std;

int main(int argc, char* argv[])
{
    int num;
    string str;
    double * par;

    ifstream file("file.txt",ios::in);
    //ifstream file (argv[1],ios::in);
    file>>num;
    cout<<num<<endl;
    Figure * fig [num];

    for(int i=0;i<num;i++)
    {
        file>>str;
        cout<<str<<endl;
        if(str=="triangle")
        {
             par=new double [6];
             for(int j=0;j<6;j++)
             {
                 file>>par[j];
                 cout<<par[j]<<" ";
             }
             cout<<endl;
             fig[i]=new Triangle(par[0],par[1],par[2],par[3],par[4],par[5]);
             delete [] par;
        }
        if(str=="eq_triangle")
        {
             par=new double [6];
             for(int j=0;j<6;j++)
             {
                 file>>par[j];
                 cout<<par[j]<<" ";
             }
             cout<<endl;
             fig[i]=new Eq_triangle(par[0],par[1],par[2],par[3],par[4],par[5]);
             delete [] par;
        }
        if(str=="rectangle")
        {
             par=new double [8];
             for(int j=0;j<8;j++)
             {
                 file>>par[j];
                 cout<<par[j]<<" ";
             }
             cout<<endl;
             fig[i]=new Rectangle(par[0],par[1],par[2],par[3],par[4],par[5],par[6],par[7]);
             delete [] par;
        }
        if(str=="square")
        {
             par=new double [8];
             for(int j=0;j<8;j++)
             {
                 file>>par[j];
                 cout<<par[j]<<" ";
             }
             cout<<endl;
             fig[i]=new Square(par[0],par[1],par[2],par[3],par[4],par[5],par[6],par[7]);
             delete [] par;
        }
        if(str=="rhomb")
        {
             par=new double [8];
             for(int j=0;j<8;j++)
             {
                 file>>par[j];
                 cout<<par[j]<<" ";
             }
             cout<<endl;
             fig[i]=new Rhomb(par[0],par[1],par[2],par[3],par[4],par[5],par[6],par[7]);
             delete [] par;
        }
        if(str=="circle")
        {
            par=new double [3];
             for(int j=0;j<3;j++)
             {
                 file>>par[j];
                 cout<<par[j]<<" ";
             }
             cout<<endl;
             fig[i]=new Circle(par[0],par[1],par[2]);
             delete [] par;
        }
        if(str=="ellipse")
        {
            par=new double [4];
             for(int j=0;j<4;j++)
             {
                 file>>par[j];
                 cout<<par[j]<<" ";
             }
             cout<<endl;
             fig[i]=new Ellipse(par[0],par[1],par[2],par[3]);
             delete [] par;
        }
    }

    for(int i=0;i<num;i++)
    {
        cout<<endl;
        fig[i]->Print();
        cout<<"Perimeter: "<<fig[i]->GetPerimeter()<<endl;
        cout<<"Area: "<<fig[i]->GetArea()<<endl;
    }

    file.close();
    return 0;
}
