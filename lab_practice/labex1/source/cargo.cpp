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
					"Cargo fragility: " << cargo.fragile << endl;
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

//public functions
//constructors
cargo::cargo() : id(0), destination("Undefined"), weight(0), fragile(false){ ++cargo::count;}
cargo::cargo(int id, std::string destination, double weight, bool fragile) :
	id(id), destination(destination), weight(weight), fragile(fragile) { ++cargo::count;}

//setters and getters
void cargo::set_weight(double const w) { this->weight = w; }
double cargo::get_weight(void) { return this->weight; }

//other functions
void cargo::show(void) const { std::cout << *this; }
void cargo::make_safe(void) { if ( !this->fragile) {this->fragile = true; this->weight +=5;}}
																	// if not fragile
																	
