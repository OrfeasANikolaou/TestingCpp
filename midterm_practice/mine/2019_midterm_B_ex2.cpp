#include <iostream>

class task{
	friend std::ostream& operator<<(std::ostream& os, task const& t);
	public:
		task(size_t, size_t, std::string);	// constructor with all fields
		void SET_description(std::string);	// sets description
		std::string GET_description(void);	// returns description
		bool has_conflict(task const* const other) const;// checks if two tasks have conflict (occur in same timeframe)
	private:
		size_t from;
		size_t to;
		std::string descritpion;
};


int main(void){
	task arr[4] = { task(234,300,"my first task"),
									task(345,400,"my second task"),
									task(0,250,"my third task"),
									task(1000,5000,"my last task"), };
	/*
	 // FIRST ITERATION WITH GOTO
	 for (size_t i = 0; i < 4; ++i){
		for (size_t j = 0; j < 4; ++j){
			if (j != i){
				if (arr[i].has_conflict(&arr[j])) goto L;
			}
		}
	std::cout << arr[i] << std::endl;
L:
	if(true) [[maybe_unused]] int x = 0; // cute hack so i don't have any warnings
	}
	*/
	
	 // SECOND ITERATION WITH FLAG
	for (size_t i = 0; i < 4; ++i){
	bool flag = false;
		for (size_t j = 0; j < 4; ++j){
			if (j != i){
				if (arr[i].has_conflict(&arr[j])) flag = true;
			}
		}
		if (!flag) { std::cout << arr[i] << std::endl; }
	}

	return 0;
}

task::task(size_t f, size_t t, std::string d) : from(f), to(t), descritpion(d) {
	// doesn't make sense from a next point in time to a previous point in time, does it?
	if (this->from > this->to){
		size_t temp = this->from;
		this->from = this->to;
		this->to = temp;
	}
}
void task::SET_description(std::string str) { this->descritpion = str; }
std::string task::GET_description(void) { return this->descritpion; }
bool task::has_conflict(task const* const other) const{
 	bool ret = true;	
	if (this->to < other->from || other->to < this->from) { ret = false;}
	return ret;
}
std::ostream& operator<<(std::ostream& os, task const& t){
	os << "Starting time: " << t.from << std::endl <<
	 			"Ending time: " << t.to << std::endl <<
				"Task description: " << t.descritpion;
	return os;
}

