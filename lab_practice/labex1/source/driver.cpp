#include "./../headers/cargo.hpp"
#include <utility>
using namespace std::rel_ops;

int main(void){
	cargo arr[5] = { cargo(1, "Patras", 100, false),
									cargo(2, "Athens", 200, true),
									cargo(3, "Kalamata" , 2000, false),
									cargo(4, "Patras", 1500, true),
									cargo(5, "Athens" , 1100, false), };	
	return 0;
}
