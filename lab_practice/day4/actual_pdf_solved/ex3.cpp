#include <iostream>
#include <string>

class pet{
	public:	
	pet(std::string);
	virtual std::string sound() = 0;
	virtual void make_sound();	
	protected:
		std::string _name;
};
class dog : public pet{
	public:
	dog(std::string);
	virtual std::string sound() override;
	virtual void make_sound() override;
};
class cat : public pet{
	public:
	cat(std::string);
	virtual std::string sound() override;
	virtual void make_sound() override;
};
int main(void){
	dog d1("dog1"), d2("dog2"), d3("dog3");
	cat c1("cat1"), c2("cat2"), c3("cat3");
	
	 pet* pets[] = {&d1, &d2, &d3, &c1, &c2, &c3};
	for (auto p : pets){
		p->make_sound();
	}
	return 0;
}
// PET CLASS
pet::pet(std::string name) : _name(name){
	using namespace std;
	cout << "Adress of pet: " << this << endl;
}

void pet::make_sound(){
	using namespace std;
	cout << "Name: " << _name << " " << sound();
}

// DOG CLASS
dog::dog(std::string name) : pet(name){
	using namespace std;
	cout  << "Adress of dog: " << this << endl;
}

std::string dog::sound(){	
	return "DOG SOUND\n";
}

void dog::make_sound(){
	pet::make_sound();
	std::cout << _name << " calling from other function. " << std::endl;
}

//CAT CLASS
cat::cat(std::string name) : pet(name){
	using namespace std;
	cout << "Adress of cat: " << this << endl;
}

std::string cat::sound(){
	return "CAT SOUND\n";
}

void cat::make_sound(){
	pet::make_sound();
	std::cout << _name << " calling from other function. " << std::endl;

}


