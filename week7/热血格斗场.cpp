#include<iostream>
#include<map>
using namespace std;
int main()
{
	typedef map<int,int> MAP;
	MAP facer;
	facer.insert(make_pair(1000000000,1));//将power作为关键字排序 
	int num;
	cin>>num;
	int id,power;
	MAP::iterator it,it1;
	 while(num--)
	 {
	 	cin>>id>>power;
	 	it=facer.lower_bound(power);
	 	if(it!=facer.begin())
	 	{
	 		it1=it;//不能改变it，因为else还要输出it->second ,且要比较前后两个 
	 		it1--;
	 		if(power-it1->first<=it->first-power)
	 			cout<<id<<" "<<it1->second<<endl;
	 		else 
	 			cout<<id<<" "<<it->second<<endl;
		 }
		 else {
		 	cout<<id<<" "<<it->second<<endl;
		 }
		 facer[power]=id;
	 }
	 return 0;
 } 
