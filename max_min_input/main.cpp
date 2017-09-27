#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <exception>

using namespace std;

vector<double> get_nums()
{
    string input;
    cout<<"введите число";
    getline(cin, input);
    cout<<endl<<input<<endl;
    vector<string> res;
    boost::algorithm::split(res, input,boost::is_space());
    cout<<"strings:"<<endl;
    for_each(res.cbegin(), res.cend(), [&](string val){cout<<val<<endl;});
    vector<double> nums;
    for(auto &i: res)
    {
        double interpreted = 0;
        try
        {
            interpreted = stod(i);
        }
        catch(exception &e)
        {
           cout << i << " not num"<< endl;
           continue;
        }

        nums.push_back(interpreted);
    }

    cout<<"interpreted"<<endl;
    for_each(nums.cbegin(), nums.cend(),
             [](double val){cout<<val<<endl;});

    return nums;
}

int main()
{
    cout << "Hello World!" << endl;
    auto nums = get_nums();
    auto answer = minmax_element(nums.cbegin(), nums.cend());
    cout << "min is:" << *answer.first<<endl;
    cout << "max is:" << *answer.second<<endl;

    return 0;
}

