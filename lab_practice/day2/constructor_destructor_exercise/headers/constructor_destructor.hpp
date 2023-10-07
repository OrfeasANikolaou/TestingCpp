#include <cstdint>
#include <ostream>
	using namespace std;
class A{
	public:
		A();
		A(int64_t X, int64_t Y);
		~A();
		// return outputstream
		// name of function?
		// ostram and A variables passed by reference
		friend ostream &operator<<(ostream &os, const A &obj);
	private:
		int64_t x, y;
};
