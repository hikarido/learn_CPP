//
// Created by hikarido on 6/29/18.
//

#define CATCH_CONFIG_MAIN
#include <set>

using std::set;

#include "catch.hpp"
#include "CourseraNearestTask.h"


TEST_CASE("test", "test"){
	set<int> s = {1, 4, 6};
	CHECK(*FindNearestElement(s, 1) == 2);
	set<int> s2 = {1,2,3,4};
	CHECK(s == s2);
}

