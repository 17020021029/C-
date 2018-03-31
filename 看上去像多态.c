    #include <iostream>
    using namespace std;
    class B { 
    	private: 
    		int nBVal; 
    	public: 
    		void Print() 
    		{ cout << "nBVal="<< nBVal << endl; } 
    		void Fun() 
    		{cout << "B::Fun" << endl; } 
    		B ( int n ) { nBVal = n;} 
    };

// 在此处补充你的代码
	class D:public B
	{
		int nDVal; 
		public: 
		D(int n):B(n*3) 
		{
			nDVal=n;
		}
		void Fun()
		{
			cout<<"D::Fun"<<endl;
		}
		void Print()
		{
			B::Print();
			cout<<"nDVal"<<"="<<nDVal<<endl;
		}
	 }; 
// 
    int main() { 
    	B * pb; D * pd; 
    	D d(4); 
		d.Fun(); //D::Fun
    	pb = new B(2); 
		pd = new D(8); 
    	pb -> Fun(); //输出B::Fun 
		pd->Fun(); //输出D::Fun 
    	pb->Print ();//输出nBVal=2 
		 pd->Print (); //输出nBVal=24;nDVal=8; 
    	pb = & d; 
		pb->Fun(); //输出B::Fun 
    	pb->Print(); //输出nBVal=12 
    	return 0;
    }
