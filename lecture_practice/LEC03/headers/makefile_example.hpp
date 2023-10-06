#include <iostream>
class Person{
	public:
		Person(std::string name, size_t a, float h, size_t id, bool g);
		void change_name(std::string str);
		void change_height(float h);
		void change_ID(size_t id);
		void increase_age(void);
		void print_stats(void);
		void walk(void);
		void interact(void);
		void eat(void);
	private:
		std::string name;
		size_t age;
		float height;
		size_t ID;
		bool gender; 
		/* 0 for female, 1 for male */
};
