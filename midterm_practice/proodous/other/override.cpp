#include <iostream>
class a{
	public:
		virtual void some_method(int , size_t);
};

class b : public a{
	public:
		void some_method(int, size_t) override; 
};
