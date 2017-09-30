#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

/*
Тестовое задание:
Необходимо реализовать функцию.

Прототип функции:
void join (const std::vector< int > &from, std::vector< int > &to);

Она должна принимать два отсортированных вектора (отсортированность
принимается на веру - проверять не нужно, порядок - по возрастанию).
На выходе вектор from не изменяется, а вектор to содержит все элементы
из обоих, так же расположенных в порядке возрастания.
*/

/**
 * @brief print
 * print iterable sequence on screen
 * @param vec iterable sequence
 *
 */
void print(auto &vec)
{
    cout<<"[";
    for(auto &i: vec)
    {
        cout << i <<" ";
    }
    cout<<"]"<<endl;
}

/**
 * @brief join
 * performe merging of sorted sequences from and to into one container.
 * Result will placed into param @see to
 * @param from
 * @param to
 */
void join(const std::vector<int> &from, std::vector<int> &to)
{
    //perform merge vec from into vec to
    //if vec to can store itself and vec from
    if(to.capacity() >= to.size() + from.size())
    {
        size_t old_to_size = to.size();
        to.resize(to.size()+from.size());
        vector<int>::iterator middle = copy(from.cbegin(), from.cend(), to.begin()+old_to_size);
        inplace_merge(to.begin(), middle, to.end());
    }

    //othercase create new vector and assign it on ref to
    vector<int> res(to.size()+from.size());
    merge(from.begin(), from.end(),
         to.begin(), to.end(), res.begin());
    to = move(res);
}

/**
 * @brief join_test
 * test for join function
 */
void join_test()
{
    cout<<"begin join test:"<<endl;

    vector<int> from{1,2,3,5};
    vector<int> to{-10, -9, -9, -8};
    join(from, to);
    vector<int> test = {-10, -9, -9, -8, 1, 2, 3, 5};
    assert(equal(to.cbegin(), to.cend(), test.cbegin()) == true);

    from = {-1,-2,-3,-4,-5};
    to = {1,2,3,4};
    join(from, to);
    test = {-1, -2, -3, -4, -5, 1, 2, 3, 4};
    assert(equal(to.cbegin(), to.cend(), test.cbegin()) == true);

    from = {-1, 2, 3, 4};
    to = {-5, -4, -3, 5, 6, 7};
    join(from, to);
    test = {-5, -4, -3, -1, 2, 3, 4, 5, 6, 7};
    assert(equal(to.cbegin(), to.cend(), test.cbegin()) == true);

    from = {-5, -4, -3, 5, 6, 7};
    to = {-1, 2, 3, 4};
    join(from, to);
    test = {-5, -4, -3, -1, 2, 3, 4, 5, 6, 7};
    assert(equal(to.cbegin(), to.cend(), test.cbegin()) == true);

    from = {};
    to = {};
    join(from, to);
    test = {};
    assert(equal(to.cbegin(), to.cend(), test.cbegin()) == true);

    from = {1};
    to = {};
    join(from, to);
    test = {1};
    assert(equal(to.cbegin(), to.cend(), test.cbegin()) == true);

    from = {};
    to = {1};
    join(from, to);
    test = {1};
    assert(equal(to.cbegin(), to.cend(), test.cbegin()) == true);
    cout<<"End join test: all tests passed"<<endl;
}

int main()
{

    join_test();
    return 0;
}

