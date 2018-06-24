//
// Created by hikarido on 6/24/18.
// Простой тестовый фреймворк
// Использование
// Создавайте свои тесты в виде функций
// тестовые функции должны использовать Assert and EqualAssert
// запускайте тестовые функции по средствам TestRunner.RunTest
// наслаждайтесь.
// Возможна не корректная работа при выводе ошибок ознакомьтесь с возможностями printFramework.h


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
 * Класс для выполнения тестирования
 * используйте RunTest для запуска функций использующих Assert and EqualAssert
 * @see RunTest for details
 *
 * При унитожении выводит статитику тестирования
 *
 * EXAMPLE:
 *
CODE:

 	#include "simpleTestFramework.h"

	void test_1(){
		Assert(1 == 2, "lustig test 1");
	}

	void test_map_equals(){
		std::map<pair<int, int>, vector<int>> m = {{{1,2}, {1,2,3}}};
		decltype(m) ans_m = {{{1,2}, {1,3,5}}};
		AssertEqual(m, ans_m, "data structures in test");
	}

	void correct_test(){
		Assert(true, "yes that is");
	}
	void testAll(){
		TestRunner tr{};
		tr.RunTest(test_1, "test_1");
		tr.RunTest(test_map_equals, "test_map_equals");
		tr.RunTest(correct_test, "correct_test");
	}
	int main(){
		testAll();
		return 0;
	}

 OUTPUT:
 	Test test_1 FAILED  0 != 1 HINT: lustig test 1
	Test test_map_equals FAILED  {((1, 2), [1,2,3])} != {((1, 2), [1,3,5])} HINT: data structures in test
	Test correct_test PASS

	DEFAULT TESTER:
	PASS: 3
	FAILED: 2
 *
 *
 */
class TestRunner{

public:

	explicit TestRunner(const string & name){
		if(name.size() != 0){
			this->name = name + " TESTER";
		}
	}

	explicit TestRunner() = default;

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
			test_count += 1;
			test();
			cerr << "Test " << test_name << " " << pass_correct << endl;
		} catch(runtime_error & test_exception){
			failed_tests_count += 1;
			cerr << "Test " << test_name << " " << pass_failed << " " << test_exception.what();
		}
	}

	~TestRunner(){
		if(failed_tests_count > 0){
			cerr << endl << name << ": " << endl << pass_correct << ": " << test_count << endl << pass_failed << ": " << failed_tests_count << endl;
			exit(1);
		}else{
			cerr << endl << name << ": "<< endl << "All ok!" << endl;
		}
	}

private:
	int failed_tests_count = 0;
	int test_count = 0;
	string name = "DEFAULT TESTER";
};




#endif //ALLTOSQUARE_SIMPLETESTFRAMEWORK_H
