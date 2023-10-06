#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
class Dog{
	public:
		void set_age(size_t a);
		void set_name(string str);
		void increase_age(void);
		void bark(void);
		void say_age(void);
		void say_name(void);
	private:
		string name;
		size_t age;
};
	
int main(void){
	Dog d1, d2;
	d1.set_age(10000);
	d1.set_name("woof_one");
	d2.set_age(3);
	d2.set_name("woof_two");
	/* std::cin test here because why not 
	string some_var;
	std::cin >> some_var;
	cout << some_var << endl;
	*/
	// std::cin does NOT accept more than one word, just like scnaf("%s", str);
	cout << "-----DOG ONE-----" << endl;
	d1.bark();
	d1.say_age();
	d1.increase_age();
	d1.say_name();
	d1.say_age();
	cout << "-----DOG TWO-----" << endl;
	d2.bark();
	d2.say_age();
	d2.increase_age();
	d2.say_name();
	d2.say_age();
	return 0;
}
	void Dog::bark(void){
		cout << "Woof woof!" << endl;
	}
	void Dog::say_age(void){
		cout << "I am " << age << " years old" << endl;
	}
	void Dog::say_name(void){
		cout << "My name is " << name << endl;
	}
	void Dog::set_age(size_t a){
		age = a;
	}
	void Dog::increase_age(void){
		++age;
	}
	void Dog::set_name(string str){
		name = str;
	}
