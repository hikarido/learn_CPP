//
// Created by hikarido on 6/25/18.
// Данный модуль реализует форматированный вывод структур данных С++
// Возвожности:
// Вывод:
// * std::pair as (first, second)
// * std::vector as [el0, el1, ..., elN]
// * std::map as {pair0, pair1, ..., pairN} where pairI is std::pair formatted output

#ifndef SIMPLETESTFRAMEWORK_PRINTFRAMEWORK_H
#define SIMPLETESTFRAMEWORK_PRINTFRAMEWORK_H


#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using std::pair;
using std::ostream;
using std::vector;
using std::string;
using std::stringstream;
using std::map;

/**
 * собирает из коллекции стороку разделенную delimiter
 */
template<typename Iterable>
string join(const Iterable & obj, char delimiter){
	bool is_first = true;
	stringstream ss;

	for(const auto & i: obj){
		if(!is_first){
			ss << delimiter;
		}

		is_first = false;
		ss << i;
	}

	return ss.str();
}

/**
 * print pair to ostream enframed in () brackets
 */
template<typename First, typename Second>
ostream & operator<<(ostream & out, const pair<First, Second> & printing_pair){
	out << '(' << printing_pair.first << ", " << printing_pair.second << ')';
	return out;
};

/**
 * print vector to ostream enframed in [] brackets
 */
template<typename VecElement>
ostream & operator<<(ostream & out, const vector<VecElement> & printing_vector){
	return out << '[' << join(printing_vector, ',') << ']';
}

/**
 * print map to ostream enframed in {} brackets
 */
template<typename Key, typename Value>
ostream & operator<<(ostream & out, const map<Key, Value> & printing_map){
	return out << '{' << join(printing_map, ',') << '}';
};



#endif //SIMPLETESTFRAMEWORK_PRINTFRAMEWORK_H
