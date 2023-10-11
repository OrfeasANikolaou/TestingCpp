#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "cargo.hpp"
size_t cargo::count = 0;
TEST_CASE( "make_safe_working", "[make_safe]" ){
	cargo test[] = { cargo(1, "Patras", 100, false), 
										cargo(2, "Athens", 200, true),
										cargo(3, "Kalamata", 2000, false),
										cargo(4, "Patras", 1500, true),
										cargo(5, "Athens", 1100, false), };	
	for (size_t i = 0; i < (sizeof(test) / sizeof(cargo)); ++i){
		test[i].make_safe();
	}
	REQUIRE (test[0].get_weight() == 105);
	REQUIRE (test[1].get_weight() == 200);
	REQUIRE (test[2].get_weight() == 2005);
	REQUIRE (test[3].get_weight()	== 1500);
	REQUIRE (test[4].get_weight() == 1105);
	REQUIRE (cargo::count == 5);
}
