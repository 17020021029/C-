#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	multiset<int> mst;
	set<int> it;//写到后边补充的，用来判断是否能找到当前的num,set没有重复对象 
	multiset<int>::iterator i; 
	int n;
	string str;
	int num;
	cin>>n;
	while(n--)
	{
		cin>>str>>num;
		if(str=="add"){
			mst.insert(num);
			it.insert(num);//补充 
			cout<<mst.count(num)<<endl;
		}
		else if(str=="del"){
			cout<<mst.count(num)<<endl;
			mst.erase(num);
		}
		else if(str=="ask"){
			if(it.find(num)==it.end()) 
			{
				cout<<"0 0"<<endl;
			}
			else {
				cout<<"1"<<" ";
				cout<<mst.count(num)<<endl;
			}
		}
	}
	return 0;
 } 
