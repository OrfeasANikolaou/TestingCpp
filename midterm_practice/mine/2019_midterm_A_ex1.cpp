#include <iostream>
#include <vector>

class student{
	friend bool operator>(student const&, student const&);
	friend std::ostream& operator<<(std::ostream&, student const&);
	public:
		student(); // so new can be called
		student(std::string, float);
	private:
		std::string name;
		float grade;
};

template <typename T>
T* two_max(std::vector<T> const&);


int main(void){
	std::vector<int> int_vec{4,3,1,6,7,3,5,2,6,123,65,3,6,7,-3,354};
	int* int_maxes = two_max(int_vec);
	std::cout << int_maxes[0] << std::endl << int_maxes[1] << std::endl;
	delete[] int_maxes;
	
	std::vector<student> stu_vec{ student("s1",4.3),
																student("s2",6.0),
																student("s3",10.0),
																student("s4",8.0),
																student("s5", 8.4),
																student("s6", 3.2),
																student("s7", 9.9), };
	student* stu_maxes = two_max(stu_vec);
	std::cout << stu_maxes[0] << std::endl << stu_maxes[1] << std::endl;
	delete[] stu_maxes;

	return 0;
}

template <typename T>
T* two_max(std::vector<T> const& vec){
	T* ret = new T[2];
	ret[0] = ret[1] = vec.at(0); // isws empty vector
	for (auto x : vec){
		if (x > ret[0]){
			ret[1] = ret[0];
			ret[0] = x;
		}
		else if (x > ret[1]){
			ret[1] = x;
		}
	}
	return ret;
}
student::student() {}
student::student(std::string n, float g) : name(n), grade(g) {}
bool operator>(student const& x, student const& y){
	return x.grade > y.grade;
}
std::ostream& operator<<(std::ostream& os, student const& s){
	os << "Name: " << s.name << "\tGrade: " << s.grade;
	return os;
}
