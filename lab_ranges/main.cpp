#include <iostream>

#include <range/v3/all.hpp>

int main(int argc, char* argv[])
{


    //Fibonacci sequence generator:
    auto fibonacciGenerator = [a=0, b=1]() mutable { auto c = a+b; a=b; b=c; return a; };
    auto rng = ranges::view::generate(fibonacciGenerator) |
            ranges::view::take(10);

    std::cout<< "Fibonacci sequence : "<< rng<< std::endl;


    //Caesar Cipher:
    auto s = std::string {"orange"};
    auto shift = 11;
    auto encrypted = ranges::to_<std::string>( s |
                              ranges::view::transform([](char c){ return tolower(c);}) |
                              ranges::view::transform([&shift](char c) -> char{
                                    return 'a' + (c - 'a' + shift) % 26;})
                     );

    std::cout << "original : "<< s << std::endl;
    std::cout << "encrypted : "<< encrypted << std::endl;

    return 0;



}
