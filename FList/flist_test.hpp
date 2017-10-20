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
        l.insert("c");
//        assert(l.head->next->next->value == "c");

        cout << l;

        flist l2{};
        l2.insert("hero");
        assert(l2.head->value == "hero");


    }
};

#endif //FLIST_TEST_HPP
