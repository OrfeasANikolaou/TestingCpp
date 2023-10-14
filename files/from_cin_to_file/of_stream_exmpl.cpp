#include <iostream>
#include <fstream>

int main(void){
	
	std::ofstream exmpl;
	std::string line;
	exmpl.open("exmpl.txt");

	if (exmpl.is_open()){
		std::cin >> line;
		line >> exmpl;
	}
	else std::cout << "error" << std::endl;

	return 0;
}
