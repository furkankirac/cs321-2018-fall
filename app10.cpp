#include <iostream>
#include <numeric>

// pure functions are better. eliminate state if possible.
// compile-time pure functions are represented by template meta programming in C++
// and also "constexpr" keyword. But let's skip constexpr for now.

// struct Divide<u, v>; // specialization for v=0
// struct Sum<first, second>;

// variadic templates
// struct Sum<first, second, ...>; ???
// 1) recursive version
// 2) fold expressions

// template<...> printAll
// binding run-time parameters with compile-time parameters

// variadic lambda functions

using namespace std;

template<typename ...Args>
void print(Args ...args)
{
    (cout << ... << args);
}


int main(int argc, char* argv[])
{
    print("hello", string{"how are you"}, 100);
//    cout << Sum<1, 2, 100>::value << endl;

    return 0;
}
