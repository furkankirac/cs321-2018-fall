// Accumulate class. operator << overload example. also as free function.
// compile-time vs run-time
// templates: generic programming

#include <iostream>

template<int value> // class template
struct Accumulate
{
    void operator() ()
    {
        std::cout << value << std::endl;
    }
};


// instead of below manual coding
//auto getAccumulate_int_10_20() { return Accumulate<30>(); }
//auto getAccumulate_int_100_1() { return Accumulate<101>(); }
//auto getAccumulate_unsignedshort_1000_11() { return Accumulate<1011>(); }

// do this instead
template<typename T, T a, T b>
auto getAccumulate() // function template
{
    return Accumulate<a+b>();
}


int main(int argc, char* argv[])
{
    const int v = 200;

    auto c = getAccumulate<int, 10, 20>(); // getAccumulate_10_20();
    auto d = getAccumulate<int, 100, 1>();
    auto e = getAccumulate<int, v, 1>();
    auto f = getAccumulate<unsigned short, 1000, 11>();

    c(); // 30
    d(); // 101
    e(); // 201
    f(); // 1011

//    std::cout << 30 << std::endl;
//    std::cout << 101 << std::endl;
//    std::cout << 201 << std::endl;

    return 0;
}
