//
// Created by hikarido on 6/21/18.
// Задачи курсера по желтому поясу
// Practice Programming Assignment: База регионов

#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

enum class Lang {
	DE, FR, IT
};

struct Region {
	string std_name;
	string parent_std_name;
	map<Lang, string> names;
	int64_t population;

};


bool operator<(const Region & rhs, const Region & lhs)
{
	return 	tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
			  tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

bool operator==(const Region & rhs, const Region & lhs)
{
	return	tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) ==
			tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

/**
 * За N^2 сработает
 * @param regions
 * @return
 */
int FindMaxRepetitionCount(const vector<Region>& regions)
{
	int max_occures = 0;
	for(const auto & region: regions)
	{
		int cur_count = count(regions.cbegin(), regions.cend(), region);
		if(cur_count > max_occures)
		{
			max_occures = cur_count;
		}
	}

	return max_occures;
}

/**
 * За NlogN сработает
 * @param regions
 * @return
 */
int FindMaxRepetitionCount_from_yandex(const vector<Region>& regions)
{
	int result = 0;
	map<Region, int> repetion_count;
	for(const Region & region: regions)
	{
		result = max(result, ++repetion_count[region]);
	}

	return result;
}

int main()
{
	cout << FindMaxRepetitionCount_from_yandex({
										   {
												   "Moscow",
												   "Russia",
												   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
												   89
										   }, {
												   "Russia",
												   "Eurasia",
												   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
												   89
										   }, {
												   "Moscow",
												   "Russia",
												   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
												   89
										   }, {
												   "Moscow",
												   "Russia",
												   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
												   89
										   }, {
												   "Russia",
												   "Eurasia",
												   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
												   89
										   },
								   }) << endl;

	cout << FindMaxRepetitionCount_from_yandex({
										   {
												   "Moscow",
												   "Russia",
												   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
												   89
										   }, {
												   "Russia",
												   "Eurasia",
												   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
												   89
										   }, {
												   "Moscow",
												   "Russia",
												   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
												   89
										   }, {
												   "Moscow",
												   "Toulouse",
												   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
												   89
										   }, {
												   "Moscow",
												   "Russia",
												   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
												   31
										   },
								   }) << endl;
	return 0;
}

