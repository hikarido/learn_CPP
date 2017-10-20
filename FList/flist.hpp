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

        //front insertation
        if(head->value > val)
        {
            Node * in =  new Node(val);
            in->next = head;
            head = in;
            return true;
        }

        //find position to insert
        Node * cur = head;
        Node * prev = head;
        while(cur->value < val || cur->next != nullptr)
        {
             prev = cur;
             cur = cur->next;
        }

        //insertatio
//        if(cur->next == nullptr)
//        {
//            cur->next = new Node(val);
//            return true;
//        }
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
