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

        cout << "is close test passing" << endl;
        is_close_test();
        cout << "is open test passing" << endl;
        is_open_test();
        cout << "open close correct passing" << endl;
        is_correct_pair();
        cout << "test balance passing" << endl;
        test_balance();
    }

    ~BraceBalanceTest() = default;

    void test_balance()
    {
        BraceBalance bb{};

        //true positive
        assert(bb.check("") == true);
        assert(bb.check(" ") == true);
        assert(bb.check("1+2") == true);

        assert(bb.check("[]") == true);
        assert(bb.check("[]") == true);
        assert(bb.check("{}") == true);
        assert(bb.check("()") == true);

        assert(bb.check("[[]]") == true);
        assert(bb.check("[{}]") == true);
        assert(bb.check("[()]") == true);

        assert(bb.check("([])") == true);
        assert(bb.check("({})") == true);
        assert(bb.check("(())") == true);

        assert(bb.check("{[]}") == true);
        assert(bb.check("{()}") == true);
        assert(bb.check("{{}}") == true);

        assert(bb.check("[{}()[]]") == true);
        assert(bb.check("{{}[]()}") == true);
        assert(bb.check("([]{}())") == true);

        assert(bb.check("^{John^}^{Tom^}") == true);
        assert(bb.check("^{John^}^{Tom^} ^{Smith^}^{Jones^}") == true);
        assert(bb.check("%^([a-z]+^) ^([a-z]+^), ^(*^), ^(*^), ^(*^), ^([0-9]+^)") == true);
        assert(bb.check("([a-z 0-9.,]++^)^pcity = ^([a-z]+^)^pstate = ^([a-z]+^)^pzip = ^([0-9^-]+^)") == true);
        assert(bb.check("[123]!@34$%^&*()") == true);


        //false positive
        assert(bb.check("[") == false);
        assert(bb.check("]") == false);
        assert(bb.check("{") == false);
        assert(bb.check("}") == false);
        assert(bb.check("(") == false);
        assert(bb.check(")") == false);

        assert(bb.check("((") == false);
        assert(bb.check("))") == false);
        assert(bb.check(")(") == false);

        assert(bb.check("{{") == false);
        assert(bb.check("}}") == false);
        assert(bb.check("}{") == false);

        assert(bb.check("[[") == false);
        assert(bb.check("]]") == false);
        assert(bb.check("][") == false);

        //balansed but position error
        assert(bb.check("[(])") == false);
        assert(bb.check("[{]}") == false);

        //assert(bb.check("") == false);

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

    void is_correct_pair()
    {
        BraceBalance bb{};
        assert(bb.open_close_correct('{','}') == true);
        assert(bb.open_close_correct('[',']') == true);
        assert(bb.open_close_correct('(',')') == true);

        assert(bb.open_close_correct('{',']') == false);
        assert(bb.open_close_correct('{',')') == false);

        assert(bb.open_close_correct('[','}') == false);
        assert(bb.open_close_correct('[',')') == false);

        assert(bb.open_close_correct('(',']') == false);
        assert(bb.open_close_correct('(','}') == false);

        //other character pairs
        //lower lower
        for(char i: chars_lower)
            for(auto end = chars_lower.cend() - 1;
                end != chars_lower.cbegin();
                end--)
            {
                assert(bb.open_close_correct(i,*end) == false);
            }

        //upper upper
        for(char i: chars_upper)
            for(auto end = chars_upper.cend() - 1;
                end != chars_upper.cbegin();
                end--)
            {
                assert(bb.open_close_correct(i,*end) == false);
            }

        //upper and lower
        for(char i: chars_upper)
            for(auto end = chars_lower.cend() - 1;
                end != chars_lower.cbegin();
                end--)
            {
                assert(bb.open_close_correct(i,*end) == false);
            }
    }

    string opens = "[({";
    string closes = "]})";
    string chars_lower = "qwertyuiopasdfghjklzxcvgnm";
    string chars_upper = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string numbers = "1234567890";
};

#endif
