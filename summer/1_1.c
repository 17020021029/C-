//运行不对
#include<iostream>
using namespace std;
class Student
{
     private:
        char name[20],id[20];
        int age;
        int r1,r2,r3,r4,av;
        char t;
     public:
        void init();
        void print();
};
void Student::init()
{
        cin.get(name,20);
        cin>>t>>age>>t;
        cin.get(id,20);
        cin>>t>>r1>>t>>r2>>t>>r3>>t>>r4;
}
void Student::print()
{
        cout<<name<<","<<age<<","<<id<<",";
        av=(r1+r2+r3+r4)/4;
        cout<<av<<endl;
}
int main()
{
    Student c;
    c.init();
    c.print();
return 0;
}
