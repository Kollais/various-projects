#include "student.h"

Date::Date(int nday,int nmonth, int nyear)
{
    if(Validate(nday,nmonth,nyear))
    {
        day=nday; month=nmonth; year=nyear;
    }
    else
    {
        cout<<"Невозможная дата"<<endl;
        day=0; month=0; year=0;
    }
}

bool Date::Validate(int day, int month, int year)
{
    if(day<0 || month<0 || year<0)
        return false;
    if(month==2 && isLeap(year) && day>29)
        return false;
    if(month==2 && day>28)
        return false;
    if(month%2==0 && day>30)
        return false;
    if(day>31)
        return false;
    return true;
}

bool Date::isOlder(Date& d)
{
    if(year<d.year)
        return true;
    if(year>d.year)
        return false;
    if(year==d.year)
    {
        if(month<d.month)
            return true;
        if(month>d.month)
            return false;
        if(month==d.month)
        {
            if(day<=d.day)
                return true;
            else return false;
        }
    }
}

ostream& operator<<(ostream& stream,Student& n)
{
    stream<<n.lastname<<" "<<n.name<<" "<<setw(2)<<setfill('0')<<n.date.getDay()<<"."
    <<setw(2)<<n.date.getMonth()<<"."<<n.date.getYear()<<endl;
    return stream;
}
istream& operator>>(istream& stream,Student& n)
{
    cout<<"Введите данные о студенте: фамилия, имя, дата рождения (дд мм гггг)"<<endl;
    int dd,mm,yy;
    stream>>n.lastname>>n.name;
    stream>>dd>>mm>>yy;
    if(n.date.Validate(dd,mm,yy))
        n.date.SetDate(dd,mm,yy);
    else cout<<"Невозможная дата"<<endl;
    return stream;
}

void Student::Swap(Student &st)
{
    Student st1;
    st1.SetName(st.GetName());
    st1.SetLName(st.GetLName());
    st1.SetDate(st.GetDate()->getDay(),st.GetDate()->getMonth(),st.GetDate()->getYear());
    st.SetName(name);
    st.SetLName(lastname);
    st.SetDate(date.getDay(),date.getMonth(),date.getYear());
    name=st1.GetName();
    lastname=st1.GetLName();
    date.SetDate(st1.GetDate()->getDay(),st1.GetDate()->getMonth(),st1.GetDate()->getYear());
}
