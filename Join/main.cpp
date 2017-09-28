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


void print(auto &vec)
{
    cout<<"[";
    for(auto &i: vec)
    {
        cout << i <<" ";
    }
    cout<<"]"<<endl;
}


void join(const std::vector<int> &from, std::vector<int> &to)
{
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

    cout<<"End join test: all tests passed"<<endl;
}

int main()
{

    join_test();
    return 0;
}

