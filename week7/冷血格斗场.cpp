#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	typedef map<int,int> MAP;
	MAP facer;
	facer.insert(make_pair(1000000000,1));//将power作为关键字排序 
	int num;
	cin>>num;
	int id,power;
	MAP::iterator it;
	 while(num--)
	 {
	 	cin>>id>>power;
	 	it=facer.lower_bound(power);
	 	if(it==facer.end())
		 it--;
	 	int min=it->second;
	 	int power_=abs(it->first-power);
	 	if(it!=facer.begin())
	 	{
	 		it--;
	 		if(abs(it->first-power)<power_||(power_==abs(it->first-power))&&it->second<min)
	 		min=it->second;
		 }
		 cout<<id<<" "<<min<<endl;
		 it=facer.find(power);
		 if(it==facer.end()||it->second>id)
		 facer[power]=id;//在map中加入刚写进的会员 
	 }
	 return 0;
 }
