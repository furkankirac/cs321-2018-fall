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

template<typename FuncType>
void forEach(const std::vector<int>& vec, const FuncType& func)
{
    for(int v : vec)
        if(func(v))
            std::cout << v << std::endl;
}

int main(int argc, char* argv[])
{
    std::vector<int> person_ages = { 10, 20, 3, 42, 50 };

    auto sz = person_ages.size();
    std::cout << "Num of ints in vector: " << sz << std::endl;

    { // function object
        struct OlderThan40
        {
            bool operator()(int age) const { return age > 40; }
        };

        std::cout << "OlderThan40 function object\n";
        OlderThan40 olderThan40;
        forEach(person_ages, olderThan40);
//        for(int v : person_ages)
//        {
//            if(olderThan40(v))
//                std::cout << v << std::endl;
//        }
    }

    {
        std::cout << "OlderThan40 lambda\n";
        auto olderThan40 = [](int age) -> bool { return age > 40; };
        forEach(person_ages, olderThan40);
//        for(int v : person_ages)
//        {
//            if(olderThan40(v))
//                std::cout << v << std::endl;
//        }
    }

    {
        struct OlderThanX
        {
            int x;
            OlderThanX(int x) : x(x) { }
            bool operator()(int age) const { return age > x; }
        };
        std::cout << "OlderThanX initialized with 40 (function object)\n";
        int x = 40;
        OlderThanX olderThanX(x);
        forEach(person_ages, olderThanX);
//        for(int v : person_ages)
//        {
//            if(olderThanX(v))
//                std::cout << v << std::endl;
//        }
    }

    {
        std::cout << "OlderThanX initialized with 40 (lambda)\n";
        int x = 40;
        auto olderThanX = [=](int age) { return age > x; };
        forEach(person_ages, olderThanX);
//        for(int v : person_ages)
//        {
//            if(olderThanX(v))
//                std::cout << v << std::endl;
//        }
    }

    return 0;
}
