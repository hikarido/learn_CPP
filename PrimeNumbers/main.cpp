#include <iostream>
#include <string>
#include <cassert>
#include <array>
#include <utility>
#include <vector>
#include <boost/dynamic_bitset.hpp>
#include <chrono>

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
    if(args[0] == "-help")
        return Mod::help;


    {
        auto ans = arg_to_int(args[0]);

        if(ans.first == false)
            return Mod::miss_arg;
        else if(ans.second < 0 || ans.second <= 2)
            return Mod::miss_arg;
    }

    if(args[1] == "-bench_mark")
        return Mod::bench_mark;

    return Mod::normal;
}

void parce_argv_test()
{
    cout << "Start parce_argv_test"<<endl;
    assert(parce_argv({"123",""}) == Mod::normal);
    assert(parce_argv({"-123","jfkfl"}) == Mod::miss_arg);
    assert(parce_argv({"0",""}) == Mod::miss_arg);

    assert(parce_argv({"123","-bench_mark"}) == Mod::bench_mark);
    assert(parce_argv({"kfl","-bench_mark"}) == Mod::miss_arg);

    assert(parce_argv({"-help","-none"}) == Mod::help);
    assert(parce_argv({"","-help"}) == Mod::miss_arg);
    assert(parce_argv({"123","-help"}) == Mod::normal);
    assert(parce_argv({"-help","jfjfn"}) == Mod::help);
    assert(parce_argv({"-12","-none"}) == Mod::miss_arg);
    assert(parce_argv({"0","-help"}) == Mod::miss_arg);
    assert(parce_argv({"1","-help"}) == Mod::miss_arg);
    assert(parce_argv({"2","-help"}) == Mod::miss_arg);
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

void print_help()
{
    cout << "Programm to searching Prime numbers by Erathosfen algorithm" << endl;
    cout << "use:\n\
            <prog name> -help         - to display this help\n\
            <prog name> N             - to see all prime numbers before N\n\
            <prog name> N -bench_mark - to see numbers and bench mark\n\
            NOTE: N must be more then 2\n";
}

vector<int> erathosfen(const int number)
{

    boost::dynamic_bitset<> sieve(number);
    sieve.set(0, true);
    sieve.set(1, true);
    for(int p = 2; p*p < number; p++)
    {
        //p is prime and not strided out then
        if(sieve.test(p) == false)
        {
            // need strike out all multiple of k
            for(int l = p*p; l < number; l+=p)
            {
                sieve.set(l, true);
            }
        }
    }

    vector<int> primes;
    primes.reserve(number);

    for(int i = 2; i < number; i++)
    {
       if(sieve.test(i) == false)
       {
            primes.push_back(i);
       }
    }

    return move(primes);
}

/**
* @brief work_by_mode
* switch work flow programm by mode
* @see Mod::bench_mark call @see erathosfen and measure work speed
* @see Mod::normal call @see erathosfen(
* @see Mod::help call @see print_help
* @see Mod::miss_arg print error massage
* if work_mod not is Mod will called exit()
* @param work_mod
* @param number to erathosfen
* @return choised mod
*/
Mod work_by_mode(Mod work_mod, const string& number)
{
    vector<int> prime_numbers;
    std::chrono::nanoseconds benck_mark_result{};
    switch (work_mod)
    {
        case  Mod::help:
            print_help();
            return Mod::help;

        case Mod::miss_arg:
            cout<< "Error in passed command line arguments"<<endl;
            return Mod::miss_arg;

        case Mod::bench_mark:
        {
            //start bench mark
            auto start = std::chrono::system_clock::now();
            prime_numbers = erathosfen(arg_to_int(number).second);
            auto end = std::chrono::system_clock::now();
            benck_mark_result =
                    std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            //end bench mark
            break;
        }
        case Mod::normal:
            prime_numbers = erathosfen(arg_to_int(number).second);
            break;

        default:
            cout << "error mode in work_by_mode. exit(-1) called."<<endl;
            exit(-1);
    }

    for(auto &i: prime_numbers)
    {
        cout << i << ", ";
    }

    cout << endl;

    if(work_mod == Mod::bench_mark)
        cout << endl << "Working time: "\
             << benck_mark_result.count() <<" ns"<<endl;


    return work_mod;
}

void work_by_mode_test()
{
    cout << "Start work_by_mode" << endl;
    assert(work_by_mode(Mod::bench_mark, "123") == Mod::bench_mark);
    assert(work_by_mode(Mod::normal, "123") == Mod::normal);
    assert(work_by_mode(Mod::help, "123") == Mod::help);
    assert(work_by_mode(Mod::miss_arg, "123") == Mod::miss_arg);
//    assert(work_by_mode(static_cast<Mod>(10), "123")
//           == Mod::miss_arg); //<-- exit(-1) called normal
    cout << "End work_by_mode" << endl;


}

//#define DEBUG

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

    work_by_mode(parce_argv(cmd_args), cmd_args[0]);
#endif

#ifdef DEBUG
    arg_to_int_test();
    parce_argv_test();
    work_by_mode_test();

#endif
    return 0;
}

