#include <iostream>
#include <vector>

typedef struct Point{
	Point(int a, int b) : x(a), y(b) {}
	int x;
	int y;
}Point;

bool operator==(Point a, Point b);

template <typename T>
size_t count(std::vector<T> const&, T const&);

int main(void){
	std::vector<int> int_vec = {3,1,6,7,3,6,2,3,3,0,1};
	std::vector<double> f_vec = {3.0, 3.0, 0.01, 3.001, 3.00, 1.2341, 4.1, 3.000};
	std::vector<Point> P_vec = { Point(3,3),
	 														 Point(3,3),
														 	 Point(0,1),
															 Point(1,3),
															 Point(3,1),
															 Point(3,3),
															 Point(3,2),
															 Point(0,0), };
	std::cout << "Times 3 appeared in int_vec: " << count(int_vec, 3) << std::endl;
	std::cout << "Times 3.0 appeared in f_vec: " << count(f_vec, 3.0) << std::endl;		
	std::cout << "Times there is a point with x=y=3: " << count(P_vec, Point(3,3)) << std::endl;

	return 0;
}

bool operator==(Point a, Point b){
	return a.x == b.x && a.y == b.y;
}

template <typename T>
size_t count(std::vector<T> const& v, T const& x){
	size_t c = 0;
	for (size_t i = 0; i < v.size(); ++i){
		if (v[i] == x) ++c;
	}
	return c;
}
