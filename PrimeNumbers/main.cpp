#include <iostream>

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
 * @brief parce_argv
 * parce argv according with Mode deskription
 * @param argc
 * @param argv
 * @return Working mode
 */
Mod parce_argv(int argc, char *argv[])
{

    return Mod::normal;
}



/**
 * @brief main
 * Destination of this program is calculation prime numbers
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    cout << "Prime Numbers start" <<endl;
    return 0;
}

