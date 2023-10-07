class Point{
	friend class Circle;
	public:
		Point();
		Point(float const X, float const Y);
		~Point();
		void get_point(void);
		float x;
		float y;	
};
class Circle{
	friend bool is_inside_circle(Circle const &c, Point const &p);
	public:
		Circle();
		Circle(float const rad, Point const P);
		~Circle();
		float circle_perimeter(void);
		float circle_area(void);
		void print_circle_data(void);
		void get_circle_data(void);
	private:
		float radious;
		Point p;
};
