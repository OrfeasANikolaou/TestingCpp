#include <iostream>

int main(void){
	int* i=NULL;
	double* d=NULL;
	char* c=NULL;
	
	using namespace std;

	i = new int;
	d = new double;
	c = new char;
	cin >> *i;
	cin >> *d;
	cin >> *c;

	cout << "int " << *i << endl << "double " << *d << endl << "char " << *c << endl;
	delete i; delete d; delete c;
	return 0;
}
