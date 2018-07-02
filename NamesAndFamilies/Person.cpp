//
// Created by hikarido on 7/2/18.
//


#include "Person.h"

using std::map;
using std::string;

void Person::changeFirstName(int year, const string &name) {
	first_name_history[year] = name;
}

void Person::changeLastName(int year, const string &name) {
	last_name_history[year] = name;
}

string Person::getFullName(int year) const {
	return "testing";
}

