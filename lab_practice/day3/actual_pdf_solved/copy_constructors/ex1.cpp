#include <iostream>
/*
 * THIS TOOK WAY LONGER THAN IT SHOULD HAVE
 * IT'S EASY
 */
class A{
	public:
		A(int sz);
		A(A&);
		~A();
		void show_stuff(void);
	private:
		A();
		int sz;
		int *arr;
};

int main(void){
	A a1(10);
	// throws error, I made constructor without parameters private
	// A a2;
	A a2_new(a1);
	a1.show_stuff();
	a2_new.show_stuff();

	return 0;
}

A::A(int sz) : sz(sz), arr(new int[sz]){
	for (size_t i = 0; i < sz; ++i){
		arr[i] = i*i*i;
	}
}

A::A(A &a){
	this->sz = a.sz;
	this->arr = new int[sz];
	for (size_t i = 0; i < this->sz; ++i){
		this->arr[i] = a.arr[i];
	}
}

A::~A(){
	delete [] arr;
}
void A::show_stuff(void){
	for (size_t i = 0; i < this->sz; ++i){
		using namespace std;
		cout << "Data  [" << i << "]: " << this->arr[i] << endl <<
						"Adress[" << i << "]: " << &this[i] << endl;
	}

}
