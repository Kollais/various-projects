#include <iostream>
#include "student.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");

    Student *st;
    st=new Student[5];
    int n; n=5;
    st[0].SetStudent("����","�����",*(new Date(1,2,1996)));
    st[1].SetStudent("����","�������",*(new Date(15,3,1997)));
    st[2].SetStudent("�������","������",*(new Date(22,11,1994)));
    st[3].SetStudent("�����","�����",*(new Date(13,12,1996)));
    st[4].SetStudent("����","�������",(*new Date(23,2,1995)));
    for(int i=0;i<n;i++)
        cout<<st[i];

    cout<<endl<<"���������� �� �����:"<<endl;

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
        {
            if(st[j].GetLName()>st[j+1].GetLName())
                st[j].Swap(st[j+1]);
        }

    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<st[i];

    cout<<endl<<"���������� �� ���� ��������:"<<endl;

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
        {
            if(!st[j].isOlderD((st[j+1].GetDate())))
                st[j].Swap(st[j+1]);
        }

    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<st[i];

    return 0;
}
