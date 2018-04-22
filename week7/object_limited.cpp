#include <iostream>
#include <vector>
using namespace std;
struct A {
	int v;
	A() { }
	A(int n):v(n) { };
	bool operator<(const A & a) const {
		return v < a.v;
	}
};
// 在此处补充你的代码
template <class T>
class FilterClass{
	public:
		T m_,n_;
		FilterClass(){}		
		FilterClass(T m,T n):m_(m),n_(n){}
		bool operator()(T x){
			return (m_<x&&x<n_);
		}
};
// 
template <class T>
void Print(T s,T e)
{
	for(;s!=e; ++s)
		cout << *s << ",";
	cout << endl;
}
template <class T1, class T2,class T3>
T2 Filter( T1 s,T1 e, T2 s2, T3 op) 
{
	for(;s != e; ++s) {
		if( op(*s)) {
			* s2 = * s;
			++s2;
		}
	}
	return s2;
}

ostream & operator <<(ostream & o,A & a)
{
	o << a.v;
	return o;
}
vector<int> ia;
vector<A> aa; 
int main()
{
	int m,n;
	while(cin >> m >> n) {
		ia.clear();
		aa.clear(); 
		int k,tmp;
		cin >> k;
		for(int i = 0;i < k; ++i) {
			cin >> tmp; 
			ia.push_back(tmp);
			aa.push_back(tmp); 
		}
		vector<int> ib(k);
		vector<A> ab(k);
		vector<int>::iterator p =  Filter(ia.begin(),ia.end(),ib.begin(),FilterClass<int>(m,n));//返回值为ib 
		Print(ib.begin(),p);
		vector<A>::iterator pp = Filter(aa.begin(),aa.end(),ab.begin(),FilterClass<A>(m,n));//返回值为ab 
		Print(ab.begin(),pp);	
	}
	return 0;
}
