// value vs reference semantics
// OOP includes encapsulation and inheritence
// C++ STL is example of Generics + FunctionalProgramming
// std::vector<T>
// OlderThan40: range-for, Function Object, Lambda
// OlderThanX: Function Object, Lambda
// returning auto
// forEach<FuncType>, forEach<T, FuncType>

#include <iostream>
#include <vector>

struct OlderThan40
{
    template<typename T>
    bool operator()(T age) const { return age > 40; }
};

struct OlderThanX
{
    int x;
    OlderThanX(int x) : x(x) { }

    template<typename T>
    bool operator()(T age) const { return age > x; }
};


template<typename T, typename FuncType>
inline void forEach(const std::vector<T>& vec, const FuncType& func)
{
    for(auto v : vec)
        if(func(v))
            std::cout << v << std::endl;
}

int main(int argc, char* argv[])
{
    std::vector<int> person_ages = { 10, 20, 3, 42, 50 };

    auto sz = person_ages.size();
    std::cout << "Num of ints in vector: " << sz << std::endl;

    { // function object

        std::cout << "OlderThan40 function object\n";
        forEach(person_ages, OlderThan40());
    }

    {
        std::cout << "OlderThan40 lambda\n";
        auto olderThan40 = [](auto age) -> bool { return age > 40; };
        forEach(person_ages, olderThan40);
    }

    {
        std::cout << "OlderThanX initialized with 40 (function object)\n";
        int x = 40;
        forEach(person_ages, OlderThanX(x));
    }

    {
        std::cout << "OlderThanX initialized with 40 (lambda)\n";
        int x = 40;
        forEach(person_ages, [=](auto age) { return age > x; });
    }

    return 0;
}
