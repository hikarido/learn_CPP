#include <iostream>
#include <string>
#include <cassert>
#include <array>
#include <utility>

using namespace std;

/**
 * @brief The Mod enum
 * working mode of programm
 */
enum class Mod
{
    help,       // print help
    bench_mark, // detect and display work time
    normal,     // just find and display numbers
    miss_arg    // notify about missing argv
};


/**
 * @brief arg_to_int
 * try interpret arg in str as int. If can't return answer.first == false,
 * else return {true, interpret number}
 * @param str
 * @return
 */
pair<bool, int> arg_to_int(const string& str)
{
    pair<bool, int> answer = {true, 0};

    try
    {
        answer.second = stoi(str);
    }
    catch(exception &e)
    {
        answer.first = false;
        return answer;
    }

    return answer;
}

/**
 * @brief parce_argv
 * parce argv according with Mode deskription
 * @param argc
 * @param argv
 * @return Working mode
 */
Mod parce_argv(const array<string,2> & args)
{
    return Mod::normal;
}

void parce_argv_test()
{
    cout << "Start parce_argv_test"<<endl;


    cout << "End parce_argv_test"<<endl;
}

void arg_to_int_test()
{
    cout << "Start arg_to_int_test" << endl;
    assert(arg_to_int("123") == make_pair(true, 123));
    assert(arg_to_int("123.0") == make_pair(true, 123));
    assert(arg_to_int("0") == make_pair(true, 0));
    assert(arg_to_int("-123") == make_pair(true, -123));
    assert(arg_to_int("-0mcm") == make_pair(true, 0));

    assert(arg_to_int("a") == make_pair(false, 0));
    assert(arg_to_int("aldkd") == make_pair(false, 0));
    assert(arg_to_int("-") == make_pair(false, 0));

    cout << "End arg_to_int_test" << endl;
}

#define DEBUG

/**
 * @brief main
 * Destination of this program is calculation prime numbers
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
#ifndef DEBUG
    cout << "Prime Numbers start" <<endl;
    if(argc<=1 || argc>=4)
    {
        cout << "error cli arguments count"<<endl;
        return -1;
    }

    array<string,2> cmd_args = {"-none", "-none"};

    cmd_args[0] = argv[1];
    if(argc == 3)
        cmd_args[1] = argv[2];

    parce_argv(cmd_args);
#endif

#ifdef DEBUG
    arg_to_int_test();

#endif
    return 0;
}

