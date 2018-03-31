    #include <cstdlib>

    #include <iostream>

    using namespace std;
    
    class MyString
    {
// 在此处补充你的代码  

    private:

        char* p;

        int len;

    public:

        MyString(){//无参构造函数 

        	len=0;

        	p=new char[1];

        	p[0]='\0';

		}

        MyString(const char* ptr)//构造函数  

        {

            len=strlen(ptr);

            p=new char[len+1];

            p[len]='\0'; 

            strcpy(p,ptr);

        }

        MyString(const MyString & a)//复制构造函数

        {

            len=strlen(a.p);

            p=new char[len+1];

            p[len]='\0';

            strcpy(p,a.p);

        }

        char & operator[](int n)//重载[]

        {

            return *(p+n);          

        }

        friend ostream& operator<<(ostream& os,const MyString & c)//重载<<

        {

        	cout<<c.p;

            return os;

        }

        MyString& operator=(const MyString & d)//重载=

        {

        	if(this==&d)	return *this;

        	len=strlen(d.p);

        	if(p)	delete[]p;

        	p=new char[len+1];

        	p[len]='\0';

        	strcpy(p,d.p);

        	return *this;

        }

        

        MyString & operator=(const char * str)//重载= 

        {

        	len=strlen(str);

			if(p)	delete[]p;

			p=new char [len+1];

			p[len]='\0';

			strcpy(p,str);

			return *this;

		}

        friend MyString operator+(const MyString& x,const MyString & y)//重载+

        {

        	char* tmp=new char[strlen(x.p)+strlen(y.p)+1];

        	strcpy(tmp,x.p);

        	strcat(tmp,y.p);

        	MyString temp(tmp);

        	delete tmp;

            return temp; 

        }

    	MyString & operator+=(const MyString& rhs)//重载+=

    	{

    		MyString temp(*this);

    		return *this=temp+rhs;

    	}

        friend bool operator<(const MyString &x,const MyString & y){

			return strcmp(x.p,y.p)<0;

		}

		friend bool operator==(const MyString &x,const MyString & y){

			return strcmp(x.p,y.p)==0; 

		}

		friend bool operator>(const MyString &x,const MyString & y){

			return strcmp(x.p,y.p)>0;

		}

        MyString operator()(int n,int m)

        {

			char* tmp=new char[m+1];

			tmp[m]='\0';

			int k=0;

			for(int i=n;i<n+m;i++)

				tmp[k++]=p[i];

			MyString res(tmp);

			delete []tmp;

			return res;

        }

         ~MyString()//析构函数一定要写 

		 {

		 	if(NULL)

		 	delete []p;

		  } 

	friend int strlen(const char * s)

    {    int i = 0;

        for(; s[i]; ++i);

        return i;

    }

    friend void strcpy(char * d,const char * s)

    {

        int i = 0;

        for( i = 0; s[i]; ++i)

            d[i] = s[i];

        d[i] = 0;

          

    }

    friend int strcmp(const char * s1,const char * s2)

    {

        for(int i = 0; s1[i] && s2[i] ; ++i) {

            if( s1[i] < s2[i] )

                return -1;

            else if( s1[i] > s2[i])

                return 1;

        }

        return 0;

    }//比较

    friend void strcat(char * d,const char * s)

    {

        int len = strlen(d);

        strcpy(d+len,s);

    }//加上字符串s



    };







    int main()

    {

        MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);//构造函数，复制构造函数，缺省值

        MyString SArray[4] = {"big","me","about","take"};//重载[]

        cout << "1. " << s1 << s2 << s3<< s4<< endl;//重载<<

        s4 = s3;//重载=

        s3 = s1 + s3;//重载+

        cout << "2. " << s1 << endl;

        cout << "3. " << s2 << endl;

        cout << "4. " << s3 << endl;

        cout << "5. " << s4 << endl;

        cout << "6. " << s1[2] << endl;

        s2 = s1;

        s1 = "ijkl-";//重载=

        s1[2] = 'A' ;

        cout << "7. " << s2 << endl;

        cout << "8. " << s1 << endl;

        s1 += "mnop";

        cout << "9. " << s1 << endl;

        s4 = "qrst-" + s2;//重载+

        cout << "10. " << s4 << endl;

        s1 = s2 + s4 + " uvw " + "xyz";//重载+

        cout << "11. " << s1 << endl;

        qsort(SArray,4,sizeof(MyString),CompareString); //对对象排序，需要自己写一个CompareString函数

        for( int i = 0;i < 4;i ++ )

        cout << SArray[i] << endl;

        //s1的从下标0开始长度为4的子串

        cout << s1(0,4) << endl;    //重载()

        //s1的从下标5开始长度为10的子串

        cout << s1(5,10) << endl;

        return 0;

    }
