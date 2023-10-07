#include <cmath>
#include <cstdint>
#include <iostream>
typedef struct point{
	float x;
	float y;
}point;
typedef struct circle{
	point p;
	float radius;
}circle;

point get_point_data(void);
circle get_circle_data(void);
float circle_perimeter(circle const *thi);
float circle_area(circle const *thi);
bool is_inside_circle(circle const *thi, point const *p);
int main(void){
	using std::cout;
	using std::endl;
	circle c;	
	point p;
	float perimeter;
	float area;
	cout << "-------GETTING CIRCLE DATA-------" << endl;
	c = get_circle_data();
	cout << "-------GETTING RANDOM POINT DATA-------" << endl;
	p = get_point_data();
	perimeter = circle_perimeter(&c);
	area = circle_area(&c);
	cout << "-------RESULTS-------" << endl;
	cout << "Circle perimeter: " << perimeter << endl;
	cout << "Circle area: " << area << endl;
	if (is_inside_circle(&c, &p))
		cout << "The point you gave is inside the circle" << endl;
	else
		cout << "The point you gave is not inside the circle" << endl;

	return 0;
}
point get_point_data(void){
	using std::cin;
	using std::cout;
	point ret;
	cout << "Enter point X value: ";
	cin >> ret.x;
	cout << "Enter point Y value: ";
	cin >> ret.y;
	return ret;	
}
circle get_circle_data(void){
	using std::cin;
	using std::cout;
	circle ret;
	do{
		cout << "Enter radius value: ";
		cin >> ret.radius;
	}while(ret.radius < 0);
	ret.p = get_point_data();
	return ret;
}
float circle_perimeter(circle const *thi){
	return 2 * M_PI * thi->radius;
}
float circle_area(circle const *thi){
	return M_PI * thi->radius * thi->radius;
}
bool is_inside_circle(circle const *thi, point const *p){
bool ret = false;
float distance = std::sqrt( std::pow(p->x - thi->p.x, 2) +
														std::pow(p->y - thi->p.y, 2) );
if (distance < thi->radius) ret = true;
		
return ret;
}
