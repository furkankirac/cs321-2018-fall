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
//auto getAccumulate_10_20() { return Accumulate<30>(); }
//auto getAccumulate_100_1() { return Accumulate<101>(); }


// do this instead
template<int a, int b>
auto getAccumulate() // function template
{
    return Accumulate<a+b>();
}


int main(int argc, char* argv[])
{
    const int v = 200;

    auto c = getAccumulate<10, 20>(); // getAccumulate_10_20();
    auto d = getAccumulate<100, 1>();
    auto e = getAccumulate<v, 1>();

    c(); // 30
    d(); // 101
    e(); // 201

//    std::cout << 30 << std::endl;
//    std::cout << 101 << std::endl;
//    std::cout << 201 << std::endl;

    return 0;
}
