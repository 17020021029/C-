# Filter
## Description
编写Filter模板，使得程序产生指定输出 不得编写 Filter函数

#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
bool LargerThan2(int n)
{
    return n > 2;
}
bool LongerThan3(string s) 
{
    return s.length() > 3;
}

string as1[5] = {"Tom","Mike","Jack","Ted","Lucy"};
string as2[5];
int  a1[5] = { 1,2,3,4,5};
int a2[5];
int main() {
    string * p = Filter(as1,as1+5,as2,LongerThan3);
    for(int i = 0;i < p - as2; ++i)
        cout << as2[i];
    cout << endl; 
    int * p2 = Filter(a1,a1+5,a2,LargerThan2);
    for(int i = 0;i < p2-a2; ++i)
        cout << a2[i] << ",";
    return 0;
}

Input

无

Output

MikeJackLucy
3,4,5,

Sample Input 1

None

Sample Output 1

MikeJackLucy
3,4,5,
## 代码实现
```C++
    #include <iostream>
    #include <string>
    using namespace std;

// 在此处补充你的代码
template <class T1,class T2>
T1* Filter(T1* s,T1* e,T1* t,T2 fun)
{
   int p=-1;
   int gap=e-s;
   for(int i=0;i<gap;i++)
   {
        if(fun(*(s+i))){
           p++;
           *(t+p)=*(s+i);
        }
   }
return (t+p+1);//返回值还是不太清楚
}
//
    bool LargerThan2(int n)
    {
        return n > 2;
    }
    bool LongerThan3(string s)
    {
        return s.length() > 3;
    }

    string as1[5] = {"Tom","Mike","Jack","Ted","Lucy"};
    string as2[5];
    int  a1[5] = { 1,2,3,4,5};
    int a2[5];

    int main() {
        string * p = Filter(as1,as1+5,as2,LongerThan3);
        for(int i = 0;i < p - as2; ++i)
                cout << as2[i];
        cout << endl;
        int * p2 = Filter(a1,a1+5,a2,LargerThan2);
        for(int i = 0;i < p2-a2; ++i)
                cout << a2[i] << ",";
        return 0;
    }
```
