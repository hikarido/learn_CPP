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

int main(){
	RunTest(test_1, "test_1");
	RunTest(test_map_equals, "test_map_equals");
	RunTest(correct_test, "correct_test");
//	int a = 3;
//	int b = 4;
//	AssertEqual(3,4, "test 1");
	return 0;
}