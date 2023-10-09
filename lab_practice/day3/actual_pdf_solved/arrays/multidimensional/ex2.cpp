#include <iostream>
void print_arr(size_t  r, size_t  c, int ** a);
int main(void){
 	size_t rows = 4, cols = 3;	
	int** arr = new int*[rows];
	srand(time(NULL));
	
	for (size_t i = 0; i < rows; ++i){
		arr[i] = new int [cols]; 
	}	
	for (size_t i = 0; i < rows; ++i){
		for (size_t j = 0; j < cols; ++j){
			arr[i][j] = rand();
		}
	}
	
	print_arr(rows, cols, &arr[0]);
	return 0;
}

void print_arr(size_t  r, size_t  c, int  **a){
	for (size_t i = 0; i < r; ++i){
		for (size_t j = 0; j < c; ++j){
			using namespace std;
			cout << "A[" << i << "][" << j << "]: " << a[i][j] << endl;
		}
	}
}
