//
// Created by hikarido on 6/19/18.
//
/*
 * Task from https://www.codewars.com/kata/simple-pig-latin
 */

#include <string>
#include <algorithm>
#include <iostream>
#include <list>
#include <cctype

using namespace std;

/*
 * Производит:
 * преобразование все слов строки source по следующему правилу
 * - первую букву слова ставит в конец слова
 * - в конце слова после перемещенной первой буквы ставит ay
 * Знаки пунктуации остаются не изменными
 *
 * Examples:
 * pigIt('Pig latin is cool'); // igPay atinlay siay oolcay
 * pigIt('Hello world !');     // elloHay orldWay !
 */
string pig_it(const string & source)
{
	std::list<char> container;
	char first_char = '-';

	for(const char cur_char: source)
	{
		bool is_alpha = static_cast<bool>(isalpha(cur_char));
		if(!is_alpha)
		{
			//TODO: Доделать
		}
	}

	return "";
}

/**
 * Тестирует pig_it
 */
void pig_it_test()
{
	cout <<"test 1: "<< (pig_it("Pig latin is cool") == "igPay atinlay siay oolcay") << endl;
	cout <<"test 2: "<< (pig_it("Hello world !") == "elloHay orldWay !") << endl;
}

int main(int argc, char * argv[])
{
	cout << "start" <<endl;
	pig_it_test();
	return 0;
}

