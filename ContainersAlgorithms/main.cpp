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
int main(){
	vector_growing();
	string_exp();
	return 0;
}
