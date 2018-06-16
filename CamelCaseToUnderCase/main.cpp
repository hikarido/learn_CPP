#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>
#include <list>
#include <iterator>

using namespace std;

/**
 * task from http://www.codewars.com/kata/camelcase-to-underscore/cpp
 * Производит преобразование строки from из CamelCase в under_case
 * Примеры:
 * "Calculate15Plus5Equals20" => "Calculate_15_Plus_5_Equals_20"
 * "This_Is_Already_Splitted_Correct" => "This_Is_Already_Splitted_Correct"
 * "ThisIs_Not_SplittedCorrect" => "This_Is_Not_Splitted_Correct"
 * "_UnderscoreMarked_Test_Name_" => _Underscore_Marked_Test_Name_"
 *
 * @param from строка символов ascii
 * @return строка from переведенная в under_case
 */
string camel_case_to_under_case(const string & from)
{
	list<char> in_under_case;
	bool current_char_is_upper = false;
	bool current_char_is_digit = false;

	for(int i = 0; i < from.size(); ++i)
	{
		current_char_is_upper = static_cast<bool>(isupper(from[i]));
		current_char_is_digit = static_cast<bool>(isdigit(from[i]));

		if(in_under_case.size() == 1 || in_under_case.size() == 0)
		{
			if(current_char_is_upper)
			{
				in_under_case.push_back(from[i]);
				continue;
			}
		}

		if(current_char_is_upper)
		{
			if(from[i-1] != '_')
			{
				in_under_case.push_back('_');
				in_under_case.push_back(from[i]);
				continue;
			}

			in_under_case.push_back(from[i]);
			continue;
		}

		if(current_char_is_digit)
		{
			if(in_under_case.back() == '_')
			{
				in_under_case.push_back(from[i]);
				continue;
			}
			else if(in_under_case.back() != '_' && static_cast<bool>(isdigit(in_under_case.back()) == false))
			{
				in_under_case.push_back('_');
				in_under_case.push_back(from[i]);
				continue;
			}

		}

		in_under_case.push_back(from[i]);
	}

	string s;
	s.resize(in_under_case.size());
	copy(begin(in_under_case), end(in_under_case), s.begin());
	return s;
}


int main() {
	map<string, string> tests;
	tests["Calculate15Plus5Equals20"] = "Calculate_15_Plus_5_Equals_20";
	tests["This_Is_Already_Splitted_Correct"] = "This_Is_Already_Splitted_Correct";
	tests["ThisIs_Not_SplittedCorrect"] = "This_Is_Not_Splitted_Correct";
	tests["_UnderscoreMarked_Test_Name_"] = "_Underscore_Marked_Test_Name_";
	string res;

	for(auto & i: tests)
	{
		res = camel_case_to_under_case(i.first);
		cout << "test: " << i.first <<" is ok: " << std::boolalpha << (res == i.second) << endl;

	}
	return 0;
}
