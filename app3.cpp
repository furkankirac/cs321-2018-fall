//functions - C
//function pointers - C
//function objects - C++ (old)
//lambdas - C++11

#include <iostream>

class WriteYourself
{
public:
    int value = 0;

    WriteYourself() = default;

    WriteYourself(int value) : value(value)
    {
    }

    WriteYourself(const WriteYourself& other) = default;

    void operator() () const
    {
        std::cout << value << "\n";
    }
};

int main(int argc, char* argv[])
{
    auto v1 = 10;
    auto v2 = 100.5f;
    auto v3 = 100.5;
    auto v4 = "hello";

    auto numCalls = 0;
    auto times = 5;

    auto do_10_times = [&numCalls, times]() {
        ++numCalls;
        for(int i=0; i<times; ++i)
        {
            auto a = WriteYourself(i);
            a();
        }

    };

    do_10_times();
    std::cout << "NC = " << numCalls << "\n";
}
