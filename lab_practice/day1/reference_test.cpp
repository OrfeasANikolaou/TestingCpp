#include <cstdint>
#include <iostream>
int main(void){
	using std::cout;
	using std::endl;
	int64_t a = 10;
	int64_t *b = &a;
	int64_t &c = a;
	cout << "a: " << a << endl;		// 10
	cout << "&a: " << &a << endl;	// adress of a
	cout << "*b: " << *b << endl;	// value of adress pointed by b (a)
	cout << "b: " << b << endl;		// adress of a
	cout << "&b: " << &b << endl;	// adress of b
	cout << "c: " << c << endl;		// 10 (value of c/a (same variable))
	cout << "&c: " << &c << endl;	// adress of c/a (same variable)
	return 0;
}
