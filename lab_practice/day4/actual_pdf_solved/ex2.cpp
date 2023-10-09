#include <cstddef>
#include <iostream>
#include <string>

class date{
	public:
		virtual std::string desc(void);
		date();
		date(size_t, size_t);
		date(size_t, size_t, size_t);
		size_t get_day(void);
		size_t get_month(void);
		size_t get_year(void);
	private:
		size_t day;
		size_t month;
		size_t year;
};

class holiday : public date{
	public:
	virtual	std::string desc(void) override;
	holiday(size_t, size_t, size_t, std::string);
	private:
		std::string name;	
};

int main(void){
	date d1(2, 8, 2024);
	holiday h1(2, 8, 2024, "ginomai 20");
	date &d2 = d1;
	date d3(3, 5, 7);
	holiday h2(1, 1, 2024, "KALH XRONIA");
	holiday h3(4, 3, 2000, "Kapios prepei na genh8hke tote");
	date *d4 = new holiday(12,12,2012, "telos tou kosmou");
	date *arr[] = {&d1, &h1, &d2, &d3, d4, &h2, &h3, };
	for (auto d : arr){
	using namespace std;
		 cout << d->desc() << endl;
	}
	return 0;

}
//CONSTRUCTORS
date::date() : day(1), month(1), year(2021) {}
date::date(size_t d, size_t m) : day(d), month(m), year(2021) {}
date::date(size_t d, size_t m, size_t y) : day(d), month(m), year(y) {}

//GETTERS
size_t date::get_day(void){
	return this->day;
}
size_t date::get_month(void){
	return this->month;
}
size_t date::get_year(void){
	return this->year;
}

std::string date::desc(void){
	std::string ret = std::to_string(this->day) + '/' + 
										std::to_string(this->month) + '/' + 
										std::to_string(this->year);
	return ret;	
}

holiday::holiday(size_t d, size_t m, size_t y, std::string n) : date(d, m, y), name(n) {}
std::string holiday::desc(void){
	std::string ret = date::desc() + " " + this->name;
	return ret;
}

