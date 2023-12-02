#include <iostream>

enum selection{teach, footbller};

class person{
	public:
		person();
		person(int );
		virtual ~person();
		static int instances_of;
		virtual float compute_earnings() = 0;
	protected:
		int age;
};

class teacher : public person{
	public:
		teacher(int, std::string );
		float compute_earnings() override; // makes compiler check im not making a new method and 
																		 // is from the base class
	private:
		std::string profession;
};

class footballer : public person{
	public:	
		footballer(int, std::string );
		float compute_earnings() override;
	private:
		std::string team;
};

int person::instances_of = 0;

int main(void){
	person* a[3];
	for (size_t i = 0; i < 3; ++i){
		int sel;
		std::cout << "0: Teacher" << std::endl <<
								 "1: Footballer" << std::endl;
		do{
			std::cin >> sel;
		}while(sel != 0 && sel != 1);
		switch(sel){
			int age;
			case teach: {
				std::string profession;
				std::cout << "Teacher age: ";
				do{
					std::cin >> age;
				}while(age < 0);
				std::cout << "Teacher profession: ";
				do{
					std::cin >> profession;
				}while(profession.empty());
				a[i] = new teacher(age, profession);
				break; }
			case footbller: {
				std::string team;
				std::cout << "Footabller age ";	
				do{
					std::cin >> age;
				}while(age < 0);
				std::cout << "Footballer team: ";
				do{
					std::cin >> team;
				}while(team.empty());
				a[i] = new footballer(age, team);
				break; }
		}
	}
	{ // some random scope
		[[maybe_unused]] person* p = new teacher(5,"math"); //isntances_of ++
		std::cout << person::instances_of << std::endl;
		delete p;
	} // instances_of -- 
	std::cout << person::instances_of << std::endl;
	for (auto x : a){
		std::cout << x->compute_earnings() << std::endl;
	}
	return 0;
}

person::person() { ++this->instances_of;}
person::person(int a) : age(a) { ++this->instances_of; }
person::~person() { --this->instances_of;}

teacher::teacher(int a, std::string p) : person(a), profession(p) {}
float teacher::compute_earnings() { return 1000.0; }

footballer::footballer(int a, std::string t) : person(a), team(t) {}
float footballer::compute_earnings() { return 100000.0; }
