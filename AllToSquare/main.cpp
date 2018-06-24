//
// Created by hikarido on 6/24/18.
// Программа возводящая переданный аргумент в квадрат

#include <iostream>

#include "print_utils.cpp"
#include "test_power_and_multiplying.cpp"

using namespace std;

int main(int argc, char *argv[]){
	cout << test_power_and_multiply() << endl;
	execute_test_printing_section();
	return 0;
}

