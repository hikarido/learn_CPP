#ifndef BRACE_BALANCE_TEST_HPP
#define BRACE_BALANCE_TEST_HPP

#include<iostream>
#include <cassert>
#include <string>
#include <exception>
#include"BraceBalance.hpp"

using std::cout;
using std::endl;
using std::string;


class BraceBalanceTest
{
public:
    BraceBalanceTest()
    {
        cout << "test 1 passing" << endl;
        test_1();
        cout << "is close test passing" << endl;
        is_close_test();
    }

    ~BraceBalanceTest() = default;

    void test_1()
    {


    }

    void is_close_test()
    {
        BraceBalance bb{};
        string all_close = "]})";

        assert(bb.is_close('}') == true);

    }
};

#endif
