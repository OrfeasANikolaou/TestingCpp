#include <fstream>
#include <iostream>

int main(void){
	std::string line;
//	char c;
	std::ifstream sf ("some_file.txt");
/*	if (sf.is_open()){
		while (sf.get(c)){
				
			std::cout << c;
		}
		sf.close();
	}
	*/
	if (sf.is_open()){
		while (getline(sf, line)){
			std::cout << line << std::endl;
		}
	}
	else std::cout << "error" << std::endl;
	return 0;
}
