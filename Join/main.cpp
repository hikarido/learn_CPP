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
        cout <<"brunch A"<<endl;
        vector<int>::iterator old_end = to.end();
        to.resize(to.size()+from.size());
        copy(from.cbegin(), from.cend(), old_end);
        inplace_merge(to.begin(), old_end, to.end());
        return;
    }

    //othercase create new vector and assign it on ref to
    cout << "Brunch B"<<endl;
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
    cout << "test 0"<<endl;
    vector<int> from{1,2,3,5};
    vector<int> to{-10, -9, -9, -8};
    join(from, to);
    vector<int> test = {-10, -9, -9, -8, 1, 2, 3, 5};
    assert(equal(to.cbegin(), to.cend(), test.cbegin()) == true);

    cout << "test 1"<<endl;
    from = {-1,-2,-3,-4,-5};
    to = {1,2,3,4};
    join(from, to);
    test = {-1, -2, -3, -4, -5, 1, 2, 3, 4};
    assert(equal(to.cbegin(), to.cend(), test.cbegin()) == true);

    cout << "test 2"<<endl;
    from = {-1, 2, 3, 4};
    to = {-5, -4, -3, 5, 6, 7};
    join(from, to);
    test = {-5, -4, -3, -1, 2, 3, 4, 5, 6, 7};
    assert(equal(to.cbegin(), to.cend(), test.cbegin()) == true);

    cout << "test 3"<<endl;
    cout << "=======test======="<<endl;
    from = {-5, -4, -3, 5, 6, 7};
    to = {-1, 2, 3, 4};
    cout << to.size()<<endl;
    cout << from.size()<< endl;
    cout << to.capacity() << endl;
    join(from, to);
    test = {-5, -4, -3, -1, 2, 3, 4, 5, 6, 7};
    print(to);
    cout << to.size()<<endl;
    assert(equal(to.cbegin(), to.cend(), test.cbegin()) == true); //<-- this test was errornous
    cout << "=======end_test======="<<endl;

    cout << "test 4"<<endl;
    from = {};
    to = {};
    join(from, to);
    test = {};
    assert(equal(to.cbegin(), to.cend(), test.cbegin()) == true);

    cout << "test 5"<<endl;
    from = {1};
    to = {};
    join(from, to);
    test = {1};
    assert(equal(to.cbegin(), to.cend(), test.cbegin()) == true);

    cout << "test 6"<<endl;
    from = {};
    to = {1};
    join(from, to);
    test = {1};
    assert(equal(to.cbegin(), to.cend(), test.cbegin()) == true);

    cout << "test 7"<<endl;
    from = {1,2,3,4,5,6,7,8,9,10};
    to.reserve(100);
    to = {1,2,3};
    join(from, to);
    test = {1,1,2,2,3,3,4,5,6,7,8,9,10};
    print(to);
    assert(equal(to.cbegin(), to.cend(), test.cbegin()) == true);


    cout<<"End join test: all tests passed"<<endl;
}

int main()
{

    join_test();
    return 0;
}

