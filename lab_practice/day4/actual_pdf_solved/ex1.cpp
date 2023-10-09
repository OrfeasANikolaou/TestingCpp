#include <iostream>

class Person{
	public:
		Person(std::string, size_t = 0);
		virtual	void say(std::string const);
	private:
		std::string name;
		size_t age;
};

class Student : public Person{
	public:
		Student(std::string, size_t, size_t);
		virtual	void say(std::string const) override;
	private:
	 size_t semester;
};

int main(void){
	using namespace std;
	Person p1("Person1", 10);
	Person *p3 = new Student("new", 123123, -1);
	Student p4("p4", -3, -123);
	Person &p2 = p1;
	Person &p9 = p1;
	Person &p8 = p1;
	p1.say("something p1");
	Person* arr[] = {&p1, p3 ,&p4};
 	for (auto per : arr){
//for (Person* per : arr){
 	per->say("something");
 	}	 
	return 0;
}

Person::Person(std::string name, size_t age) : name(name), age(age) {
	using namespace std;	
	cout << "Adress for Person: " << this << endl;
}

void Person::say(std::string const msg){
	using std::cout;
	using std::endl;
	cout << "The person says: " << msg << endl;
}

Student::Student(std::string name, size_t age, size_t semester) :
	Person(name, age), semester(semester) {
	using namespace std;
		cout << "Adress for student: " << this << endl;
	}

void Student::say(std::string const msg){
	using std::cout;
	using std::endl;
	cout << "The student says: " << msg << endl;
}

