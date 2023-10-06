#include <cmath>
#include <cstdint>
#include <iostream>
#include <ostream>
typedef struct circle{
	float center_x; 
	float center_y;
	float radius;
}circle;

float circle_perimeter(circle const thi);
float circle_area(circle const thi);
bool is_inside_circle(circle const thi, float x, float y);
int main(void){
	circle c = { 5,
							 3,
							 10, };
	std::cout << circle_perimeter(c) << std::endl;
	std::cout << circle_area(c) << std::endl;
	if (is_inside_circle(c, 100, 50))
		std::cout << "is" << std::endl;
	else
		std::cout << "isnt" << std::endl;

	return 0;
}
float circle_perimeter(circle const thi){
	return 2 * M_PI * thi.radius;
}
float circle_area(circle const thi){
	return M_PI * thi.radius * thi.radius;
}
bool is_inside_circle(circle const thi, float x, float y){
bool ret = false;
float distance = std::sqrt( std::pow(x - thi.center_x, 2) +
														std::pow(y - thi.center_y, 2) );
if (distance < thi.radius) ret = true;
		
return ret;
}
