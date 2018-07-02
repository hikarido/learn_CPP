//
// Created by hikarido on 7/2/18.
//

#ifndef NEAREST_PERSON_H
#define NEAREST_PERSON_H

#include <string>
#include <map>

class Person {
public:
	explicit Person() = default;
	~Person()= default;
	void changeFirstName(int year, const std::string & name);
	void changeLastName(int year, const std::string & name);
	std::string getFullName(int year) const;

private:
	std::map<int, std::string> first_name_history;
	std::map<int, std::string> last_name_history;
	std::string empty_text_value = "";
	std::string searchChangesInYear(int year, const std::map<int, std::string> & names) const;
	std::string generateOutputString(const std::string & first_name,const std::string & last_name) const;
};


#endif //NEAREST_PERSON_H
