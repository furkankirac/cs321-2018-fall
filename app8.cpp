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
#include <list>
#include <algorithm>
#include <numeric>

int main(int argc, char* argv[])
{
    using namespace std;

    auto print = [](const auto& container) {
        for(auto val : container)
            cout << val << ", ";
        cout << endl;
    };

    vector<int> v(50);
    iota(v.begin(), v.end(), 1);
    list<int> y;
    vector<int> z;

    transform(v.begin(), v.end(), front_inserter(y), [](int value) {
        return value*value;
    });

    int k = 10;
    copy_if(y.begin(), y.end(), back_inserter(z),
            [&k](int value) { return value > k; }
    );

    auto sum_z = accumulate(z.begin(), z.end(), 0);

    print(v);
    print(y);
    print(z);
    cout << "sum_z = " << sum_z << endl;

    return 0;
}
