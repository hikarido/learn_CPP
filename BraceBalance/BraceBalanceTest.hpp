#ifndef BRACE_BALANCE_TEST_HPP
#define BRACE_BALANCE_TEST_HPP

#include<iostream>
#include <cassert>
#include"BraceBalance.hpp"

using std::cout;
using std::endl;


class BraceBalanceTest
{
public:
    BraceBalanceTest()
    {
        cout << "test 1 passing" <<endl;
        test_1();
    }

    ~BraceBalanceTest() = default;

    void test_1()
    {


    }
};

#endif
