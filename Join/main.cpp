#include <iostream>
#include <vector>
#include <algorithm>

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

int main()
{
    vector<int> a = {1,2,3, 1100, 2344};
    vector<int> b = {23,24,25};


    cout<<"before"<<endl;
    print(a);
    print(b);
    join(b, a);

    cout<<"after"<<endl;
    print(a);
    print(b);



    cout << endl;



    return 0;
}

