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

void join_test()
{
    vector<int> from{1,2,3,5};
    vector<int> to{-10, -9, -9, -8};
    join(from, to);
    vector<int> test = {-10, -9, -9, -8, 1, 2, 3, 5};
    assert(equal(to.cbegin(), to.cend(), test.cbegin()) == true);
}s

int main()
{

    join_test();
    return 0;
}

