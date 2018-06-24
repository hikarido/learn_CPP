//
// Created by hikarido on 6/24/18.
//

#ifndef ALLTOSQUARE_SIMPLETESTFRAMEWORK_H
#define ALLTOSQUARE_SIMPLETESTFRAMEWORK_H

#include <sstream>
#include <exception>
#include <string>

using std::ostringstream;
using std::runtime_error;
using std::string;
using std::endl;

/**
 * Проверка на эквивалентность двух выражений
 * @tparam Expect must have oprator !=
 * @tparam Exist  must have operator !=
 * @param expect значение ожидаемое
 * @param exist значение предоставленное, в сравнение к ожижаемому
 * @param hint std::string unique description for more detalisation, default = NONE
 */
template<typename Expect, typename Exist>
void AssertEqual(const Expect & expect, const Exist & exist, const string & hint = "NONE"){
	if(expect != exist){
		ostringstream ost;
		ost << "Assertation failed: " << expect << " != " << exist << " HINT: " << hint<< endl;
		throw runtime_error(ost.str());
	}
};


#endif //ALLTOSQUARE_SIMPLETESTFRAMEWORK_H
