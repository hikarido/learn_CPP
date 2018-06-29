//
// Created by hikarido on 6/30/18.
//

#ifndef NEAREST_COURSERANEARESTTASK_H
#define NEAREST_COURSERANEARESTTASK_H

/*
 * Задача:
 * Тренировочное задание по программированию: Поиск ближайшего элемента
 * Напишите функцию FindNearestElement, для множества целых чисел numbers и
 * данного числа border возвращающую итератор на элемент множества,
 * ближайший к border. Если ближайших элементов несколько, верните итератор на наименьший из них.
 *
 * Example:
 * int main() {
 *set<int> numbers = {1, 4, 6};
 * cout <<
 *     *FindNearestElement(numbers, 0) << " " <<
 *     *FindNearestElement(numbers, 3) << " " <<
 *     *FindNearestElement(numbers, 5) << " " <<
 *     *FindNearestElement(numbers, 6) << " " <<
 *     *FindNearestElement(numbers, 100) << endl;
 * set<int> empty_set;
 * cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
 * return 0;
 *}
 *
 *RESULT:
 *line 1: 1 4 4 6 6
 *line 2: 1
 *
 */

/**
 *
 * @param numbers set
 * @param border
 * @return итератор на подходящий элемено или numbers.end() если такого нет
 */
set<int>::const_iterator FindNearestElement(
		const set<int>& numbers,
		int border);

#endif //NEAREST_COURSERANEARESTTASK_H
