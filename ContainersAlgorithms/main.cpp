//
// Created by hikarido on 6/28/18.
// Немного экспериментов с std

#include <iostream>
#include <chrono>
#include <vector>
#include <iterator>
#include <algorithm>
#include <deque>
#include <string>
#include <random>
#include <map>
#include <iomanip>
#include <set>
#include <cassert>
#include <locale>

using namespace std;

template<typename Collection>
void printCollection(const Collection & c){
	cout << '{';
	for(const auto  & a: c){
		cout << a << ',';
	}
	cout << '}';
}
/**
 * Некоторые тесты вектора
 */
void vector_growing(){
//	{
//		vector<int> v;
//		printCollection(v);
//		cout << v.size() << endl;
//		v.resize(34);
//		printCollection(v);
//		cout << v.size() << endl;
//		cout << v.capacity() << endl;
//		v.push_back(1);
//		cout << v.capacity() << endl;
//		printCollection(v);
//	}
//	{
//		vector<int> vec;
//		printCollection(vec);
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.push_back(1);
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.push_back(1);
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.push_back(1);
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.push_back(1);
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.push_back(1);
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.push_back(1);
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.push_back(1);
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.push_back(1);
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.push_back(1);
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.pop_back();
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.pop_back();
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.pop_back();
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.pop_back();
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.pop_back();
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.pop_back();
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.pop_back();
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.pop_back();
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.pop_back();
//		cout << vec.size() << ' ' << vec.capacity() << endl; // zero size
//// боль начинается вот тут
//		vec.pop_back();
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//		vec.pop_back();
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//// а вот тут простреливается нога
//		vec.push_back(1);
//		cout << vec.size() << ' ' << vec.capacity() << endl;
//	}

	{
		auto start = chrono::system_clock::now();
		vector<int> v;
		v.resize(100000);
		while(v.size() != 0){
			v.erase(v.begin());
		}
		auto stop = chrono::system_clock::now();
		chrono::duration<double> time_point = stop - start;
		cout << time_point.count() <<  " seconds" << endl;

		{
			start = chrono::system_clock::now();
			deque<int> d;
			d.resize(100000);
			while(d.size() != 0){
				d.pop_front();
			}
			stop = chrono::system_clock::now();
			time_point = stop - start;
			cout << time_point.count() << " seconds" << endl;
		}
	}
}

void string_exp(){
	string s = "some string which contains spaces";

	for(auto it = find(s.cbegin(), s.cend(), ' ');
			it != s.cend();
			it = find(next(it), s.cend(), ' ')){
		cout << it - s.cbegin() << endl;
	}

}


void  vector_algo(){
//	{
//		vector<int> v;
//		std::random_device dv{};
//		std::mt19937 gen{dv()};
//
//		map<int, int> hist;
//
//		std::normal_distribution<> distr{0, 5};
//		for(int i = 0; i < 100000; ++i){
//			++hist[round(distr(gen))];
//		}
//
//		for(auto & p: hist){
//			cout << setw(2) << p.first << ' ' <<  string(p.second/100, '*') << endl;
//		}
//	}

//	{
//		vector<int> v = {1,1,2,5,6,7,7,7,8,9,11,11};
//		printCollection(v);
//
//		cout << endl << boolalpha << is_sorted(v.begin(), v.end()) << endl;
//		cout << binary_search(v.begin(), v.end(), 99) << endl;
//		cout << (lower_bound(v.begin(), v.end(), 4) - v.begin()) << endl;
//		printCollection(v);
//		cout << "in vector 7 occurs: " << abs(distance(upper_bound(v.begin(), v.end(), 7), lower_bound(v.begin(), v.end(), 7)))
//			 << " times" << endl;
//
//		vector<int>::iterator lover, upper;
//		tie(lover, upper) = equal_range(v.begin(), v.end(), 7);
//		cout << "\n times: " << upper - lover << endl;
//
//		for(auto cur_it = lover; cur_it != upper; ++cur_it){
//			cout << *cur_it << endl;
//		}
}

void set_pain(){
	{
		set<int> s = {1,2,3,4,4,5};
		set<int>::iterator low, up;
		tie(low, up) = s.equal_range(3);
		if(low != s.end())
		{
			cout << *low << endl;
			cout << *up << endl;
		}
	}

	{
		set<int> s = {1,2,3,4,5,7};
		set<int>::iterator up, down;
		tie(down, up) = equal_range(s.cbegin(), s.cend(), 123);
		assert(down == s.end());
		assert(up == s.end());

		tie(down, up) = equal_range(s.begin(), s.end(), -12);
		assert(down == s.begin());
		assert(up == s.begin());
		tie(down, up) = equal_range(s.cbegin(), s.cend(), 6);

		assert(s.find(6) == s.end());
	}

	{
		set<int> s = {1,2,3};
		set<int> s1{s};
		s.erase(2);
		printCollection(s);
		printCollection(s1);

//		be aware!
//		cout << endl << *max_element(s.begin(), s1.end()) << endl;


	}

	{
		set<int> s;
		auto it = max_element(s.cbegin(), s.cend());
		if(it == s.cend()){
			cout << '!' << endl;
		}

		if(it == s.cbegin()){
			cout << "!!" << endl;
		}
	}
}

void unicode_to_console(){
	{
		locale::global(locale(""));
		wstring s = L"Привет";
		wcout << s << endl;
	}

	wstring phrase = L"ДА это был долгий путь";
	size_t pos = phrase.find(L"долгий");
	if(pos != wstring::npos){
		size_t pos_end_space = phrase.find(L' ', pos);
		if(pos_end_space != wstring::npos){
			wcout << pos_end_space << endl;
		}
		phrase.replace(pos, pos_end_space - pos, L"Быстрый");
		wcout << phrase << endl;
	}
}

int main(){
//	vector_growing();
//	string_exp();
//	vector_algo();
	set_pain();
//	unicode_to_console();
	return 0;
}
