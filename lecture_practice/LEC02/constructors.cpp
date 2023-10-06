#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
class Cat{
	public:
		Cat(string str, size_t a);
		void say_name(void);
		void say_age(void);
		void meaw(void);
		bool is_clean(void);
	private:
		string name;
		size_t age;	
};

int main(void){
	Cat c1("Psipsina", 1000000);
	c1.say_name();
	c1.say_age();
	c1.meaw();
	c1.is_clean();	
	cout << "something";
	return 0;
}
Cat::Cat(string str, size_t a){
	this->name = str;
	this->age = a;
}
void Cat::say_name(void){
	cout << "My name is " << name << endl;
}
void Cat::say_age(void){
	cout << "I am " << age << " years old" << endl;
}
void Cat::meaw(void){
	cout << "MEAAAAAAW" << endl;
}
bool Cat::is_clean(void){
	cout << "Cats are always clean" << endl;
	return true;
}

