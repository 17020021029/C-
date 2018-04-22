#include <iostream>
#include <iomanip> 
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{
// 在此处补充你的代码
public:
class CArray2D{
	int row,col;//行，列
	int z;
	T* ele;
	public:
	CArray2D(){
		ele=new T[1];
	}
	void cin_(int m,int n)
	{
		row=m;
		col=n;
		z=m*n;
		if(ele)	delete[]ele;
		ele=new T[z+1];
	}
	T* operator[](int i){
		return ele+i*col;
	}
	operator T*(){//memset函数 
		return ele;
	}
};
	CArray2D* a;
	CArray3D(int i,int j,int k){
		a=new CArray2D[i];
		for(int idex=0;idex<i;idex++)
			a[idex].cin_(j,k);	
	}
	CArray2D& operator[](int n){
		return *(a+n); 
	}
// 
};

CArray3D<int> a(3,4,5);
CArray3D<double> b(3,2,2);
void PrintA()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 4; ++j) {
            for(int k = 0; k < 5; ++k) 
                cout << a[i][j][k] << "," ;
            cout << endl;
        }
    }
}
void PrintB()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < 2; ++k) 
                cout << b[i][j][k] << "," ;
            cout << endl;
        }
    }
}

int main()
{

    int No = 0;
    for( int i = 0; i < 3; ++ i ) {
        a[i];
        for( int j = 0; j < 4; ++j ) {
            a[j][i];
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
            a[j][i][i];    
        }
    } //初始化 
    PrintA();
    memset(a[1],-1 ,20*sizeof(int));//赋值操作    
    memset(a[1],-1 ,20*sizeof(int));
    PrintA(); 
    memset(a[1][1],0 ,5*sizeof(int));
    PrintA();

    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 2; ++j )
            for( int k = 0; k < 2; ++k )
                b[i][j][k] = 10.0/(i+j+k+1);
    PrintB();
    int n = a[0][1][2];
    double f = b[0][1][1];
    cout << "****" << endl;
    cout << n << "," << f << endl;

    return 0;
}
