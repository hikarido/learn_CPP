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
        cout << "is open test passing" << endl;
        is_open_test();
    }

    ~BraceBalanceTest() = default;

    void test_1()
    {


    }

    void is_close_test()
    {
        BraceBalance bb{};

        assert(bb.is_close('}') == true);
        assert(bb.is_close('{') == false);

        assert(bb.is_close(']') == true);
        assert(bb.is_close('[') == false);

        assert(bb.is_close(')') == true);
        assert(bb.is_close('(') == false);

        for(char i: opens)
            assert(bb.is_close(i) == false);

        for(char i: closes)
            assert(bb.is_close(i) == true);

        for(char i: chars_lower)
            assert(bb.is_close(i) == false);

        for(char i: chars_upper)
            assert(bb.is_close(i) == false);

        for(char i: numbers)
            assert(bb.is_close(i) == false);

    }

    void is_open_test()
    {
        BraceBalance bb{};

        assert(bb.is_open('}') == false);
        assert(bb.is_open('{') == true);

        assert(bb.is_open('[') == true);
        assert(bb.is_open(']') == false);

        assert(bb.is_open('(') == true);
        assert(bb.is_open(')') == false);

        for(char i: opens)
            assert(bb.is_open(i) == true);

        for(char i: closes)
            assert(bb.is_open(i) == false);

        for(char i: chars_lower)
            assert(bb.is_open(i) == false);

        for(char i: chars_upper)
            assert(bb.is_open(i) == false);

        for(char i: numbers)
            assert(bb.is_open(i) == false);

    }

    string opens = "[({";
    string closes = "]})";
    string chars_lower = "qwertyuiopasdfghjklzxcvgnm";
    string chars_upper = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string numbers = "1234567890";
};

#endif
