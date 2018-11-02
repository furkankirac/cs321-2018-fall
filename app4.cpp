// Accumulate class. operator << overload example. also as free function.
// compile-time vs run-time
// templates: generic programming

#include <iostream>

struct Accumulate
{
    int value;

    Accumulate(int value = 0) : value(value) { }
};

Accumulate& operator <<(Accumulate& a, int v) // func #1
{
    std::cout << "BBBB";
    a.value += v;
    return a;
}

Accumulate& operator <<(Accumulate& a, const char*) // func #2
{
    std::cout << "AAAAAA";
    ++a.value;
    return a;
}


int main(int argc, char* argv[])
{
    Accumulate a;
    a << 10 << 20 << "hi guys"; // "....." this is const char*

    std::cout << a.value << std::endl;
    return 0;
}
