#include "stdafx.h" 
#include <iostream>  
#include "conio.h"
#include "Windows.h"  
#include <string> 
#include <iomanip> 

using namespace std;

struct Node
{
	string FIO, adress,phone;
	int day, month, year;
	Node *Next,*Prev;
};

template<typename T>
class List 
{
private:

	T *Head,*Tail;
	int count;
public:

     List()
	 {
		 count = 0;
		 Head = NULL; Tail = NULL;
	 }

     ~List()
	 {
		 while(Head) 
         {
			Tail = Head->Next;
			delete Head; 
			Head = Tail; 
		 }
	 }

     void PrintList()
	 {
		 T *tmp = Tail;
		 tmp = Head;
		 cout<<"Список:"<<endl;
		 int i = 1;
		 while (tmp != NULL) 
		 {
			 cout<<i<<" ФИО: "<<tmp->FIO<<" Адрес: "<<tmp->adress<<" Дата рождения: "<<tmp->day<<"."<<tmp->month<<"."<<
				 tmp->year<<" Телефон: "<<tmp->phone<<endl;
			 tmp = tmp->Next; 
			 i++;
		 }
	 }

	 void DeleteNode(int n)
	 {
		 if(n<1 || n>count)
		 {
			 cout<<"Запись с таким номером не существует"<<endl;
			 cin.ignore();
			 return;
		 }
		 int i = 1;
		 T *Del = Head;
		 while(i<n)
		 {
			 Del = Del->Next;
			 i++;
		 }
		 T *PrevDel = Del->Prev;
		 T *NextDel = Del->Next;
		 if(PrevDel != 0 && count != 1)
			 PrevDel->Next = NextDel;
		 if(NextDel !=0 && count != 1)
			 NextDel->Prev = PrevDel;
		 if(n == 1)
			 Head = NextDel;
		 if(n == count)
			 Tail = PrevDel;
		 delete Del; 
		 count--;
	  }

     void AddNode(string FIO, string adress, int day, int month, int year, string phone)
	 {
		 T *tmp = new Node; 
		 tmp->Next = NULL;  
		 tmp->FIO = FIO;
		 tmp->adress = adress;
		 tmp->day = day;
		 tmp->month = month;
		 tmp->year = year;
		 tmp->phone = phone;
		 count++;
 
		 if (Head != NULL) 
		 {
			 tmp->Prev = Tail; 
			 Tail->Next = tmp; 
			 Tail = tmp; 
		 }
		 else 
		 {
			 tmp->Prev = NULL;
			 Head = Tail = tmp;
		 }
	 }

	void SortList()
	{
		T *tmp = Head; 
		while(tmp->Next) 
		{ 
			if( (tmp->FIO) > (tmp->Next->FIO) ) 
			{ 
				string str = tmp->Next->FIO; 
				tmp->Next->FIO = tmp->FIO; 
				tmp->FIO = str; 
				tmp=tmp->Next;
				SortList();
			} 
			else
				tmp = tmp->Next;
		}
	}

	 void SearchNode(string nFIO)
	 {
		 T *tmp = Tail;
		 int i = 0;
		 tmp = Head;
		 //cout<<"Найдено: "<<endl;
		 while (tmp != NULL) 
		 {
			if(tmp->FIO == nFIO)
			{
				cout<<"ФИО:"<<tmp->FIO<<" Адрес: "<<tmp->adress<<" Дата рождения: "<<tmp->day<<"."<<tmp->month<<"."<<tmp->year
				<<" Телефон: "<<tmp->phone<<endl;
				i = 1;
			}
		    tmp = tmp->Next; 
		 }
		 if(i == 0)
			 cout<<"Ничего"<<endl;
	 }

	void SearchOldestMan()
	{
		 T *tmp;
		 int maxy = 3000, maxm = 13, maxd = 32, i = 0, iy = 0, im = 0, id = 0;
		 int nday[20], nmonth[20], nyear[20];
		 string nFIO [20];
		 tmp = Head;
		 cout<<"Старейший(е) жители: "<<endl;
		 while (tmp != NULL ) 
		 {
			if(tmp->year < maxy)
				maxy = tmp->year;
			tmp = tmp->Next; 
		 }
		 
		 tmp = Head; iy = 0;
		 while (tmp != NULL)
		 {
			 if(tmp->year == maxy)
			 {
				 nday[iy] = tmp->day; nmonth[iy] = tmp->month;
				 nyear[iy] = tmp->year; nFIO[iy] = tmp->FIO;
				 iy++;
			 }
			 tmp = tmp->Next;
		 }

		 if(iy == 1)
		 {
			 SearchNode(nFIO[0]);
		 }
		 else
		 {
			 maxm = 13;
			 for(i = 0; i < iy; i++)
			 {
				 if(nmonth[i] < maxm)
					 maxm = nmonth[i];
			 }
			 
			 for(i = 0; i < iy; i++)
			 {
				 if(nmonth[i] == maxm)
				 {
					 nday[im] = nday[i]; nmonth[im] = nmonth[i];
				     nyear[im] = nyear[i]; nFIO[im] = nFIO[i];
					 im++;
				 }
			 }

			 if(im == 1)
			 {
				 SearchNode(nFIO[0]);
			 }
			 else
			 {
				 maxd=32;
				 for(i = 0; i < im; i++)
				 {
					 if(nday[i] < maxd)
						 maxd = nday[i];
				 }
				 
				 for(i = 0; i < im; i++)
				 {
					 if(nday[i] == maxd)
					 {
						 nday[id] = nday[i]; nmonth[id] = nmonth[i];
				         nyear[id] = nyear[i]; nFIO[id] = nFIO[i];
						 id++;
					 }
				 }

				 if(id == 1)
				 {
					 SearchNode(nFIO[0]);
				 }
				 else
				 {
					 for(i=0; i<id; i++)
						SearchNode(nFIO[i]); 
				 }
			 }
		 }
	}

 };

  
int main ()
{
	system("cls");
	setlocale(LC_ALL, "Russian");
	int b;
	List<Node> lst; 
	lst.AddNode("Лебедев Артем Николаевич", "г.Донецк, ул.Тихая, д.7", 10, 5, 1965, "050 541 34 98"); 
	lst.AddNode("Иванова Анна Петровна", "г.Киев, ул.Гарибальди, д.5-А, кв.54", 9, 5, 1995, "099 324 61 98"); 
	lst.AddNode("Симонов Никодим Игоревич", "г.Москва, ул.Нижняя, д.84, кв.3", 17, 2, 1938, "099 324 61 98"); 
	lst.AddNode("Симонов Николай Игоревич", "г.Москва, ул.Нижняя, д.84, кв.3", 17, 2, 1938, "099 324 61 98"); 
	do
	{
		system("cls");
		lst.PrintList(); cout<<endl;
		cout<<"Введите номер операции:"<<endl;
		cout<<"  1.Добавить запись\n  2.Удалить запись\n  3.Найти запись\n  4.Сортировать список по алфавиту\n"<<
			"  5.Найти старейшего жителя\n  6.Выйти\n"<<endl;
		cin>>b;

		if(b==1)
		{
			string nFIO, nadress, nphone;
			int nday, nmonth, nyear;
			cout<<"Введите ФИО: "<<endl;
			SetConsoleCP(1251);
			cin.ignore();
			getline(cin,nFIO);
			SetConsoleCP(866);
			cout<<"Введите адрес: "<<endl;
			SetConsoleCP(1251);
			cin.ignore();
			getline(cin, nadress);
			SetConsoleCP(866);
			cout<<"Введите телефон: "<<endl;
			SetConsoleCP(1251);
			cin.ignore();
			getline(cin, nphone);
			SetConsoleCP(866);
			cout<<"Введите дату рождения в формате ДД ММ ГГГГ: "<<endl;
			SetConsoleCP(1251);
			int er1,er2,er3;
			SetConsoleCP(866);
			do
			{
				er1=0; er2=0; er3=0;
				cin>>nday;
				if (nday<0 || nday>32)
					er3=1;
			    cin>>nmonth;
				if (nmonth<0 || nmonth>13)
					er2=1;
				cin>>nyear;
				if (nyear<1900 || nyear>2015)
					er1=1;

				if(er1==1) cout<<"Неверный год\n";
				if(er2==1) cout<<"Неверный месяц\n";
				if(er3==1) cout<<"Неверный день\n";
			}
			while (er1==1 || er2==1 || er3==1);
			SetConsoleCP(1251);
			SetConsoleCP(866);
			lst.AddNode(nFIO, nadress, nday, nmonth, nyear, nphone);
		}

		if(b==2)
		{
			int del1;
			cout<<"Введите номер удаляемой записи:"<<endl;
			cin>>del1;
			lst.DeleteNode(del1);
		}

		if(b==3)
		{
			string search1;
			cout<<"ФИО: "<<endl;
			SetConsoleCP(1251);
			cin.ignore();
			getline(cin, search1);
			SetConsoleCP(866);
			lst.SearchNode(search1);
			system("pause");
		}

		if (b==4)
		{
			lst.SortList();
		}

		if (b==5)
		{
			lst.SearchOldestMan();
			system("pause");
		}
	}
	while(b!=6);
	system("pause");
}