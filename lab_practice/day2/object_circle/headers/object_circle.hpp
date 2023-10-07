class Point{
	public:
		Point();
		Point(float const X, float const Y);
		~Point();
		float x;
		float y;	
};
class Circle{
	friend Point;
	friend bool is_inside_circle(Circle const c, Point const p);
	public:
		Circle();
		Circle(float const rad, Point const P);
		~Circle();
		float circle_perimeter(Circle const cir);
		float circle_area(Circle const cir);
	private:
		float radious;
		Point p;
};
