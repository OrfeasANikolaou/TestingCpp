#include <iostream>

class MyClass {
    private:
        int x_;

    public: 
        // στατικό μέλος δεδομένων
	//every object of the same class can see this, and can by called with CLASSNAME::a
        static int a;
        
        // default constructor
        MyClass() : MyClass(0) {} // delegation to another constructor

        MyClass(int x) : x_(x) {
            MyClass::a++; // single point of responsibility
        }
        
        // στατική συνάρτηση μέλος κλάσης
	//every object of the same class can see this, and can by called with CLASSNAME::print_number_of_objects()
        static void print_number_of_objects(){
            std::cout << "Number of instances: " << a << std::endl;
        }
};

// αρχικοποίηση στατικού μέλους δεδομένων της κλάσης MyClass
int MyClass::a = 0;

int main(){
    MyClass obj1(5), obj2(7);
    MyClass objs[10];
    obj1.print_number_of_objects();
    std::cout << "# of instances: " << MyClass::a << std::endl;
    return 0;
}

/*
Number of instances: 12
# of instances: 12
*/
