#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
class cargo{
	//friend functions
	friend std::ostream& operator<<(std::ostream& , cargo const &);
	friend bool operator==(cargo const, cargo const);
	friend bool operator<(cargo const, cargo const);
	public:
		cargo();
		cargo(int , std::string = "Undefined", double = 0, bool = false);
		void set_weight(double  const);
		double get_weight(void);
		void show(void) const;
		void make_safe(void);

	private:
		int id;
		std::string destination;
		double weight;
		bool fragile;
};
std::ostream& operator<<(std::ostream& os, cargo const& cargo){
	using std::cout;
	using std::endl;
	cout << "Cargo ID: " << cargo.id << endl <<
					"Cargo destination: " << cargo.destination << endl <<
					"Cargo weight: " << cargo.weight << endl <<
					"Cargo fragility: " << cargo.fragile;
	return os;
}
bool operator==(cargo const a, cargo const b){
	bool ret = false;
	if (a.fragile == b.fragile &&
			a.destination == b.destination &&
			a.id == b.id &&
			a.weight == b.weight) ret = true;
	return ret;
}
bool operator<(cargo const a, cargo const b){
	return a.weight < b.weight;
}
void cargo::make_safe(void) { if ( !fragile) {fragile = true; weight +=5;}}
																	// if not fragile

//public functions
//constructors
cargo::cargo() : cargo(0) { } // inside header files ive got =undefined, =0, =false the rest
cargo::cargo(int i, std::string d, double w, bool f) :
	id(i), destination(d), weight(w), fragile(f) {}

//setters and getters
void cargo::set_weight(double const w) { this->weight = w; }
double cargo::get_weight(void) { return this->weight; }

//other functions
void cargo::show(void) const { std::cout << *this << std::endl; }

TEST_CASE( "make_safe_working", "[make_safe]" ){
	cargo test[] = { cargo(1, "Patras", 100, false), 
										cargo(2, "Athens", 200, true),
										cargo(3, "Kalamata", 2000, false),
										cargo(4, "Patras", 1500, true),
										cargo(5, "Athens", 1100, false), };	
	for (size_t i = 0; i < (sizeof(test) / sizeof(cargo)); ++i){
		test[i].make_safe();
	}
	REQUIRE (test[0].get_weight() == 105);
	REQUIRE (test[1].get_weight() == 200);
	REQUIRE (test[2].get_weight() == 2005);
	REQUIRE (test[3].get_weight()	== 1500);
	REQUIRE (test[4].get_weight() == 1105);
}
