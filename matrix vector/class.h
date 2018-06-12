#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

template <class T>
class Vector{
private:
	int N;
	T *X;
public:
	T GetX(int i) {
		return X[i];
	}

	void SetX(int i,T a) {
		X[i]=a;
	}

	void SetN(int n) {
		this->N=n;
	}

	unsigned GetN() {
		return N;
	}

	void Form() {
		cout<<"¬ведите элементы вектора:"<<endl;
		T a;
		for(int i=0;i<GetN();i++) {
			cin>>a;
			SetX(i,a);
		}
	}

	void Random() {
		srand(time(0));
		for(int i=0;i<GetN();i++)
			X[i]=rand()%100;
	}
	Vector<T>() {
		X=new T[0];
	}

	Vector<T>(int n,T a) {
		N=n;
		X=new T[n];
		for(int i=0;i<n;i++) 
			X[i]=a;
	}

	Vector<T>(Vector<T> &A) {
		N=A.N;
		X=new T[N];
		for(int i=0;i<N;i++)
			X[i]=A.X[i];
	}

	~Vector<T>() {
		delete []X;
	}

	Vector<T> operator + (Vector<T> A) {
		if(N>=A.N){
			Vector<T> temp(A);
			for(int i=0;i<A.N;i++) temp.X[i]+=X[i];
			return temp;
		}
		else {
			Vector<T> temp(*this);
			for(int i=0;i<N;i++) temp.X[i]+=A.X[i];
			return temp;
		}
	}

	Vector<T> operator - (Vector<T> A) {
			if(N>=A.N){
			Vector<T> temp(A);
			for(int i=0;i<A.N;i++) temp.X[i]-=X[i];
			return temp;
		}
		else {
			Vector<T> temp(*this);
			for(int i=0;i<N;i++) temp.X[i]-=A.X[i];
			return temp;
		}
	}

	T operator * (Vector<T> A) {
      T a=0;
		if(N>=A.N) for(int i=0;i<A.N;i++) a+=X[i]*A.X[i];
		else for(int i=0;i<N;i++) a+=X[i]*A.X[i];
		return a;
	}

	Vector<T> operator * (T a) {
		Vector<T> temp(this->GetN(),0);
		for(int i=0;i<this->N;i++) temp.X[i]=this->X[i]*a;
		return temp;
	}

	friend Vector<T> operator * (T a,Vector<T> A) {
		Vector<T> temp(A.GetN(),0);
		for(int i=0;i<A.N;i++) temp.X[i]=A.X[i]*a;
		return temp;
	}

	template<class R>

	friend ostream& operator << (ostream& a, Vector<T>& A);

	T* operator [] (int i) {
		return X[i];
	}
	
};



template<class T>
class Matrix{
protected:
	T **X;
	int N,M;
public:
	Matrix<T>(int n,int m) {
		N=n,M=m;
		X=new T*[N];
		for(unsigned i=0;i<N;i++){
			X[i]=new T[M];
			for(int j=0;j<N;j++)
				X[i][j]=0;
		}
	}

	Matrix<T>(int n,int m, float A,float B) {
		X=new T*[n];
		for(int i=0;i<n;i++)
			X[i]=new T[m];
		N=n,M=m;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				X[i][j]=A*j*sin(i/2)+B*i*cos(i/2);
	}

	~Matrix<T>() {
		for(int i=0;i<N;i++) 
			delete []X[i];
		delete []X;
	}


	Matrix<T>(Matrix<T> &A) {
		N=A.N,M=A.M;
		T** temp=new T*[N];
		for(int i=0;i<N;i++)
			temp[i]=new T[M];
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				temp[i][j]=A.X[i][j];
		X=temp;
	}

	void Random() {
		for(int i=0;i<GetN();i++)
			for(int j=0;j<GetM();j++)
				X[i][j]=rand()%100;
	}

	unsigned GetN() {
		return N;
	}

	unsigned GetM() {
		return M;
	}

	T GetX(int i,int j) {
		return X[i][j];
	}

	void SetX(int i,int j,T a) {
		X[i][j]=a;
	}

	void Form() {
		cout<<"¬ведите элементы матрицы\n";
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++) {
				cout<<i<<"."<<j<<" - ";
				cin>>X[i][j];
			}
	}

	void operator = (Matrix<T> &A) {
		N=A.N;
		T** temp=new T*[N];
		for(int i=0;i<N;i++)
			temp[i]=new T[N];
		for(int i=0;i<N;i++)
			for(int j=0;j<N;i++)
				temp[i][j]=A.X[i][j];
		X=temp;
	}

	Matrix<T> operator + (Matrix<T> &M2) {
		Matrix<T> tM(*this);
		T a=0;
		for(int i=0;i<GetN();i++)
			for(int j=0;j<GetM();++j){
				for(int p=0;p<GetM();p++)
					a+=X[i][p]+M2.X[p][i];
				tM.SetX(i,j,a);
				a=0;
			}
		return temp;
	}

	Matrix<T> operator * (Matrix<T> &M2) {
		Matrix<T> tM(*this);
		T a=0;
		for(int i=0;i<GetN();i++)
			for(int j=0;j<GetM();i++){
				for(int p=0;p<GetM();p++)
					a+=X[i][p]*M2.X[p][i];
				tM.SetX(i,j,a);
				a=0;
			}
		return temp;
	}

	template <class R>
	friend  ostream operator <<(ostream& a, Matrix<T>& A);

	T* operator [] (int i) {
		return X[i];
	}

	T otbor();
};

		template <class T>
	ostream& operator <<(ostream& a, Vector<T>& A){
		a<<endl;
		a.setf(ios_base::fixed);// формат чисел
		for(int i=0;i<A.GetN();++i)
			a<<A.GetX(i)<<" ";
		a.unsetf(ios_base::fixed);
		return a;
	}


		template<class T>
	ostream& operator<<(ostream& a, Matrix<T>& A){
		a<<std::endl;
		for(int i=0;i<A.GetN();++i){
			for(int j=0;j<A.GetM();++j)
				a<<setw(8)<<A.GetX(i,j);
		a<<std::endl;
		}
		return a;
	}