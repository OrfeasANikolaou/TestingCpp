#include <iostream>
	class A{
		public:
			void fun(float const a, float const b) ; 
			void fun(int const a, int const ) ;
			void fun(float const , int const b) ;
		private:
};
int main(void){
	float fv(343.123);
	int iv(34);
	A a;
	//if i call it with a.fun(23, 34) etc it is ambigous
	//therefore when i put a float i have to put 34.4f so it knows it's a float
	//or the variables
	a.fun(iv,iv);
	a.fun(fv, iv);
	a.fun(fv, fv);
	return 0;
}


void A::fun(float const a, float const b){
	using namespace std;
	cout << "Output float a: " << a << endl <<
					"Output float b: " << b << endl;	
}
void A::fun(int const a, int const b){
	using namespace std;
	cout << "Output int a: " << a << endl <<
					"Output int b: " << b << endl;	
}
void A::fun(float const a, int const b){
	using namespace std;
	cout << "Output float a: " << a << endl <<
					"Output int b: " << b << endl;	
}
