#include "./../headers/makefile_example.hpp"

int main(void){
	Person p1("person_one", 19, 2.00, 1000, false);
	//Person p1("person_one", 19, 2.00, 1000, true);
	p1.print_stats();
	p1.change_name("definitely_not_person_one");
	p1.increase_age();
	p1.change_height(2.10); // another grouth spurt
	p1.change_ID(9999);
	p1.eat();
	p1.interact();
	p1.walk();
	p1.print_stats();
	return 0;
}
