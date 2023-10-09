#include <iostream>

int main(void){
	using namespace std;
	int a[5][5] = {0};
	
	for (size_t i = 0; i < 5; ++i){
		for (size_t j = 0; j < 5; ++j){
			a[i][j] = i + j;
			cout << "A[" << i << "][" << j << "]: " << a[i][j] << endl;
		}
	}

	
	
	return 0;
}
