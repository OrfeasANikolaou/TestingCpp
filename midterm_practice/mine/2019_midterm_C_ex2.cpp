#include <iostream>

class vehicle{ 
	public:
		vehicle(int, std::string, int);
		~vehicle();
		virtual int traffic_tax(void) const = 0;	
	protected:
		int registration_number;
		std::string owner_name;
		int cc;
	private:
};

class car : public vehicle{
	friend std::ostream& operator<<(std::ostream& , car const& );
	public:
		int traffic_tax(void) const override;
		car(int, std::string, int, int);
	private:
		int number_of_doors;
};

class truck : public vehicle{
	friend std::ostream& operator<<(std::ostream& , truck const& );
	public:
		int traffic_tax(void) const override;
		truck(int, std::string, int, int);
	private:
		int max_weight;
};

int total_tax(vehicle* [5]);

int main(void){
	vehicle* arr[5];
	int sum_tax = 0;
	for (size_t i = 0; i < 5; ++i){
		std::cout << "--------------------------" << std::endl <<
								 '\t' << i << '\t' << "VEHICLE" << std::endl <<
								 "--------------------------" << std::endl;
		int sel;
		do{
			std::cout << "0: Car" << std::endl <<
									 "1: Truck" << std::endl;
			std::cin >> sel;
		}while(sel != 0 && sel != 1);
		int rn, cc, x;
		std::string name;
		std::cout << "Enter registration number: ";
		std::cin >> rn;
		std::cout << "Enter owner name: ";
		std::cin >> name;
		std::cout << "Enter cc: ";
		std::cin >> cc;
		switch(sel){
			case 0: { 
				std::cout << "Enter number of doors: ";
				std::cin >> x;
				arr[i] = new car(rn, name, cc, x);
				break;}
			case 1: { 
				std::cout << "Enter max weight: ";
				std::cin >> x;
				arr[i] = new truck(rn, name, cc, x);
				break;}
		}
		sum_tax += arr[i]->traffic_tax();
	}
	std::cout << "Total tax: " << sum_tax << std::endl;
	return 0;
}

/* start vehicle definitions */

// start constructor definitions
vehicle::vehicle(int rn, std::string on, int c) : 
	registration_number(rn), owner_name(on), cc(c) {}
vehicle::~vehicle() {}
// end constructor definitions

// start member functions

// end member functions

/* end vehicle definitions */

/* start car definitions */

// start constructor definitions
car::car(int rn, std::string on, int c, int d) : vehicle(rn, on, c), number_of_doors(d) {}
// end constructor defintitions

// start member functions
int car::traffic_tax(void) const{
	int ret = 140;
	int t = 0;
	if (cc > 1000){
		t = cc - 1000;
		t /= 100;
		ret += t * 10;
	}
	return ret;
}

// start overloads
std::ostream& operator<<(std::ostream& os, car const& c){
	os << "Registration number: " << c.registration_number << std::endl <<
	 			"Owner name.........: " << c.owner_name << std::endl <<
				"cc.................: " << c.cc << std::endl <<
				"Number of doors....: " << c.number_of_doors << std::endl;	
	return os;
}

/* end car definitions */

/* start truck definitions */

// start constructor definitions
truck::truck(int rn, std::string on, int c, int mw) : vehicle(rn, on, c), max_weight(mw) {}
// end constructor defintions

// start member functions
int truck::traffic_tax(void) const{
	int ret = 300;
	if (this->max_weight > 3000 && this->max_weight <= 6000) { ret = 400; }
	if (this->max_weight > 6000) { ret = 600; }
	return ret;
}

// end member functions
std::ostream& operator<<(std::ostream& os, truck const& t){
	os << "Registration number: " << t.registration_number << std::endl <<
				"Owner name.........: " << t.owner_name << std::endl << 
				"cc.................: " << t.cc << std::endl <<
				"Max weight.........: " << t.max_weight << std::endl;
	return os;
}

/* end truck defintions */


int total_tax(vehicle* v[5]){
	int total = 0;
	for (size_t i = 0; i < 5; ++i){
		total += v[i]->traffic_tax();
	}
	return total;
}
