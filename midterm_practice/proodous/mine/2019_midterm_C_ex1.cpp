#include <iostream>
#include <sstream>
enum class ACCOUNT_TYPE { CHECKING,
										SAVINGS,
										MONEY_MARKET, };  // ACCOUNT_TYPE::some_enum_val

class account{
	friend bool operator<(account const&, account const&);
	public:
		account();
		account(std::string const&, int const&, ACCOUNT_TYPE const& );
		account(account const& ); //Copy constructor takes a reference to an object of the same class as an argument.
		~account();
		std::string GET_owner(void) const;
		double GET_balance(void) const;
		ACCOUNT_TYPE GET_account_type(void) const;
		void SET_owner(std::string const& );
		void SET_balance(int const& );
		void SET_account_type(ACCOUNT_TYPE const& );
		void deposit(double const& );
		double withdrawal(double const& );
		operator std::string(void) const;
		static size_t nr_of_accounts;
	private:
		std::string owner;
		double balance; // in cents
		ACCOUNT_TYPE type; 
};

size_t account::nr_of_accounts = 0;
int main(void){
	account acc1;
	account acc2("Ken Lay", 100.000, ACCOUNT_TYPE::MONEY_MARKET);
	account acc3 = acc2;
	double wi, amnt;
	std::cout << "Number of accounts: " << account::nr_of_accounts << std::endl;
	do{
		std::cout << "Enter valid withdrawal from acc2 (press 0 to cancel): ";
		std::cin >> wi;
	}while(wi < 0);	
	amnt = acc2.withdrawal(wi);
	acc3.deposit(amnt * 0.8);
	amnt -= amnt * 0.8;	// amount remaining to deposit
	acc1.deposit(amnt);
	amnt -= amnt;	// gets compiled to amnt = 0 but i put it like that to be pedantic
	std::cout << std::string(acc1) << std::endl << 
							 std::string(acc2) << std::endl <<
							 std::string(acc3) << std::endl;
	std::cout << "-------HAS LESS (KEN LAY)------" << std::endl;
	if (acc2 < acc3) { std::cout << std::string(acc2) << std::endl; }
	else { std::cout << std::string(acc3) << std::endl; }	
	return 0;
}


//ACCOUNT CLASS 
//getters
std::string account::GET_owner(void) const { return this->owner; }
double account::GET_balance(void) const { return this->balance; }
ACCOUNT_TYPE account::GET_account_type(void) const { return this->type; };
//setters
void account::SET_owner(std::string const& o) { this->owner = o; }
void account::SET_balance(int const& b) { this->balance = b; }
void account::SET_account_type(ACCOUNT_TYPE const& a) { this->type = a; }
//constructors destructors
account::account() : owner("Noname"), balance(0), type(ACCOUNT_TYPE::CHECKING) { 
	++this->nr_of_accounts;
}
account::account(std::string const& s, int const& b, ACCOUNT_TYPE const& t) :
	owner(s), balance(b), type(t) { ++this->nr_of_accounts; }
account::account(account const& other){ // copy constructor 
	this->owner = other.owner; 
	this->balance = 0; 
	this->type = other.type;
	++this->nr_of_accounts;
} 
account::~account() { --this->nr_of_accounts; }
//member functions
void account::deposit(double const& x) {
	this->balance += x;
}
double account::withdrawal(double const& x){
	double ret;
	if (this->balance >= x){
		this->balance -= x;
		ret = x;
	}
	else {
		ret = x - this->balance; // x - this->balance always positive because of if statement
		this->balance = 0;
	}
	return ret;	// withdrawal amount even if desired amount > balance
}
//overlaods
bool operator<(account const& x, account const& y) { return x.balance < y.balance; }
account::operator std::string(void) const {
	std::stringstream ss;
	std::string typestr;
	switch(this->type){
		case ACCOUNT_TYPE::CHECKING: 			{ typestr = "CHECKING";			break; }
		case ACCOUNT_TYPE::SAVINGS:  			{ typestr = "SAVINGS";			break; }
		case ACCOUNT_TYPE::MONEY_MARKET:	{ typestr = "MONEY_MARKET"; break; }
	}
	ss << this->owner << " - " << this->balance << " - " << typestr;
	return ss.str();
}


