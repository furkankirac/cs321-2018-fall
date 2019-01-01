#include <iostream>

using namespace std;

#include <range/v3/all.hpp>
using namespace ranges;

template<typename T>
struct Pair
{
    T first;
    T second;
};

bool isPrime(int val)
{
    if(val%2 == 0)
        return false;

    for(int i=3; i<val/2; i+=2)
        if(val%i == 0)
            return false;

    return true;
}

int main(int argc, char* argv[])
{
    auto primes = view::ints(1) | view::filter([](int val) { return isPrime(val); }) | view::take(20);
    auto primepairs = view::zip_with([](int v1, int v2) { return Pair<int>{v1, v2}; }, primes, primes | view::tail);

    cout << primes << endl;
    cout << (primes | view::tail) << endl;
    for(const auto [v1, v2] : primepairs)
        cout << '[' << v1 << ',' << v2 << ']' << endl;

//    for(const auto v : primepairs)
//        cout << '[' << v.first << ',' << v.second << ']' << endl;

    return 0;
}
