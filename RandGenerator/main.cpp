#include <iostream>
#include <cassert>
#include "Generator.hpp"

using namespace std;

void Generator_test()
{
    cout << "Generator_test(); passing"<<endl;
    Generator g{};
    assert(g.shift == 0);
    assert(g.node == 0);

    g.next_shift();assert(g.shift == 1);
    g.next_shift();assert(g.shift == 2);
    g.next_shift();assert(g.shift == 3);
    g.next_shift();assert(g.shift == 4);
    g.next_shift();assert(g.shift == 5);
    g.next_shift();assert(g.shift == 0);




}

int main()
{

    Generator g{};
    g.print();

    Generator_test();
    return 0;
}

