// Accumulate class. operator << overload example. also as free function.
// Int operator = (const Int& other){ return other;} /// nooooo
// compile-time vs run-time
// templates: generic programming

#include <iostream>

struct Int
{
    int value;

    Int(int value = 0) : value(value) // ctor #1
    {
        std::cout << "ctor #1" << std::endl;
    }

    Int(const Int& other) // ctor #2
    {
        value = other.value;
        std::cout << "ctor #2" << std::endl;
    }

    Int& operator =(const Int& other) // copy-assignment operator
    {
        value = other.value;
        std::cout << "copy-assignment" << std::endl;

        return *this;
    }
};

int main(int argc, char* argv[])
{
    Int v1(10); // ctor #1
    Int v2(v1); // ctor #2
    Int v3(v2); // ctor #2 again
    Int v4;
    v4 = v3 = v2; // copy-assignment

    std::cout << v1.value << std::endl;
    std::cout << v2.value << std::endl;
    std::cout << v3.value << std::endl;

    return 0;
}
