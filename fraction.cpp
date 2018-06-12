#include <iostream>
#include <math.h>

using namespace std;

class Drobi
{
    protected:
        int a; //���������
        int b; //�����������
        int c; //����� �����
        bool sign; //����
    public:
        Drobi(){a=0; b=1; c=0; sign=true;} //����������� �� ���������
        Drobi(int A, int B, bool S){a=A; b=B; c=0; sign=S;}  //����������� � ����������� ��� ����� �����
        Drobi(int C, int A, int B, bool S){a=A; b=B; c=C; sign=S;} //����������� � ����������� � ����� ������
        Drobi(Drobi& n) {*this=n;} //����������� �����������
        void operator=(const Drobi &n) //��������������� ��������� ������������
        {
            if(this==&n)return; //���� ���� � ��� �� ���������, �� ��������
            a=n.a; b=n.b; c=n.c;
            sign=n.sign;
            if(a>b) SeparateIntPart(); //���� ����� ������������, �������� ����� �����
            simpify(); //�������� �����
        }
        Drobi operator+(Drobi &n) //��������������� �������� �������� ����� � ������
        {
            AddIntPart(); //��������� ����� ����� � ���������
            Drobi n1;
            int x=a*n.b,y=b*n.a,z=b*n.b;
            if(sign==n.sign) //���� ���������� �����
            {
                if(b==n.b) //���� ������ �����������
                {
                    n1.a=a+n.a;
                    n1.b=b;
                    n1.sign=sign;
                }
                else
                {
                    n1.a=x+y;
                    n1.b=z;
                    n1.sign=sign;
                }
            }
            else
            {
                if(x>y) //���� ������ ����� ������ ������
                {
                    n1.a=x-y;
                    n1.sign=sign;
                }
                else
                {
                    n1.a=y-x;
                    n1.sign=n.sign;
                }
                n1.b=z;
            }
            return n1;
        }
        Drobi operator-(Drobi &n) //��������������� �������� ��������� ����� �� �����
        {
            AddIntPart();
            Drobi n1;
            int x=a*n.b,y=b*n.a,z=b*n.b;
            if(sign==n.sign)
            {
                if(b==n.b)
                {
                    if(a>n.a)
                    {
                        n1.a=a-n.a;
                        n1.b=b;
                        n1.sign=sign;
                    }
                    else
                    {
                        n1.a=n.a-a;
                        n1.b=b;
                        n1.sign=!sign;
                    }
                }
                else
                {
                    if(x>y)
                    {
                        n1.a=x-y;
                        n1.sign=sign;
                    }
                    else
                    {
                        n1.a=y-x;
                        n1.sign=!sign;
                    }
                    n1.b=z;
                }
            }
            else
            {
                if(b==n.b)
                {
                    n1.a=a+n.a;
                    n1.b=b;
                    n1.sign=sign;
                }
                else
                {
                    n1.a=x+y;
                    n1.b=z;
                    n1.sign=sign;
                }
            }
            return n1;
        }
        Drobi operator*(Drobi &n) //��������������� �������� �������� ����� �� �����
        {
            AddIntPart();
            Drobi n1;
            n1.a=a*n.a;
            n1.b=b*n.b;
            n1.sign=sign&&n.sign;
            return n1;
        }
        Drobi operator/(Drobi &n) //��������������� �������� ������� ����� �� �����
        {
            AddIntPart();
            Drobi n1;
            n1.a=a*n.b;
            n1.b=b*n.a;
            n1.sign=sign&&n.sign;
            return n1;
        }
        inline void simpify() //��������� ����� 2/4 = 1/2
        {
            int i=(a<b) ? a:b;
            while(i>1)
            {
                if(!(a%i)&&!(b%i))
                {
                    a/=i;
                    b/=i;
                    i=(a<b)? a:b;
                }
                else
                    i--;
            }
        }
        inline void SeparateIntPart() //��������� ����� ����� �� ������������ �����
        {
            if(!c)
            {
                c=a/b;
                a-=c*b;
            }
            else
            {
                c+=a/b;
                a-=c*b;
            }
            if(a==0)
                b=1;
        }
        void AddIntPart() //���������� ����� ����� � ���������
        {
            if(c)
            {
                a+=c*b;
                c=0;
            }
        }
        Drobi operator+(int co) //�������� ����� � ���������� ������
        {
            AddIntPart();
            Drobi n1;
            n1.a=a; n1.b=b; n1.c=c; n1.sign=sign;
            int c1;
            c1=co*n1.b;
            if(sign)
            {
                if(co<0)
                {
                    if(n1.a>fabs(c1))
                        n1.a+=co*b;
                    else
                    {
                        n1.a=fabs(c1)-n1.a;
                        n1.sign=!sign;
                    }
                }
                else
                    n1.a+=co*b;
            }
            else
            {
                if(co<0)
                    n1.a+=co*b;
                else
                {
                    if(n1.a>fabs(c1))
                        n1.a-=co*b;
                    else
                    {
                        n1.a=fabs(c1)-n1.a;
                        n1.sign=!sign;
                    }
                }
            }
            return n1;
        }
        Drobi operator-(int co) //��������� �� ����� ��������� ������
        {
            AddIntPart();
            Drobi n1;
            n1.a=a; n1.b=b; n1.c=c; n1.sign=sign;
            int c1;
            c1=co*n1.b;
            if(sign)
            {
                if(co<0)
                    n1.a+=co*b;
                else
                {
                    if(n1.a>c1)
                        n1.a-=co*b;
                    else
                    {
                        n1.a=c1-n1.a;
                        n1.sign=!sign;
                    }
                }
            }
            else
            {
                if(co<0)
                {
                    if(n1.a>fabs(c1))
                        n1.a-=fabs(c1);
                    else
                    {
                        n1.a=fabs(c1)-n1.a;
                        n1.sign=!sign;
                    }
                }
                else
                    n1.a+=co*b;
            }
            return n1;
        }
        Drobi operator*(int co) //��������� ����� �� ��������� ������
        {
            AddIntPart();
            Drobi n1;
            n1.a=a; n1.b=b; n1.c=c; n1.sign=sign;
            if(co<0)
            {
                int c1=a*co;
                n1.a=fabs(c1);
                n1.sign=!sign;
            }
            else
                n1.a=a*co;
            return n1;
        }
        Drobi operator/(int co) //��������� ����� �� ��������� ������
        {
            AddIntPart();
            Drobi n1;
            n1.a=a; n1.b=b; n1.c=c; n1.sign=sign;
            if(co<0)
            {
                int c1=b*co;
                n1.b=fabs(c1);
                n1.sign=!sign;
            }
            else
                n1.b=b*co;
                return n1;
        }
        Drobi PutToDegree(int d) //���������� ����� � ����������� �������
        {
            AddIntPart();
            Drobi n1;
            n1.a=a; n1.b=b; n1.c=c; n1.sign=sign;
            if(d<0)
                swap(n1.a,n1.b);
            d=fabs(d);
            n1.a=powf(n1.a,d);
            n1.b=powf(n1.b,d);
            return n1;
        }
        friend Drobi operator+(int co,Drobi n); //�������� ����� � ���������� �����
        friend Drobi operator-(int co,Drobi n); //��������� �� ����� ��������� �����
        friend Drobi operator*(int co,Drobi n); //��������� ����� �� ��������� �����
        friend Drobi operator/(int co,Drobi n); //������� ����� �� ��������� �����
        friend ostream& operator<<(ostream& ,Drobi&); //��������������� ��������� ������ �����
        friend istream& operator>>(istream& ,Drobi&); //��������������� ��������� ����� �����
};

Drobi operator+(int co,Drobi n)
{
    n.AddIntPart();
    Drobi n1;
    n1.a=n.a; n1.b=n.b; n1.c=n.c; n1.sign=n.sign;
    int c1;
    c1=co*n1.b;
    if(n1.sign)
    {
        if(co<0)
        {
            if(n1.a>fabs(c1))
                n1.a+=co*n1.b;
            else
            {
                n1.a=fabs(c1)-n1.a;
                n1.sign=!n1.sign;
            }
        }
        else
            n1.a+=co*n1.b;
    }
    else
    {
        if(co<0)
            n1.a+=co*n1.b;
        else
        {
            if(n1.a>fabs(c1))
                n1.a-=co*n1.b;
            else
            {
                n1.a=fabs(c1)-n1.a;
                n1.sign=!n1.sign;
            }
        }
    }
    return n1;
}

Drobi operator-(int co,Drobi n)
{
    n.AddIntPart();
    Drobi n1;
    n1.a=n.a; n1.b=n.b; n1.c=n.c; n1.sign=n.sign;
    int c1;
    c1=co*n1.b;
    if(n1.sign)
    {
        if(co<0)
            n1.a+=co*n1.b;
        else
        {
            if(n1.a>c1)
                n1.a-=co*n1.b;
            else
            {
                n1.a=c1-n1.a;
                n1.sign=!n1.sign;
            }
        }
    }
    else
    {
        if(co<0)
        {
            if(n1.a>fabs(c1))
                n1.a-=fabs(c1);
            else
            {
                n1.a=fabs(c1)-n1.a;
                n1.sign=!n1.sign;
            }
        }
        else
            n1.a+=co*n1.b;
    }
    return n1;
}

Drobi operator*(int co,Drobi n)
{
    n.AddIntPart();
    Drobi n1;
    n1.a=n.a; n1.b=n.b; n1.c=n.c; n1.sign=n.sign;
    if(co<0)
    {
        int c1=n1.a*co;
        n1.a=fabs(c1);
        n1.sign=!n1.sign;
    }
    else
        n1.a=n1.a*co;
    return n1;
}

Drobi operator/(int co,Drobi n)
{
    n.AddIntPart();
    Drobi n1;
    n1.a=n.a; n1.b=n.b; n1.c=n.c; n1.sign=n.sign;
    if(co<0)
    {
        int c1=n1.b*co;
        n1.b=fabs(c1);
        n1.sign=!n1.sign;
    }
    else
       n1.b=n1.b*co;
    return n1;
}

ostream& operator<<(ostream& stream,Drobi& n)
{
    if(!n.sign)
        stream<<"-";
    if(n.c)
    {
        if(n.a)
            stream<<n.c<<" "<<n.a<<"/"<<n.b<<endl;
        else
            stream<<n.c<<endl;
    }
    else if(n.a)
            stream<<n.a<<"/"<<n.b<<endl;
    else
        stream<<"0"<<endl;
   return stream;
}

istream& operator>>(istream& stream,Drobi& n)
{
    cout<<"������� �����: ����� �����, ���������, �����������, ���� (1=+,0=-)"<<endl;
    stream>>n.c>>n.a>>n.b;
    int c1;
    stream>>c1;
    if(c1)
        n.sign=true;
    else
        n.sign=false;
    return stream;
}

int main()
{
    setlocale(LC_ALL,"Russian");

    Drobi d1,d2(1,2,1),d3(1,3,1);
    Drobi t[3]; //����� ������ ������ ������
    cout<<d2<<d3;
    d1=d2+d3;
    cout<<"�����: "<<d1;
    d1=d2-d3;
    cout<<"��������: "<<d1;
    d1=d2*d3;
    cout<<"������������: "<<d1;
    d1=d2/d3;
    cout<<"�������: "<<d1;
    d1=d1+2;
    cout<<"����� +2: "<<d1;
    d1=d1.PutToDegree(-2);
    cout<<"����� � -2 �������: "<<d1;

    return 0;
}
