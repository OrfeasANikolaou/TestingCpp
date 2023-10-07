/* IT IS SAFE TO UNCOMMENT ANY COMMENT EXPCET FOR THIS ONE AND THE ONE ON LINE 6 */
#include <iostream>
#include "./../headers/object_circle.hpp"
#include <cmath>
Point::Point(){
	//doing using namespace std here is safe because the function is so small
	using namespace std;
/*	cout << 
	  "Constructor was made for Point without any value assigned" << endl;
*/
}
Point::Point(float const X, float const Y){
	using namespace std;
	this->x = X; //same as x = X, but is more explicit, I like it more like this
	this->y = Y;
 /*cout <<
   "Constructor was made with values x: " << X << " and y: " << Y
	 << " assigned to the object" << endl; 	
*/
}
Point::~Point(){
	using namespace std;
/*	cout << "Point was destroyed" << endl;
*/
}
void Point::get_point(void){
	using namespace std;
	cout << "Enter coordinate x for point: ";
	cin >> this->x;
	cout << "Enter coordinate y for point: ";
	cin >> this->y;
}
Circle::Circle(){
	using namespace std;
/*	cout << 
		"Constructor was made for Circle without any value asssigned" << endl;
*/
}
Circle::Circle(float const rad, Point const P){
	using namespace std;
	this->radious = rad;
	this->p = P;
/*	cout << 
		"Constructor was made with values radious: " << rad << " P.x: " <<
		P.x << " and P.y: " << P.y << endl;
*/
}
Circle::~Circle(){
/*	using namespace std;
	cout << "Circle was destroyed" << endl; 
*/
}
float Circle::circle_perimeter(void){
	return 2 * M_PI * this->radious; 
}
float Circle::circle_area(void){
	return M_PI * this->radious * this->radious;
}
void Circle::print_circle_data(void){
	using namespace std;
	cout << "Radious: " << this->radious << endl <<
					"Area: " << this->circle_area() << endl <<
					"Perimeter: " << this->circle_perimeter() << endl;
}
void Circle::get_circle_data(void){
	using namespace std;
	do{
		cout << "Enter radious length: ";
		cin >> this->radious;
	}while(this->radious < 0);
	this->p.get_point();
}
bool is_inside_circle(Circle const &c, Point const &p){
	using namespace std;
	float distance = 	sqrt( pow(p.x - c.p.x, 2) +
													pow(p.y - c.p.y, 2) );
	if (distance < c.radious) return true;
	return false;
}

