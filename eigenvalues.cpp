#include <iostream>
#include <math.h>

using namespace std;

double A[3][3] = {{3,1,4},{5,2,0},{1,8,8}};
double x1,x2,x3,x2d,x2m,x3d,x3m;
double a,b,c,d,D,Q,R,S,fi,pi=3.1415926535;
int n=3;

int sgn (double val)
{
    if(fabs(val)<0.0001)
        return 0;
    if(val > 0)
        return 1;
    else return -1;
}

int main()
{
    setlocale(LC_ALL,"Russian");
    a=-1;
    b=A[0][0]+A[1][1]+A[2][2];
    c=A[2][1]*A[1][2]+A[1][0]*A[0][1]-A[0][0]*A[1][1]-A[0][0]*A[2][2]-A[1][1]*A[2][2]+A[0][2]*A[2][0];
    d=A[0][0]*A[1][1]*A[2][2]+A[2][0]*A[0][1]*A[1][2]+A[1][0]*A[2][1]*A[0][2]-A[0][0]*A[2][1]*A[1][2]
    -A[1][0]*A[0][1]*A[2][2]-A[0][2]*A[1][1]*A[2][0];

    a=-b; b=-c; c=-d;

    //D=-4*b*b*b*d+b*b*c*c-4*a*c*c*c+18*a*b*c*d-27*a*a*d*d;
    Q=(a*a-3*b)/9;
    R=(2*a*a*a-9*a*b+27*c)/54;
    S=Q*Q*Q-R*R;
    if(S>0)
    {
        cout<<"S>0"<<endl;
        cout<<"3 вещественных корн€"<<endl;
        fi=(1/3.)*acos(R/sqrt(Q*Q*Q));
        x1=-2*sqrt(Q)*cos(fi)-a/3;
        x2=-2*sqrt(Q)*cos(fi+(2/3.)*pi)-a/3;
        x3=-2*sqrt(Q)*cos(fi-(2/3.)*pi)-a/3;
        cout<<"x1= "<<x1<<endl;
        cout<<"x2= "<<x2<<endl;
        cout<<"x3= "<<x3<<endl;
    }
    if(S<0)
    {
        cout<<"S<0"<<endl;
        cout<<"S= "<<S<<endl;
        cout<<"1 вещественный и 2 комплексных корн€"<<endl;
        if(Q>0)
        {
            cout<<"Q>0"<<endl;
            fi=(1/3.)*acosh(fabs(R)/sqrt(Q*Q*Q));
            x1=-2*sgn(R)*sqrt(Q)*cosh(fi);
            x2d=sgn(R)*sqrt(Q)*cosh(fi)-a/3;
            x2m=sqrt(3*Q)*sinh(fi);
            cout<<"x1= "<<x1<<endl;
            cout<<"x2= "<<x2d<<"+ i*"<<x2m<<endl;
            cout<<"x3= "<<x2d<<"- i*"<<x2m<<endl;
        }
        if(Q<0)
        {
            cout<<"Q= "<<Q<<endl;
            cout<<"Q<0"<<endl;
            fi=(1/3.)*asinh(fabs(R)/sqrt(fabs(powf(Q,3))));
            x1=-2*sgn(R)*sqrt(fabs(Q))*sinh(fi)-a/3;
            x2d=sgn(R)*sqrt(fabs(Q))*sinh(fi)-a/3;
            x2m=sqrt(3)*sqrt(fabs(Q))*cosh(fi);
            cout<<"x1= "<<x1<<endl;
            cout<<"x2= "<<x2d<<"+ i*"<<x2m<<endl;
            cout<<"x3= "<<x2d<<"- i*"<<x2m<<endl;
        }
        if(Q==0)
        {
            cout<<"Q=0"<<endl;
            x1=-1*powf(c-(a*a*a)/27,1/3.)-a/3;
            x2d=-(a+x1)/2;
            x2m=(1/2.)*sqrt(fabs((a-3*x1)*(a+x1)-4*b));
            cout<<"x1= "<<x1<<endl;
            cout<<"x2= "<<x2d<<"+ i*"<<x2m<<endl;
            cout<<"x3= "<<x2d<<"- i*"<<x2m<<endl;
        }

    }
    if(S==0)
    {
        cout<<"S=0"<<endl;
        cout<<"”равнение вырождено"<<endl;
        x1=-2*powf(R,1/3.)-a/3;
        x2=powf(R,1/3.)-a/3;
        cout<<"x1= "<<x1<<endl;
        cout<<"x2= "<<x2<<endl;

    }
    return 0;
}

/* mod(A-lam*E) = */

/*
    |a11 a12 a13|
    |a21 a22 a23|  =  a11a22a33 + a31a12a23 + a21a32a13 - a11a32a23 - a21a12a33 - a13a22a31
    |a31 a32 a33|
*/

/*
    |(a11-lam) a12 a13|
  = |a21 (a22-lam) a32|  =  (a11-l)(a22-l)(a33-l) + a31a12a23 + a21a32a13 - (a11-l)a32a23 - a21a12(a33-l) - a13(a22-l)a31
    |a31 a32 (a33-lam)|
*/

/*
a*l^3+b*l^2+c*l+d=0
a=-1
b=a11+a22+a33
c=a32*a23+a21*a12+a13*a31-a11*a22-a11*a33-a22*a33
d=a11*a22*a33+a31*a12*a23+a21*a32*a13-a11*a32*a23-a21*a12*a33-a13*a22*a31
*/

/*
D=-4b^3d+b^2c^2-4ac^3+18abcd-27a^2d^2
D>0 3 вещественных корн€
D<0 1 вещественный и 2 комплексных корн€
D=0 хот€ бы 2 корн€ совпадают
*/

/*
ѕо тригонометрической формуле ¬иета

Q=(a^2-3b)/9
R=(2a^3-9ab+27c)/54
S=Q^3-R^2

1.S>0

fi=(1/3)arccos(R/sqrt(Q^3))
x1=-2sqrt(Q)cos(fi)-a/3
x2=-2sqrt(Q)cos(fi+(2/3)pi)-a/3
x3=-2sqrt(Q)cos(fi-(2/3)pi)-a/3

2.S<0

2.1. Q>0
fi=(1/3)arch(mod(R)/sqrt(Q^3))
x1=-2sgn(R)sqrt(Q)ch(fi)
x2,3=sgn(R)sqrt(Q)ch(fi)-a/3+-isqrt(3Q)sh(fi)

2.2. Q<0
fi=(1/3)arsh(mod(R)/sqrt(Q^3))
x1=-2sgn(R)sqrt(mod(Q))sh(fi)-a/3
x2,3=sgn(R)sqrt(Q)sh(fi)-a/3+-sqrt(3mod(Q))ch(fi)

2.3. Q=0
x1=-(c-a^3/27)^(1/3)-a/3
x2,3=-(a+x1)/2+-(i/2)sqrt(mod((a-3x1)(a+x1)-4b))

3.S=0
x1=-2sgn(R)sqrt(Q)-a/3=-2(R)^(1/3)-a/3
x2=sgn(R)sqrt(Q)-a/3=(R)^(1/3)-a/3

*/


