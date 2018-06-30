//
// Created by hikarido on 7/1/18.
//


#include "pchheader.h"

using std::set;
using std::endl;
using std::cout;
using std::generate_n;
using std::inserter;

#include "catch.hpp"
#include "CourseraNearestTask.h"


TEST_CASE( "2: Factorial of 0 is 1 (fail)", "[multi-file:2]" ) {
	REQUIRE(1 == 2);
}

TEST_CASE("test 1", "[coursera test]"){
	set<int> numbers = {1, 4, 6};
	CHECK(*FindNearestElement(numbers, 0) == 1);
	CHECK(*FindNearestElement(numbers, 3) == 4);
	CHECK(*FindNearestElement(numbers, 5) == 4);
	CHECK(*FindNearestElement(numbers, 6) == 6);
	CHECK(*FindNearestElement(numbers, 100) == 6);
	set<int> empty_set;
	CHECK(FindNearestElement(empty_set, 8) == end(empty_set));
}

TEST_CASE("test 2", "[my test]"){
//	set<int> nums;
//	auto gen = [](){
//		static int i = -10;
//		return i++;
//	};
//	generate_n(inserter(nums, nums.end()), 21, gen);

	SECTION("Filled set"){
		set<int> nums = {-10, -8, -7, -5, -4, -3, -1, 0, 1, 3, 4, 5, 6, 7, 8, 10};

		SECTION("Border"){
			SECTION("Left"){
				CHECK(*FindNearestElement(nums, -100) == -10);
				CHECK(*FindNearestElement(nums, -10) == -10);
				CHECK(*FindNearestElement(nums, -9) == -10);
			}
			SECTION("Right"){
				CHECK(*FindNearestElement(nums, 100) == 10);
				CHECK(*FindNearestElement(nums, 10) == 10);
				CHECK(*FindNearestElement(nums, 9) == 8);
			}
		}

		SECTION("Existed"){
			CHECK(*FindNearestElement(nums, -8) == -8);
			CHECK(*FindNearestElement(nums, 0) == 0);
			CHECK(*FindNearestElement(nums, -1) == -1);
			CHECK(*FindNearestElement(nums, 1) == 1);
			CHECK(*FindNearestElement(nums, 8) == 8);
		}

		SECTION("Not existed"){
			CHECK(*FindNearestElement(nums, -2) == -3);
			CHECK(*FindNearestElement(nums, 2) == 1);
		}
	}

	SECTION("Empty set"){
		set<int> nums;

		CHECK(FindNearestElement(nums, -10) == nums.end());
		CHECK(FindNearestElement(nums, 10) == nums.end());

		for(int i = -100; i < 100; ++i){
			CHECK(FindNearestElement(nums, i) == nums.end());
			CHECK(FindNearestElement(nums, i) == nums.begin());
		}
	}
	SECTION("One sized"){
		set<int> nums = {1};
		CHECK(*FindNearestElement(nums, -10) == 1);
	}
//	SECTION("Left"){
//		CHECK(*FindNearestElement(nums, -9) == -10);
//		CHECK(*FindNearestElement(nums, -8) == -9);
//		CHECK(*FindNearestElement(nums, -2) == -2);
//	}
//	CHECK(*FindNearestElement(nums, 0)) == 0);
}
