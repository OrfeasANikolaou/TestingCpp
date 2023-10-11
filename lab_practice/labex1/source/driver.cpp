#include "./../headers/cargo.hpp"
#include <iostream>
#include <utility>
#include <algorithm>

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
	}
/*		THIS WORKS, IT'S JUST COMMENTED BECAUSE IT HAS NO REASON TO EXIST
 *		IT'S JUST TO SHOW THAT THE CMP OPERATORS ARE OVERLOADED CORRECTLY
 *
	if (arr[0] == arr[1]) cout << "same" << endl;
	if (arr[0] != arr[1]) cout << "different" << endl;
	if (arr[0] < arr[1]) cout << "smaller" << endl;
	if (arr[1] > arr[0]) cout << "bigger" << endl;
	cout << endl;
  *
	*/

	std::sort(&arr[0], &arr[5] );
	for (cargo c : arr){
		cout << "---------------------------" << endl; 
						c.show();
	}
	cout << endl;

	cout << "Number of instances: " << cargo::count << endl;	
	return 0;
}
