#include <iostream>
void fun(int const, int const);
void fun(float const, float const);
void fun(int const, float const);
int main(void){
	int int_var(6);
	float float_var(3.141239);
	std::cout << "First call." << std::endl;
	fun(int_var, int_var);
	std::cout << "Second call." << std::endl;
	fun(float_var, float_var);
	std::cout << "Thrid call." << std::endl;
	fun(int_var, float_var);
	return 0;
}
void fun(int const a, int const b){
	using std::cout;
	using std::endl;
	cout << "Output int a: " << a << endl << 
					"Output int b: " << b << endl;
}
void fun(float const a, float const b){
	using std::cout;
	using std::endl;
	cout << "Output float a: " << a << endl << 
					"Output float b: " << b << endl;
}
void fun(int const a, float const b){
	using std::cout;
	using std::endl;
	cout << "Output int a: " << a << endl << 
					"Output float b: " << b << endl;
}
