//
// Created by hikarido on 6/24/18.
//

#include "power_and_multiplying.cpp"
#include <sstream>

using namespace std;

// Section for testing multiply section
bool test_pair_multiplying(){
	{
		pair<int, int> p = {1,1};
		auto pow2p = p * p;
		assert(pow2p == std::make_pair(1,1));
	}

	{
		pair<int, double> p = {3, 9.0};
		assert((p*p) == std::make_pair(9, 81.0));
	}

	{
		pair<double, int> p = {-1, 0};
		auto p2 = std::make_pair<double, int>(1, 0);
		assert((p*p) == p2);
	}

	{
		pair<pair<int, int>, int> p = {{2,3}, 4};
		assert((p*p) == std::make_pair(std::make_pair(4,9), 16));
	}

	{
		pair<int, pair<int, int>> p = {2, {3,4}};
		assert((p*p) == std::make_pair(4, std::make_pair(9, 16)));
	}

	{
		pair<pair<int,int>, pair<int, int>> p = {{2,3}, {4,5}};
		pair<pair<int, int> ,pair<int, int>> ans = {{4, 9}, {16, 25}};
		assert((p*p) == ans);
	}

	{
		pair<int, vector<int>> p = {2, {2,3,4}};
		decltype(p) ans = {4, {4, 9, 16}};
		assert((p*p) == ans);
	}

	return true;
}

bool test_map_multiplying(){
	{
		map<int, int> m;
		map<int, int> ans;
		assert((m*m) == ans);
	}
	{
		map<int, int> m = {{1, 2}, {3,4}};
		map<int, int> ans = {{1,4}, {3, 16}};
		assert((m * m) == ans);
	}

	{
		map<int, map<int, int>> m = {{3, {{3,10}}}};
		decltype(m) ans = {{3, {{3, 100}}}};
		assert((m*m) == ans);
	}

	{
		map<int, pair<int, int>> m = {{2, {3,4}}};
		map<int, pair<int, int>> ans = {{2, {9, 16}}};
		assert((m*m) == ans);
	}

	{
		map<pair<int,int>, int> m = {{{2,3}, 3}};
		decltype(m) ans = {{{2,3}, 9}};
		assert((m*m) == ans);
	}

	{
		map<int, pair<int, int>> m = {{2, {3 ,4}}};
		map<int, pair<int, int>> ans = {{2, {9, 16}}};
		assert((m*m) == ans);
	}

	{
		map<pair<int, int>, pair<int, int>> m = {{{-2,3}, {3,-4}}};
		decltype(m) ans = {{{-2,3}, {9, 16}}};
		assert((m*m) == ans);
	}

	{
		map<vector<int>, int> m = {{{1,2,3}, 3}, {{22,11}, 4}};
		decltype(m) ans = {{{1,2,3}, 9}, {{22,11}, 16}};
		assert((m*m) == ans);
	}

	{
		map<int, vector<int>> m = {{4, {1,2,3}}, {5, {2,3,-4}}};
		map<int, vector<int>> ans = {{4, {1,4,9}}, {5, {4, 9, 16}}};
		assert((m*m) == ans);
	}

	{
		map<vector<int>, vector<int>> m = {{{1,2,3}, {2,3}}, {{2,3}, {3, 4, 5}}};
		decltype(m) ans = {{{1,2,3}, {4,9}}, {{2,3}, {9, 16,25}}};
		assert((m*m) == ans);
	}


//	map as key, No iam not do this....
//	{
//		map<map<int, int>, int> m = {{{2,4}, 3}};
//		decltype(m) ans = {{{{2, 16}}, 9}};
//		assert((m*m) == ans);
//
//
//	}

	return true;
}

bool test_vector_multiplying(){
	{
		vector<int> v;
		assert((v*v) == v);
	}

	{
		vector<int> v = {1,2,3,4,5};
		vector<int> ans = {1,4,9,16,25};
		assert((v*v) == ans);
	}

	{
		vector<pair<int, int>> v = {{1,2}, {3,4}};
		decltype(v) ans = {{1,4}, {9, 16}};
		assert((v*v) == ans);
	}

	{
		vector<vector<int>> v = {{1,2,3}, {3,4,5}};
		decltype(v) ans = {{1, 4, 9}, {9,16, 25}};
		assert((v*v) == ans);
	}

	{
		vector<vector<pair<int, int>>> v = {{{2,3}, {3, 4}}};
		decltype(v) ans = {{{4, 9}, {9, 16}}};
		assert((v*v) == ans);
	}

	{
		vector<vector<pair<int, vector<int>>>> v = {{{2, {2,3,4}}, {3, {1,2,3}}}};
		decltype(v) ans = {{{4, {4, 9, 16}}, {9, {1,4,9}}}};
		assert((v*v) == ans);
	}

	return true;
}

bool test_collection_multiplying(){
	{
		vector<int> v = {-1,2,3, 0};
		v = power2(v);
		vector<int> ans = {1, 4, 9, 0};
		assert(v == ans);
	}

	{
		map<int, vector<pair<int, int>>> m = {
				{1, {{1,2},{2,2},{3,3}}},
				{2, {{-1, -1}, {0,0}, {2,2}}},
				{3, {{1,2}}}
		};

		decltype(m) ans = {
				{1, {{1, 4}, {4, 4}, {9, 9}}},
				{2, {{1, 1}, {0,0}, {4,4}}},
				{3, {{1,4}}}
		};
		assert((power2(m)) == ans);
	}
	return true;
}

string test_power_and_multiply(){
	stringstream ss;
	if(test_pair_multiplying()){
		ss << "test_pair_multiplying pass: ok" << endl;
	}

	if(test_map_multiplying()){
		ss << "test_map_multiplying pass: ok" << endl;
	}

	if(test_vector_multiplying()){
		ss << "test_vector_multiplying pass ok" << endl;
	}
	if(test_collection_multiplying()){
		ss << "test_collection_multiplying pass ok" << endl;
	}

	return ss.str();
}
// End section for testing implementation of multiply
