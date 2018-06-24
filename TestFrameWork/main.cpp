//
// Created by hikarido on 6/24/18.
//

#include "simpleTestFramework.h"

void test_1(){
	Assert(1 == 2, "lustig test 1");
}

void test_map_equals(){
	std::map<pair<int, int>, vector<int>> m = {{{1,2}, {1,2,3}}};
	decltype(m) ans_m = {{{1,2}, {1,3,5}}};
	AssertEqual(m, ans_m, "data structures in test");
}

void correct_test(){
	Assert(true, "yes that is");
}
void testAll(){
	TestRunner tr;

	tr.RunTest(test_1, "test_1");
	tr.RunTest(test_map_equals, "test_map_equals");
	tr.RunTest(correct_test, "correct_test");
}
int main(){
	testAll();
	return 0;
}