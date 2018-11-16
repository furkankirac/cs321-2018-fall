#include <iostream>
#include <numeric>

using uint = unsigned int;

// greatest common divisor algorithm is found by Euclid and published in his "Elements" (BC 300, 2300 years ago!)
inline uint GCD0(uint u, uint v)
{
    while(v != 0)
    {
        auto r = u % v; // % is the modulus operator. gives the remainder after dividing u by v
        u = v;
        v = r;
    }
    return u;
}

// students will write the below code
// note: function templates cannot be specialized for their template parameters
// need to use "if constexpr / else"
template<uint u, uint v>
inline uint GCD1()
{
    if constexpr(v != 0)
        return GCD1<v, u % v>();
    else
        return u;
}

// class template, class templates can be specialized
template<uint u, uint v>
struct GCD2
{
    static inline uint eval() { return GCD2<v, u % v>::eval(); }
};

// class template specialization for v=0
template<uint u>
struct GCD2<u, 0> // note the <u, 0> here
{
    static inline uint eval() { return u; }
};

// class template, class templates can be specialized
template<uint u, uint v>
struct GCD3
{
    static const uint value = GCD3<v, u % v>::value;
};

// class template specialization for v=0
template<uint u>
struct GCD3<u, 0> // note the <u, 0> here
{
    static const uint value = u;
};

int main(int argc, char* argv[])
{
    std::cout << std::gcd(20, 12) << std::endl; // prints 4, standard library's run-time implementation
    std::cout << GCD0(20, 12) << std::endl; // prints 4, our run-time implementation as a free function
    std::cout << GCD1<20, 12>() << std::endl; // prints 4, your template based compile-time implementation
    std::cout << GCD2<20, 12>::eval() << std::endl; // prints 4, your template based compile-time implementation
    std::cout << GCD3<20, 12>::value << std::endl; // prints 4, your template based compile-time implementation
    return 0;
}
