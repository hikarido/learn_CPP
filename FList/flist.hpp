#ifndef FLIST_HPP
#define FLIST_HPP
#include <ostream>
#include <string>

using std::string;

/**
 * @brief The flist class
 * Implement forward single direction list. Store element string type,
 * sorted in lexicographic order, without dublicates
 *
 * @details
 * List specification:
 *
 * flist create empty list
 *
 * ~flist destruct each list element
 *
 * insert val into list. If val already exist val
 * not be added and return false, else return true
 *
 * remove will delete val from list and release memory return true,
 * if val not contains in list return true
 *
 * operator << will print list in next form(angle braces not print)
 * <[list elem head, next, other,........, last]std::endl>
 */
class flist{

public:
    flist() = default;
    ~flist() = default;
    bool insert(string & val);
    bool remove(string & val);
    friend std::ostream& operator<<(std::ostream & out,
                                    const flist & obj);

private:
    /**
     *@brief Node
     * determine list element
     */
    class Node
    {
    public:
        Node(string &val):value(val){}
        ~Node()
        {
            next = nullptr;
        }
        string value{};
        Node * next = nullptr;
    };

    Node * head = nullptr;

};

#endif //FLIST_HPP
