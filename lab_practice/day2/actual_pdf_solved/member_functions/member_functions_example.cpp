#include <iostream>

using namespace std;

class A
{
	friend void friendly_print(A obj){
		obj.fun(obj.a);
	}
public:
		A() {};
		A(int a) : a(a) {};
		void public_print(){
			this->fun(this->a);
		}
private:
    void fun(int a)
    {
        cout << a << endl;
    }
		int a;
};

int main()
{
  using namespace std;  
	A obj(5);
	cout << "priting with friend function." << endl;
	friendly_print(obj);
	cout << "printing with member function." << endl;
	obj.public_print();
}

