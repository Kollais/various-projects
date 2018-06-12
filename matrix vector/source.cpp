#include "class.h"
using namespace std;
template <class T>
T Matrix<T>::otbor(){
	T max=X[0][0];
	int i1=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		if(abs(X[i][j])>max)
			max=abs(X[i][j]),i1=i;
	T S=0;
	for(int j=0;j<N;j++)
		S+=X[i1][j];
	return S;
}

template <class T>
Vector<T> preobr (Matrix<T>& A)
{
	T Sr=0;
	
	for(int i=0;i<A.GetN();i++)
		for(int j=0;j<A.GetM();j++)
			Sr+=A[i][j];
	Sr/=A.GetN()*A.GetM();;

	for(int i=0;i<A.GetN();i++)
		for(int j=0;j<A.GetM();j++)
		if (abs(A[i][j])>Sr)
			A[i][j]/=Sr;
  
	Vector<T> temp(A.GetN(),0);
	for(int i=0;i<A.GetN();++i) {
		Sr=1;
		int flag=0;
		for(int j=0;j<A.GetM();++j){
			if(A[i][j]!=0) {
				Sr*=A[i][j];
				flag++;
			}
		}
		if(flag>0)
			temp.SetX(i,Sr);
		else
			temp.SetX(i,0);
	}
	return temp;
}
int main()
{
	setlocale(LC_ALL,"Russian");
	Matrix<double> A(3,4,5.7,9.3);
	Matrix<double> B(5,5,12.1,-3.8);
	Matrix<double> C(6,4,10.5,23.4);
	cout<<"Matrix A:"<<endl<<A<<endl<<endl;
	cout<<"Matrix B:"<<endl<<B<<endl<<endl;
	cout<<"Matrix C:"<<endl<<C<<endl<<endl;
	cout<<"Сумма положительных элементов строки, содержащего максимальный по модулю элемент матрицы для каждой матрицы:"<<endl;
	cout<<"S(A) = "<<A.otbor()<<" S(B) = "<<B.otbor()<<" S(C) = "<<C.otbor()<<endl<<endl;
	cout<<"Проверим условие P>0:"<<endl;
	if(A.otbor()>0) {
		Vector<double> P=preobr(A);
		cout<<"Выполнено для А:"<<" сформируем вектор"<<endl<<P;
		cout<<endl<<"Конечный вид матрицы:"<<endl<<A;
	}
	if(B.otbor()>0) {
		Vector<double> P=preobr(B);
		cout<<"Выполнено для B:"<<" сформируем вектор"<<endl<<P;
		cout<<endl<<"Конечный вид матрицы:"<<endl<<B;
	}
	if(C.otbor()>0) {
		Vector<double> P=preobr(C);
		cout<<"Выполнено для C:"<<" сформируем вектор"<<endl<<P;
		cout<<endl<<"Конечный вид матрицы:"<<endl<<C;
	}
	system("pause");
	return 0;
}