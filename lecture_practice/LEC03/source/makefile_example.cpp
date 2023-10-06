#include "./../headers/makefile_example.hpp"

Person::Person(std::string n, size_t a, float h, size_t id, bool g){
	this->name = n;
	this->age	= a;
	this->height = h;
	this->ID = id;
	this->gender = g;
}
void Person::change_name(std::string str){
	if (age >= 18) name = str;
	else std::cout << "You are not old enough to change your name." << std::endl;
}
void Person::change_height(float h){
	height = h;
}
void Person::change_ID(size_t id){
	ID = id;	
}
void Person::increase_age(void){
	++age;
}
void Person::print_stats(void){
	using namespace std;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Height: " << height << endl;
	cout << "ID: " << ID << endl;
	if (gender)	cout << "Gender: male" << endl; 
	else cout << "Gender: female" << endl;
}
void Person::walk(void){
	std::cout << "What a nice weather it is today!" << std::endl;
}
void Person::interact(void){
	std::cout << "Hello." << std::endl;
}
void Person::eat(void){
	std::cout << "Man, that was delicious!" << std::endl;
}
