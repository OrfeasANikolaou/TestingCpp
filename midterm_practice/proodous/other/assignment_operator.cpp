#include <iostream>

class p{
	public:
		int x, y;
		p& operator=(p const& other) { this->x = other.x; this->y = other.y; return *this; }
};


int main(void){

	p a = {3,4};
	p b;
	b = a;
	std::cout << a.x << a.y << std::endl <<
							 b.x << b.y << std::endl;	

}
