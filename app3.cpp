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

class Do10Times
{
public:

    void operator() (const WriteYourself& obj)
    {
        for(int i=0; i<10; ++i)
            obj();
    }

};

int main(int argc, char* argv[])
{
    Do10Times do_ten_times;
    do_ten_times(WriteYourself(100));
}
