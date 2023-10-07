#include <iostream>
#include "./../headers/object_circle.hpp"
int main(void){
	using std::cout;
	using std::endl;
	using std::cin;	
	Circle c;
	Point some_random_point;
	cout << "-------GETTING SOME RANDOM POINT DATA-------" << endl;
	some_random_point.get_point();
	cout << "-------GETTING CIRCLE DATA-------" << endl;
	c.get_circle_data();
	c.print_circle_data();	
	if (is_inside_circle(c, some_random_point))
  	cout << "The point you gave is inside the circle" << endl;
	else
		cout << "The point you gave is not inside the circle" << endl;
	
	return 0;
}
