// Γράψτε ένα πρόγραμμα που να ορίζει μια κλάση Α με ένα ακέραιο ιδιωτικό μέλος δεδομένων x και ένα ακέραιο δημόσιο μέλος δεδομένων y.
// Συμπληρώστε τον απαιτούμενο κώδικα έτσι ώστε για ένα αντικείμενο που δημιουργείται στη main να εμφανίζεται τόσο η τιμή του x όσο και η τιμή του y.

#include <iostream>


/*
 * SOLVED
 */


using namespace std;

class A
{
friend ostream &operator<<(ostream &os, A &a){
	using namespace std;
	cout << "x value: " << a.x << endl << 
					"y value: " << a.y;
	return os;
}
private:
    int x;

public:
    int y;
    A(int x, int y) : x(x), y(y) {}
		void print_A(){
			using std::cout;
			using std::endl;
			cout << *this << endl;
		}
};

int main()
{
    A obj(1, 2);
		obj.print_A();
}
