//
// Created by hikarido on 6/30/18.
//
#include "pchheader.h"

using std::set;
using std::lower_bound;
using std::prev;

#include "CourseraNearestTask.h"

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
	const auto  first_no_less = lower_bound(numbers.cbegin(), numbers.cend(), border);

	// проверка на пустой и на то, что нащ ближайший это первый
	if(first_no_less == numbers.cbegin()){
		return first_no_less;
	}

	// теперь в нашем множестве по крайней мере один элемент
	// если frist_no_less отсвутствует, то вернём перый перед end
	const auto last_less = prev(first_no_less);
	if(first_no_less == numbers.end()){
		return last_less;
	}

	// в данном случае оталось только расчитать ближайший элмент
	// border точно находтся между двумя существующими элементами
	bool is_left = ((border - *last_less) <= (*first_no_less - border));
	return is_left ? last_less: first_no_less;


}


