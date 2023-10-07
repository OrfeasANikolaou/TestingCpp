#include "./../headers/constructor_destructor.hpp"
#include <cstdint>
#include <iostream>
ostream &operator<<(ostream &os, const A &obj){
	os << obj.x << " " << obj.y;
	return os;
}
A::A() : x(0), y(0){
/*	using namespace std;
	this->x = 0;
	this->y = 0;
	cout << "Constructor for A without assigned values." << endl;
*/
}
A::A(int64_t X, int64_t Y = 19) : x(X), y(Y) {}
/*{
	using namespace std;
	this->x = X;
	this->y = Y;
	cout << "Constructor A made with values: " << endl << 
					"x: " << this->x << endl <<
					"y: " << this->y << endl;
}
*/
A::~A(){
	using namespace std;
	cout << "Object A destroyed." << endl;
/*THIS ONE IS WRONG BECAUSE IT SAYS 8, BUT OBJECT HAS TWO 64BIT INTS 
	cout << "Size test: " << sizeof this << endl;
	THE NEXT ONE IS CORRECT, BECAUSE 16 * 8 = 128
*/	
	cout << "Size: " << sizeof(*this) << endl;
	cout << "Adress: " << this << endl;
}
