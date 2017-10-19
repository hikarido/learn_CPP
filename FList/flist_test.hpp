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
        create_test();
        Node_subclass_test();
    }

    void create_test()
    {
        flist l{};
        assert(l.head == nullptr);
    }

    void Node_subclass_test()
    {
        string s{"hello"};
        flist::Node node(s);
        assert(node.next == nullptr);
        assert(node.value == "hello");

    }
};

#endif //FLIST_TEST_HPP
