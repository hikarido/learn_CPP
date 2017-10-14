#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

/**
 * @brief is_word_polindrom
 * Determin what is the word polindrom or nof
 *
 * @details
 * EXAMPLE
 * =======
 * not polindroms: "hello","123jji321", "keks", " ", "", "a"
 * polindroms: "223heh322", "kak"
 * if word contain escape sequence or back slash return false
 * @pram word supposed polindrom
 * @return true if word is polindrom
 */
bool is_word_polindrom(const string & word)
{
    // ""
    if(word.empty())
        return false;

    //contains escape sequence
    if(find(word.cbegin(), word.cend(), '\\') != word.cend())
        return false;

    // one  character
    if(word.size() == 1)
        return false;

    auto first = word.cbegin();
    auto second = word.cend() - 1;

    while(first <= second)
    {
        if(*first != *second)
            return false;

        ++first;
        --second;
    }

    return true;
}

/**
 * @brief is_word_polindrom_test
 * Perform testing is_word_polindrom()
 */
void is_word_polindrom_test()
{
    assert(is_word_polindrom("") == false);
    assert(is_word_polindrom(" ") == false);
    assert(is_word_polindrom("a") == false);
    string chars = "`1234567890-=\\qwertyuiop[]asdfghjkl;/'zxcvbnm,.\
            QWERTYUIOPLKJHGFDSAZXCVBNM";

    for(char c: chars)
            assert(is_word_polindrom(string(1, c)) == false);

    assert(is_word_polindrom("aa") == true);
    assert(is_word_polindrom("aaa") == true);
    assert(is_word_polindrom("aaaa") == true);
    assert(is_word_polindrom("aaaaa") == true);
    assert(is_word_polindrom("aaaaaa") == true);
    assert(is_word_polindrom("aba") == true);
    assert(is_word_polindrom("abba") == true);
    assert(is_word_polindrom("abcba") == true);

    //input word with '\'
    cout << "Enter word contained '\\' character" << endl;
    string in;
    cin >> in;
    assert(is_word_polindrom(in) == false);

}

/**
 * @brief main
 * Polindrom test area
 * TODO check some book on polindroms
 * @return
 */
int main()
{
    cout << "is_word_polindrom_test(); pessing" << endl;
    is_word_polindrom_test();
    return 0;
}

