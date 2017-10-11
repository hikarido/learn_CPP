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

    /**
     * @brief open_close_correct
     * determine belongs of pair brace string(openclose) to set <{},[],()>
     * @param open one of {([
     * @param close one of }])
     * @return true if yes, false other way
     */
    bool open_close_correct(char open, char close) const
    {
        std::string brace_pair = {open, close};
        if(std::regex_match(brace_pair, correct_pairs))
        {
            return true;
        }
        return false;
    }

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
    std::regex correct_pairs{"\\[\\]|\\{\\}|\\(\\)"};

    friend class BraceBalanceTest;
};

#endif
