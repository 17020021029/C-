    #include <iostream>
    #include <string>
    #include <cstring>
    using namespace std;
    template <class T>
    class myclass {
// 在此处补充你的代码
        public:
           int size;
           T *p;
           myclass(T line[100],int n){
                p=new T[n];
                size=n;
                for(int i=0;i<n;i++){
                        p[i]=line[i];}
                }
//
    ~myclass( ) {
                delete [] p;
        }
        void Show()//输出函数
        {
                for( int i = 0;i < size;i ++ ) {
                        cout << p[i] << ",";
                }
                cout << endl;
        }
    };
    int a[100];
    int main() {
        char line[100];
        while( cin >> line ) {
                myclass<char> obj(line,strlen(line));;
                obj.Show();
                int n;
                cin >> n;
                for(int i = 0;i < n; ++i)
                        cin >> a[i];
                myclass<int> obj2(a,n);
                obj2.Show();
        }
        return 0;
    }
