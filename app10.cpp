#include <iostream>

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

using namespace std;

template<int u, int v>  struct Divide       { static const auto value = u / v; };
template<int k>         struct Divide<k, 0> { static const auto value = 0; };
template<>              struct Divide<0, 0> { static const auto value = -1; };

template<int ...Args>
struct Sum
{
    static const auto value = (0 + ... + Args);
};


template<typename ...Ts>
inline void print(Ts... args)
{
//    cout << ... << args;
    ((cout << args << endl), ...);
}

int main(int argc, char* argv[])
{
    // comma operator
//    (cout << "Hi there"), (cout << "How are you");

//    print<int, const char*, double>(10, "hello", 20.5);
    print(10, "hello", 20.5);

//    cout << Divide<10, 0>::value << endl;
//    cout << Divide<0, 0>::value << endl;
//    cout << Sum<10, 20, 30, 1, 2, 3>::value << endl;
    return 0;
}
