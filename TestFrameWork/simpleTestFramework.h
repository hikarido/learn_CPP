//
// Created by hikarido on 6/24/18.
// Простой тестовый фреймворк
// Использование
//
//
//


#ifndef ALLTOSQUARE_SIMPLETESTFRAMEWORK_H
#define ALLTOSQUARE_SIMPLETESTFRAMEWORK_H

#include <sstream>
#include <exception>
#include <string>
#include <ostream>

#include "printFramework.h"

using std::ostringstream;
using std::runtime_error;
using std::string;
using std::endl;
using std::cerr;

const string pass_correct = "PASS";
const string pass_failed = "FAILED";

/**
 * Проверка на эквивалентность двух выражений
 * Ожидается, что expect == exist, если это не  так то выполняется оповещение о том, то
 * ожидание расходится с реальностью
 * @tparam Expect must have oprator !=
 * @tparam Exist  must have operator !=
 * @param expect значение ожидаемое
 * @param exist значение предоставленное, в сравнение к ожижаемому
 * @param hint std::string unique description for more detalisation, default = "NONE"
 *
 * Бросает исключение std::runtime_error если тест выстрелил
 */
template<typename Expect, typename Exist>
void AssertEqual(const Expect & expect, const Exist & exist, const string & hint = "NONE"){
	if(expect != exist){
		ostringstream ost;
		ost << " "<< expect << " != " << exist << " HINT: " << hint<< endl;
		throw runtime_error(ost.str());
	}
};

/**
 * Замена для стандартного assert
 * ожидается что expect_true == true
 * если это не так то возбуждается исключение и отрабатывает вывод инфррмации
 * о расхождении с ожидаемым результатом
 * @param expect_true bool результат выполнения какого либо выражения
 * @param hint string уникальное название теста выводится в блоке HINT, default = "NONE"
 *
 * Бросае исключение std::runtime_error если тест выстрелил
 */
void Assert(bool expect_true, const string & hint = "NONE"){
	AssertEqual(expect_true, true, hint);
}

/**
 * Среда для запуска тестовых функций
 * Ловит исключения при выстреле тестов и позволяет выполнить все тесты
 * Что бы определить совокупность рабочего и не рабочего кода согласно тестам
 * @tparam FunctionAgregatedTestFunction некая функция которая в себе исполняет одну и более тестовых функций
 * @param test тестовая функци
 * @param test_name std::string имя теста
 */
template<typename FunctionAgregatedTestFunction>
void RunTest(FunctionAgregatedTestFunction test, const string & test_name){
	try{
		test();
		cerr << "Test " << test_name << " " << pass_correct << endl;
	} catch(runtime_error & test_exception){
		cerr << "Test " << test_name << " " << pass_failed << " " << test_exception.what();
	}
}




#endif //ALLTOSQUARE_SIMPLETESTFRAMEWORK_H
