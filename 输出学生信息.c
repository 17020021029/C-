    #include <iostream>
    #include <string>
    using namespace std;
class Student
{
    string name;
    int id;
public:
        Student(){}
        Student(const string str,int n)
        {
                name=str;
                id=n;
        }
        void Read()
        {
            cin>>name;
            cin>>id;
        }
        void Print()
        {
                cout<<id<<"  ";
             cout<<name<<endl;
        }
        ~Student(){}

};
    int main()
    {
        int t;
        cin >> t;
        Student s("Tom",12);
        while( t-- )    {
                int n;
                cin >> n;
                Student st;
                for( int i = 0;i < n; ++i) {
                        st.Read();
                        st.Print();
                }
                cout << "****" << endl;
        }
        return 0;
    }
