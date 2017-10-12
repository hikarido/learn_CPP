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


}

int main()
{

    Generator g{};
    g.print();

    Generator_test();
    return 0;
}

