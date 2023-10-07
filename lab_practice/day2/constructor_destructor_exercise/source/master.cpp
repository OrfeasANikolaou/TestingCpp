#include "./../headers/constructor_destructor.hpp"
#include <iostream>
int main(void){
	using std::cout;
	using std::endl;
	A prokathorismeno;
	//A test_pente[] = {A(4), };
	//A x(4);
	A pente[] = {A(), A(4, 4), A(5, 1), A(100, 100), A(9, 6), };
	cout << "default: " << prokathorismeno << endl;
	for (size_t i = 0; i < 5; ++i)
		cout << "pente[" << i << "] = " << pente[i] << endl;
		// cout << object of class A;
		// from &operator<< if it gets a stream and a class A (pente[i]) 
		// it gets overloaded and executes cout << pente[i].x << " " ...
	return 0;
}
