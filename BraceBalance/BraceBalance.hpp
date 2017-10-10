#ifndef BRACE_BALANCE_HPP
#define BRACE_BALANCE_HPP

#include <stack>
#include <string>

class BraceBalance{

public:
    BraceBalance() = default;
    ~BraceBalance() = default;
    bool check(const std::string & sentence);

private:
    bool open_close_correct(char open, char close);
    bool is_open(char brace);
    bool is_close(char brace);

    std::stack<char> store;


};

#endif
