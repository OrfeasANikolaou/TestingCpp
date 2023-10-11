#include "./../headers/cargo.hpp"
#include <iostream>

//CLASS CARGO
//friend functions
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
	id(i), destination(d), weight(w), fragile(f) { ++this->count; }

//setters and getters
void cargo::set_weight(double const w) { this->weight = w; }
double cargo::get_weight(void) { return this->weight; }

//other functions
void cargo::show(void) const { std::cout << *this << std::endl; }
																	
