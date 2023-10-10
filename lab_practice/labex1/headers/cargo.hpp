#include <string>
class cargo{
	//friend functions
	friend std::ostream& operator<<(std::ostream& , cargo const &);
	friend bool operator==(cargo const, cargo const);
	friend bool operator<(cargo const, cargo const);
	public:
		cargo();
		cargo(int , std::string = "Undefined", double = 0, bool = false);
		void set_weight(double  const);
		double get_weight(void);
		void show(void) const;
		void make_safe(void);
	 static size_t count;	
	private:
		int id;
		std::string destination;
		double weight;
		bool fragile;
};

