//
// Created by hikarido on 6/24/18.
//

#include "simpleTestFramework.h"

int main(){
	std::map<pair<int, int>, vector<int>> m = {{{1,2}, {1,2,3}}};
	decltype(m) ans_m = {{{1,2}, {1,3,5}}};
	AssertEqual(m, ans_m);

	int a = 3;
	int b = 4;
	AssertEqual(3,4, "test 1");
	return 0;
}