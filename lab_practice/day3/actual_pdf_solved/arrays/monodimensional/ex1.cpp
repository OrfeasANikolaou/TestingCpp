#include <iostream>

int main(void){
	using namespace std;
	int arr[] = {2, 7, 1, 3, 6, };
	int x;
	int* narr;
	cin >> x;
	narr = new int[x * 5];
	for (size_t i = 0; i < x; ++i){
		for (size_t j = 0; j < 5; ++j){
		narr[i * 5 + j]	= arr[j];
		}
	}
	for (size_t i = 0; i < x * 5; ++i){
		cout << narr[i] << endl;
	}
	return 0;
}
