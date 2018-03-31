#include<iostream>
#include<iomanip>
using namespace std;
static int life,dragon_life,ninja_life,iceman_life,lion_life,wolf_life;        //生命元及各个怪物的生命值
static int Min;                                                           //生命最少的怪物。 
#define min_(a,b)(a<b? a:b) 
class red{
	public:
	int m,n=0,dragon_n=0,ninja_n=0,iceman_n=0,lion_n=0,wolf_n=0;        //n为怪物总数以及不同怪物的数目 
	int num=0;                                                           //num为循环标记 
	red(int x):m(x){}//初始化
	int judge(){                                                               //这是一个判定函数，来确定当前需要制造哪一个怪物 
	    if(m<Min)
	    {
	    	cout<<"red headquarter stops making warriors"<<endl;
	    	return 1;
		}
		if(num%5==0&&m>=iceman_life){
	    	bulid(0);
	    	return 0;
		}
		else if (num%5==1&&m>=lion_life){
	    	bulid(1);
	    	return 0;
		}
		else if (num%5==2&&m>=wolf_life){
	    	bulid(2);
	  		return 0;
		}
	    else if (num%5==3&&m>=ninja_life){
	    	bulid(3);
		  	return 0;
		}
		else if (num%5==4&&m>=dragon_life){
	    	bulid(4);
	      	return 0;
		}
		else{
			num++;
			judge();
		}
	} 
	int bulid(int x){                                                         //这是一个生成函数，来制造一个怪物 
	    n++;
	    num++;
	    if(x==0){
	    	m=m-iceman_life;
			iceman_n++;
            cout<<"red iceman "<<n<<" born with strength "<<iceman_life<<","<<iceman_n<<" iceman in red headquarter"<<endl;
		}
		if(x==1){
			m=m-lion_life; 
		    lion_n++;
            cout<<"red lion "<<n<<" born with strength "<<lion_life<<","<<lion_n<<" lion in red headquarter"<<endl;
		}
		if(x==2){
			m=m-wolf_life;
		    wolf_n++;
		    cout<<"red wolf "<<n<<" born with strength "<<wolf_life<<","<<wolf_n<<" wolf in red headquarter"<<endl;
		}
		if(x==3){
			m=m-ninja_life;
			ninja_n++;
		    cout<<"red ninja "<<n<<" born with strength "<<ninja_life<<","<<ninja_n<<" ninja in red headquarter"<<endl;
		}
		if(x==4){
			m=m-dragon_life;  dragon_n++;
			cout<<"red dragon "<<n<<" born with strength "<<dragon_life<<","<<dragon_n<<" dragon in red headquarter"<<endl;
		}
	}
};
class blue{	
 	public:
	int m,n=0,dragon_n=0,ninja_n=0,iceman_n=0,lion_n=0,wolf_n=0;        //n为怪物总数以及不同怪物的数目 
	int num=0;                                                           //num为循环标记 
	blue(int x):m(x){}//初始化
	int judge(){                                                               //这是一个判定函数，来确定当前需要制造哪一个怪物 
	    if(m<Min)
	    {
	    	cout<<"blue headquarter stops making warriors"<<endl;
	    	return 1;
		}	
		if (num%5==0&&m>=lion_life){
	    	bulid(0);
	    	return 0;
		}
		else if (num%5==1&&m>=dragon_life){
	    	bulid(1);
	      	return 0;
		}
		else if (num%5==2&&m>=ninja_life){
	    	bulid(2);
		  	return 0;
		}
		else if(num%5==3&&m>=iceman_life){
	    	bulid(3);
	    	return 0;
		}
		else if (num%5==4&&m>=wolf_life){
	    	bulid(4);
	  		return 0;
		}
		else{
			num++;
			judge();
		}
	} 
	int bulid(int x){                                                         //这是一个生成函数，来制造一个怪物 
	    num++;
		n++;
		if(x==0){
			m=m-lion_life; 
		    lion_n++;
            cout<<"blue lion "<<n<<" born with strength "<<lion_life<<","<<lion_n<<" lion in blue headquarter"<<endl;
		}
		if(x==1){
			m=m-dragon_life;  dragon_n++;
			cout<<"blue dragon "<<n<<" born with strength "<<dragon_life<<","<<dragon_n<<" dragon in blue headquarter"<<endl;
		}
	    if(x==2){
			m=m-ninja_life;
			ninja_n++;
		    cout<<"blue ninja "<<n<<" born with strength "<<ninja_life<<","<<ninja_n<<" ninja in blue headquarter"<<endl;
		}
	    if(x==3){
	    	m=m-iceman_life;
			iceman_n++;
            cout<<"blue iceman "<<n<<" born with strength "<<iceman_life<<","<<iceman_n<<" iceman in blue headquarter"<<endl;
		}
	
		if(x==4){
			m=m-wolf_life;
		    wolf_n++;
		    cout<<"blue wolf "<<n<<" born with strength "<<wolf_life<<","<<wolf_n<<" wolf in blue headquarter"<<endl;
		}
	}
};
/*class monster{                                                         //怪物类 
	public:
	char number;
	int life,attrack;
};*/
/*
class dragon{                                            //不同怪物，派生类 
	dragon(){cout<<"dragon";}
};
class ninja{
	ninja(){cout<<"ninja";}
};
class iceman{
	iceman(){cout<<"iceman"}
};
class lion{
	lion(){cout<<"lion"}
};
class wolf{
	wolf(){cout<<"wolf";}
};*/
int main(){
	int m,m_=1;                                  //m代表一共循环的次数，m_代表循环到了第几次 
	cin>>m;                                      //输入一共循环的次数 
	while(m){
		int time=0;
		cin>>life>>dragon_life>>ninja_life>>iceman_life>>lion_life>>wolf_life;
		red red_(life);                          //初始化红蓝堡垒 
		blue blue_(life);
		bool red_bulid=1,blue_bulid=1;            //标志，记录红蓝堡垒是否还在生产 
		Min=min_(min_(dragon_life,ninja_life),min_(iceman_life,min(lion_life,wolf_life)));
		cout<<"Case:"<<m_<<endl;                  //第几次循环 
		m_++;m--;                                //循环次数++ 
		while(1){
			if(red_bulid){ 
			    cout<<setw(3)<<setfill('0')<<time<<" ";
			    red_bulid=1-red_.judge();
			}
			if(blue_bulid){
				cout<<setw(3)<<setfill('0')<<time<<" ";
				blue_bulid=1-blue_.judge();
			}
			if(red_bulid+blue_bulid==0)
			    break;
			time++;
		}
	}
	return 0;
}
