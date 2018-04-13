    #include <iostream>
    #include <string>

    using namespace std;
    template <class T>
    class CMyistream_iterator
    {

// 在此处补充你的代码
    public:
        istream& is;
        T t;
        CMyistream_iterator(istream& n):is(n){
           cin>>t;
        }
        void operator++(int){
                cin>>t;
        }
        T operator*(){
                return t;}
//
    };
    int main()
    {
        int t;
        cin >> t;
        while( t -- ) {
                 CMyistream_iterator<int> inputInt(cin);//参数为cin，需要一个构造函数初始化，且要输入数据
                 int n1,n2,n3;
                 n1 = * inputInt; //读入 n1
                 int tmp = * inputInt;//需要重载*
                 cout << tmp << endl;
                 inputInt ++;   //++时也要输入一个数,需要重载
                 n2 = * inputInt; //读入 n2
                 inputInt ++;
                 n3 = * inputInt; //读入 n3
                 cout << n1 << " " << n2<< " " << n3 << " ";
                 CMyistream_iterator<string> inputStr(cin);
                 string s1,s2;
                 s1 = * inputStr;
                 inputStr ++;
                 s2 = * inputStr;
                 cout << s1 << " " << s2 << endl;
        }
         return 0;
    }
