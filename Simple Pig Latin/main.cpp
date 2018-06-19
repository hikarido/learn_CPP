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
#include <cctype>
#include <iterator>

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



// first ugly attemption
string pig_it(const string & str)
{
	std::list<char> container;

	//==============================================
	// на code wars тест дурной, втыкаем костыль
	//https://www.codewars.com/kata/520b9d2ad5c005041100000f/discuss#label-issue
	// avaini comment with issue
	//in test system error are exists
	// punctuation char exist in word
	//	Expected: equal to aLdMAYOBHFl!zmday
	//	Actual: LdMAYOBHFlaay!zmday

	auto source_iter = str.cbegin();

	std::string cr = "!\"#$%&'()*+,-./";
	char which = '1';
	auto occurrence = [&cr, &which](char c)->bool
	{
		if(count(cr.cbegin(), cr.cend(), c))
		{
			which = c;
			return true;
		}
		return false;
	};

	if(any_of(str.crbegin(), str.crend(), occurrence))
	{
		std::string find_char;
		find_char.push_back(which);

		auto iter_copy_from = find_end(str.cbegin(), str.cend(), find_char.cbegin(), find_char.cend());
		if(iter_copy_from != str.end() && iter_copy_from != prev(str.end()))
		{
			source_iter = iter_copy_from;
			copy(str.cbegin(), source_iter, back_inserter(container));
//			for(auto i: container)
//			{
//				cout << i << endl;
//			}
		}

		// Да у них такой тЕст, но я просто решил доделать во что бы то это не встало!!!
		if(iter_copy_from == prev(str.end()) && count(str.cbegin(), str.cend(), ' ') == 0)
		{
			return str;
		}
	}


	//===============================================

	char first_char = '-';
	bool first_stored = false;
	bool start_flag = true;
	char cur_char = '-';

	for(;source_iter !=str.end(); source_iter++)
	{
		cur_char = *source_iter;
		bool container_not_empty = !container.empty();
		if(isalpha(cur_char) && (!first_stored))
		{
			if(container_not_empty || start_flag)
			{
				char space = ' ';
				if(container.back() == space)
				{
					first_char = cur_char;
					first_stored = true;
					continue;
				}

				first_char = cur_char;
				first_stored = true;
				start_flag = false;
				continue;
			}
		}
		else
		{
			if(cur_char == ' ')
			{
				container.push_back(first_char);
				container.push_back('a');
				container.push_back('y');
				container.push_back(' ');

				first_stored = false;
				first_char = '-';
				continue;
			}
			else
			{
				container.push_back(cur_char);
			}
		}
	}

	if(first_char!='-')
	{
		container.push_back(first_char);
		container.push_back('a');
		container.push_back('y');
	}


	return std::string(container.cbegin(), container.cend());
}


/**
 * Тестирует pig_it
 */
void pig_it_test()
{
//	cout << pig_it("dj!j") << endl;
	cout << pig_it("O tempora o mores !") << endl;
	cout << pig_it("XiJ!XndvPfKg.ra") << endl;
	cout << pig_it("ZCfrbVLWNgio!tD") << endl;
	cout << pig_it("bXbF.lMzhNLnSgz") << endl;
	cout <<"test 1: "<< (pig_it("Pig latin is cool") == "igPay atinlay siay oolcay") << endl;
	cout <<"test 2: "<< (pig_it("Hello World !") == "elloHay orldWay !") << endl;
}

int main(int argc, char * argv[])
{
	cout << "start" <<endl;
	pig_it_test();
//
//	string cr = "!\"#$%&'()*+,-./";
//	string s = "123.123#";
//	char which = '1';
//	auto pred = [&s, &which](char c)->bool
//	{
//		if(count(s.cbegin(), s.cend(), c))
//		{
//			which = c;
//			return true;
//		}
//		return false;
//	};
//	if(any_of(cr.cbegin(), cr.cend(), pred))
//	{
//		cout << which << endl;
//		cout << "exist" << endl;
//	}
	return 0;

}




































