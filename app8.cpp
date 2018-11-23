// std::erase, std::remove_if, std::copy_if

// haskell  -> c++              -> python
// ---------------------------------------
// map      -> std::transform   -> map
// filter   -> std::copy_if     -> filter
// fold*    -> std::accumulate  -> reduce

// vector, list, back_inserter, front_inserter, iota
// Google's MapReduce?

#include <iostream>
#include <vector>
//#include <list>
//#include <algorithm>
//#include <numeric>

int main(int argc, char* argv[])
{
    using namespace std;

    vector<int> v = { 1, 2, 3, 4, 5 };
    vector<int> y(v.size());

    for(int i=0; i<v.size(); ++i)
        y[i] = v.at(i) * v.at(i);

    for(auto val : v)
        cout << val << ", ";
    cout << endl;

    for(auto val : y)
        cout << val << ", ";
    cout << endl;

    return 0;
}
