#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <array>
#include <iostream>

using std::array;
using std::cout;
using std::endl;

/**
 * @brief The Generator class
 * Generator random numbers based on Matrix
 */
class Generator{

public:

    Generator() = default;

    /**
     * @brief Generator
     * Set start state of generator
     * @param shift row of matrix [0,5] if passed incorrsct will assign 0
     * @param node column of matrix [0,5] if passed incorrect will assign 0
     */
    Generator(int shift, int node);
    ~Generator() = default;

    /**
     * @brief gen
     * generate next number belong {0,1,2,3,4,5,6}
     * @return
     */
    int gen();

    /**
     * @brief print
     * print current state of Generator
     */
    void print()
    {
        cout <<"Generator" << endl;
        cout << "shift: " << shift <<endl;
        cout << "node: " << node <<endl;
        cout << "Matrix: " << endl;

        for(auto i: matrix)
        {
            for(int el: i)
                cout << el << " ";
            cout << endl;
        }
    }

private:

    /**
     * @brief next_shift
     * @return
     */
    int next_shift();

    array<array<int, 6>, 6> matrix = {{                 //i am don't know
                                      {{0,1,2,3,4,5}},  //why but compiler
                                      {{1,2,3,4,5,0}},  //gcc 4.9 -std=c++1y
                                      {{2,3,4,5,0,1}},  //required this extra
                                      {{3,4,5,0,1,2}},  //braces
                                      {{4,5,0,1,2,3}},  //but in docs said
                                      {{5,0,1,2,3,4}}   //what in c++14 it
                                     }};                //not needed

    int shift = 0;
    int node = 0;

};

#endif //GENERATOR_HPP
