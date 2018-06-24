//
// Created by hikarido on 6/24/18.
// Программа возводящая переданный аргумент в квадрат

// Task from coursera
// https://www.coursera.org/learn/c-plus-plus-yellow/programming/YQJs1/vsio-v-kvadrat

// у нас есть пара вектор и мапа
// они содержат друг друга произвольно и не попорядку , а бы как
// на самом нижнем уровне находятся примитивы, некие, их нужно возвести в квадрат
// и затем медленно подниматься на верх возводя в квадрат вся и всех

// 1) определим функции вывода пары, вектопра и карт
// 2) определим возведение в квадрат
// * пары
// * вектора
// * словаря
// 3) протестируем решение


#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>
#include <map>

using std::cout;
using std::endl;
using std::pair;
using std::ostream;
using std::vector;
using std::string;
using std::stringstream;
using std::map;

// printting function section


/**
 * print pait to ostream enframed in () brackets
 */
template<typename First, typename Second>
ostream & operator<<(ostream & out, const pair<First, Second> & printing_pair){
	out << '(' << printing_pair.first << ", " << printing_pair.second << ')';
	return out;
};

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

// test print section

void test_print_pair(){
	pair<int, char> p = {1, 'd'};
	cout << p << endl;
}

void test_print_vector(){
	vector<char> v = {'1', '2', '3'};
	cout << v << endl;
}

void test_print_map(){
	map<char, bool> m = {
			{'a', true},
			{'0', false},
			{'5', true}
	};

	cout << m << endl;
}

void test_join(){
	vector<int> v = {1,2,3,4};
	assert(join(v, ',') == "1,2,3,4");

	map<int, string> m = {
			{0, "zero"},
			{1, "one"},
			{2, "two"}
	};
	assert(join(m, ';') == "(0, zero);(1, one);(2, two)");

}
// end test print section
// end printting function section

int main(int argc, char *argv[]){
	test_print_pair();
	test_join();
	test_print_vector();
	test_print_map();
	return 0;
}

