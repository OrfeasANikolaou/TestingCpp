#include <iostream>
#include <vector>
#include <utility> // std::rel_ops
class player{
	friend bool operator<(player, player);
	friend bool operator==(player, player);
	public:
		player(std::string, size_t);
	private:
		std::string name;
		size_t time_played; // cannot be negative therefore u64
};

template <typename T>
size_t count(std::vector<T> vec);

int main(void){
	std::vector<int> int_vec = { 4,0,5,3,2,0,0,0,0, };
	std::vector<player> p_vec = {player("p1", 50), player("p2", 1230), player("p3", 1230)};

	std::cout << count(int_vec) << std::endl; 
	std::cout << count(p_vec) << std::endl;

	return 0;
}

template <typename T>
size_t count(std::vector<T> vec){
	using namespace std::rel_ops; // operator> automatically overloaded
	size_t cnt = 0;				
	T min = vec.at(0);	// may be out of bounds (empty vector) so using .at()
	size_t const vsz = vec.size();	// set to a value so it doesn't get called everytime
	for (size_t i = 0; i < vsz; ++i){
		if (min > vec[i]){ 
			min = vec[i]; 														// cannot go out of bounds so can use [] instead of .at()
			cnt = 0; 
		} 																					// if a smaller value is found, then it's the smallest value
																								// and therefore was found 0 times
																								// cnt will always be at least 1 anyway except if empty vector
		if (vec[i] == min) ++cnt;
	}
	return cnt;
}

 //PLYAER CLASS 

/* friend functions --> overloads */
bool operator<(player x, player y){
	return x.time_played < y.time_played;
}
bool operator==(player x, player y){
	return x.time_played == y.time_played;
}


/* member functions --> constructors */
player::player(std::string n, size_t tp) : name(n), time_played(tp) {}

