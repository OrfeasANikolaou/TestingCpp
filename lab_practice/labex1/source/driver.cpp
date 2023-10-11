#include "./../headers/cargo.hpp"
#include <iostream>
#include <utility>
using namespace std::rel_ops;
 
size_t cargo::count = 0;	
int main(void){
	using std::cout;
	using std::endl;
	cargo arr[5] = { cargo(1, "Patras", 100, false),
									cargo(2, "Athens", 200, true),
									cargo(3, "Kalamata" , 2000, false),
									cargo(4, "Patras", 1500, true),
									cargo(5, "Athens" , 1100, false), };
	for (size_t i = 0; i < 5; ++i){
		arr[i].make_safe();
		cout << "--------------------------" << endl << 
						arr[i] << endl;
	}
	/*
	 for (auto c : arr){
		c.make_safe();
	}
	*/
	cout <<  endl;
	for (cargo c : arr){
		cout << "---------------------------" << endl <<
						c << endl;
	}
	cout << endl << endl;
	cout << "Number of instances: " << cargo::count << endl;	
	return 0;
}
