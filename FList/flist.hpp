#ifndef FLIST_HPP
#define FLIST_HPP
#include <ostream>
#include <string>

using std::string;
using std::endl;
using std::cout;

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

    flist(const flist & other) = delete;
    flist & operator=(const flist & other) = delete;

    flist(flist && other) = delete;
    flist & operator=(flist && other) = delete;

    bool insert(const string && val)
    {
        if(head == nullptr)
        {
            head = new Node(val);
            return true;
        }

        Node * prv = head;
        Node * cur = head;

        //search place where val
        //will be inserted
        while(cur != nullptr)
        {
            if(cur->value > val)
            {
                break;
            }

            prv = cur;
            cur = cur->next;
        }

        if(cur == head)         //insert to begin
        {
            auto ins = new Node(val);
            ins->next = head;
            head = ins;
            return true;
        }

        if(cur == nullptr)      //insert to end
        {
            prv->next = new Node(val);
            return true;
        }

        auto ins = new Node(val);       //insert between elements
        ins->next = cur;
        prv->next = ins;
        return true;

    }

    bool remove(string & val);
    friend std::ostream& operator<<(std::ostream & out,
                                    const flist & obj)
    {
        if(obj.head == nullptr)
        {
            out << endl << "[]" << endl;
            return out;
        }

        out << endl << "[";
        auto current = obj.head;
        while(current->next != nullptr)
        {
            out << current->value << ", ";
            current = current->next;
        }

        out << current->value;
        out << "]"<<endl;

        return out;
    }

private:
    /**
     *@brief Node
     * determine list element
     */
    class Node
    {
    public:
        explicit Node(const string &val):value(val){}
        ~Node()
        {
            next = nullptr;
        }

        Node(const Node & other) = delete;
        Node & operator=(const Node & other) = delete;

        Node(Node && other) = delete;
        Node & operator=(Node && other) = delete;

        string value{};
        Node * next = nullptr;
    };

private:
    Node * head = nullptr;
    friend class flist_test;

};

#endif //FLIST_HPP
