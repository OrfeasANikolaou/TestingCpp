#include <cstdint>
#include <iostream>
#include <utility>

class customer{
	friend bool operator==(customer, customer);
	friend bool operator<(customer, customer);
	friend std::ostream &operator<<(std::ostream &, customer &);
	public:
		customer();
		customer(std::string, int64_t = 0);
	private:
		std::string name;
		int64_t balance; //signed because customer can owe money
										 //int because doubles are not accurate enough for money
										 //balance is in cents
};

int main(void){
	using namespace std::rel_ops;
	using std::cout;
	using std::endl;
	customer a("one", -3424),b("two", 234563);
	cout << a << endl;
	cout << b << endl;
	if (a==b) cout << "eq" << endl;
	if (a<b) cout << "lt" << endl;
	if (a>b) cout << "gt" << endl;
	if (a<=b) cout << "le" << endl;
	if (a>=b) cout << "ge" << endl;
	if (a!=b) cout << "ne" << endl;	

	return 0;
}

customer::customer() : balance(0) {}
customer::customer(std::string n, int64_t b) : name(n), balance(b) {}

bool operator==(customer a, customer b){
	bool ret;
	if (a.balance == b.balance) ret = true;
	else ret = false;
	return ret;
}

bool operator<(customer a, customer b){
	bool ret;
	if (a.balance < b.balance) ret = true;
	else ret = false;
	return ret;
}

std::ostream &operator<<(std::ostream &os, customer &c){
	using std::cout;
	using std::endl;
	int16_t	cents;
	int64_t whole;
	if (c.balance < 0) cents = -c.balance % 100;
	else cents = c.balance % 100;
	
	whole = c.balance - cents;
	whole /= 100;
	cout << "Name: " << c.name << endl <<
					"Balance: " << whole << '.' << cents << "€";
	return os;
}
