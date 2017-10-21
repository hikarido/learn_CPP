#ifndef FLIST_TEST_HPP
#define FLIST_TEST_HPP

#include <iostream>
#include <cassert>
#include <string>
#include "flist.hpp"

using namespace std;

class flist_test{
public:
    flist_test()
    {
        cout << "test" << endl;
        create_test();
        Node_subclass_test();
        insert_test();
        cout << "end" << endl;
    }

    void create_test()
    {
        flist l{};
        flist r{};
        assert(l.head == nullptr);
    }

    void Node_subclass_test()
    {
        string s{"hello"};
        flist::Node node(s);
        assert(node.next == nullptr);
        assert(node.value == "hello");

    }

    void insert_test()
    {

        flist l{};
        l.insert("b");
        l.insert("a");
        assert(l.head->value == "a");
        assert(l.head->next->value == "b");
        l.insert("1");
        assert(l.head->value == "1");
        assert(l.head->next->value == "a");
        assert(l.head->next->next->value == "b");
        l.insert("15");
        l.insert("5");
        l.insert("3");
        l.insert("c");

        cout << l;

        //create empty
        {
            flist l{};
            assert(l.head == nullptr);
        }

        //insert in empty
        {
            flist l{};
            l.insert("a");
            assert(l.head->value == "a");
        }

        //insert to begin
        {
            flist l{};
            l.insert("a");
            l.insert("0");
            assert(l.head->value == "0");
        }

        //insert to end
        {
            flist l{};
            l.insert("a");
            l.insert("b");
            assert(l.head->next->value == "b");
        }

        //insert between begin and end
        {
            flist l{};
            l.insert("a");
            l.insert("c");
            l.insert("b");
            assert(l.head->next->value == "b");
        }


    }
};

#endif //FLIST_TEST_HPP
