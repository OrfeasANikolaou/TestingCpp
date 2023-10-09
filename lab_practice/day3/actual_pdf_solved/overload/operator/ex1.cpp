#include <iostream>
#include <ostream>
class A{
	friend bool operator<(A, A);
	friend std::ostream &operator<<(std::ostream &, A &);
	public:
		A();
		A(int a, int b = 0, int c = 0);
	private:
		int a, b, c;
};


int main(void){
	using namespace std;
	A one(123), two(23,23), three(23,1,124);
	if (one < two) cout << one << endl;
	else if (two < three) cout << two << endl;
	else cout << three << endl;
	cout << "ONE" << endl;
	cout << one << endl; 
	cout << "TWO" << endl;
	cout << two << endl;
	cout << "THREE" << endl;	
	cout << three << endl;
	return 0;
}

A::A() : a(0), b(0), c(0) {}
A::A(int a, int b, int c) : a(a), b(b), c(c) {}

bool operator<(A x, A y){
	int x_sum;
	int y_sum;
	bool ret;
	x_sum = x.a + x.b + x.c;
	y_sum = y.a + y.b + y.c;
	if (x_sum < y_sum) ret = true;
	else ret = false;
	return ret;
}

std::ostream &operator<<(std::ostream &os, A &x){
	using std::cout;
	using std::endl;
	cout << "a: " << x.a << endl <<
					"b: " << x.b << endl <<
					"c: " << x.c << endl <<
					"Total sum: " << x.a + x.b + x.c; 
	return os;
}
