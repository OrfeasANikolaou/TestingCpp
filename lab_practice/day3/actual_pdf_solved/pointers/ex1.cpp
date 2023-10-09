#include <iostream>
void fun(int, int, int *, int *);
int main(void){
	using namespace std;
	int in1 = 23, in2 = 3;
	int sum;
	int mul;
	fun(in1, in2, &sum, &mul);
	cout << in1 << endl << in2 << endl << sum << endl <<  mul << endl;
	return 0;
}
void fun(int a, int b, int *sum, int *mul){
	*sum = a + b;
	*mul = a * b;
}
