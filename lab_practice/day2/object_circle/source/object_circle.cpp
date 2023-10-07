#include <iostream>
#include "./../headers/object_circle.hpp"

Point::Point(){
	//doing using namespace std here is safe because the function is so small
	using namespace std;
	cout << 
	  "Constructor was made for Point without any value assigned" << endl;
}
Point::Point(float const X, float const Y){
	using namespace std;
	this->x = X; //same as x = X, but is more explicit, I like it more like this
	this->y = Y;
 cout <<
   "Constructor was made with values x: " << X << endl << " and y: " << Y << 
	 endl << "assigned to the object" << endl; 	
}
Point::~Point(){
	using namespace std;
	cout << "Object was destroyed" << endl;
}
Circle::Circle(){
	using namespace std;
	cout << 
		"Constructor was made for Circle without any value asssigned" << endl;
}
Circle::Circle(float const rad, Point const P){
	using namespace std;
	this->radious = rad;
	this->p = P;
	cout << 
		"Constructor was made with values radious: " << rad << endl << "P.x: " <<
		P.x << endl << "and P.y: " << P.y << endl;
}
