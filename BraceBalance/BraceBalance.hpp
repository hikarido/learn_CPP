#ifndef BRACE_BALANCE_HPP
#define BRACE_BALANCE_HPP

#include <stack>
#include <string>
#include <regex>

class BraceBalance{

public:
    BraceBalance() = default;
    ~BraceBalance() = default;
    bool check(const std::string & sentence);

private:
    bool open_close_correct(char open, char close);

    /**
     * @brief is_open
     * determin belongs brace to set of <[{(> or not
     * @return
     */
    bool is_open(char brace) const
    {
        if(std::regex_match(std::string(1, brace), open_braces))
        {
            return true;
        }
        return false;
    }

    /**
     * @brief is_close
     * determine belongs brace to set of <}])> or not
     * @return
     */
    bool is_close(char brace) const
    {
        if(std::regex_match(std::string(1, brace), close_braces))
        {
            return true;
        }
        return false;
    }

    std::stack<char> store;
    std::regex open_braces{"[\\[\\{\\(]"};
    std::regex close_braces{"[\\]\\}\\)]"};
//    std::regex correct_pairs{"[]|{}|()"};

    friend class BraceBalanceTest;
};

#endif
