

class Student
{
private:
    string name, lastname;
    Date date;
public:
    Student() {}
    Student(string nn, string nln, Date& nd) {name=nn; lastname=nln; date=nd;}
    Student(Student &st) {*this=st;}
    friend ostream& operator<<(ostream& ,Student&);
    friend istream& operator>>(istream& ,Student&);
    void SetStudent(string nn, string nln, Date& nd) {name=nn; lastname=nln; date=nd;}
    string GetName() {return name;}
    string GetLName() {return lastname;}
    Date* GetDate() {return &date;}
    void SetName(string n) {name=n;}
    void SetLName(string ln) {lastname=ln;}
    void SetDate(int dd, int mm, int yy) {date.SetDate(dd,mm,yy);}
    bool isOlderD(Date *d) {if(date.isOlder(*d)) return true; else return false;}
    void Swap(Student&);
};



