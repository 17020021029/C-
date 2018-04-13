    #include <iostream>
    #include <string>
    using namespace std;
    template <class T>
    T SumArray(T* a, T* b){
        T res=*a;   //给返回值赋初值
        int gap=b-a;
        for(int i=1;i<gap;i++)//赋初值，所以从1开始
        {
                res+=*(a+i);
        }
     return res;
    }
    int main() {
        string array[4] = { "Tom","Jack","Mary","John"};
        cout << SumArray(array,array+4) << endl;
        int a[4] = { 1, 2, 3, 4};  //提示：1+2+3+4 = 10
        cout << SumArray(a,a+4) << endl;
        return 0;
    }
