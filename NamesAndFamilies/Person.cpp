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
	string first_name_in_year = searchChangesInYear(year, first_name_history);
	string last_name_int_year = searchChangesInYear(year, last_name_history);
	string full_name = generateOutputString(first_name_in_year, last_name_int_year);

	return full_name;
}

std::string Person::searchChangesInYear(int year, const std::map<int, std::string> &names) const {
	auto it = names.upper_bound(year);
	string name = empty_text_value;
	if(it != names.cbegin()){
		return (--it)->second;
	}

	return name;

}

std::string Person::generateOutputString(const std::string &first_name, const std::string &last_name) const {
	bool first_name_changed = first_name == empty_text_value? false: true;
	bool last_name_changed = last_name == empty_text_value? false: true;

	if(!first_name_changed && !last_name_changed){
		return "Incognito";
	}
	else if(!first_name_changed && last_name_changed){
		return last_name + " with unknown first name";
	}
	else if(first_name_changed && !last_name_changed){
		return first_name + " with unknown last name";
	}
	else{
		return first_name + ' ' + last_name;
	}
}
