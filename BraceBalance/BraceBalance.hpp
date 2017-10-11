#ifndef BRACE_BALANCE_HPP
#define BRACE_BALANCE_HPP

#include <stack>
#include <string>
#include <regex>

class BraceBalance{

public:
    BraceBalance() = default;
    ~BraceBalance() = default;

    /**
     * @brief check
     * In function passed string with characters sequence typicaly:
     * {[23](133kdn)}
     * 12*[3+4]
     * 2*(3+8*[2+3])
     * and more. Main character is braces. Other chars will ignored.
     * Function check for each open brace corresponds each close brace or not.
     * [1-2]*(1+3) correct
     * [{(}] incorrect
     * @param sentence
     * @return
     */
    bool check(const std::string & sentence)
    {
        std::stack<char> store{};

        for(char elem: sentence)
        {
            if(is_open(elem))
            {
                store.push((elem));
                continue;
            }

            if(is_close(elem))
            {
                if(store.empty() == false &&
                   open_close_correct(store.top(), elem))
                {
                    //occured close brase and it balansed wirh it open
                    store.pop();
                    continue;
                }
                else{
                    //missmatch openclose balance
                    return false;
                }
            }

            //not brace character will ignored
        }

        return true;
    }

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

    std::regex open_braces{"[\\[\\{\\(]"};
    std::regex close_braces{"[\\]\\}\\)]"};
    std::regex correct_pairs{"\\[\\]|\\{\\}|\\(\\)"};

    friend class BraceBalanceTest;
};

#endif
