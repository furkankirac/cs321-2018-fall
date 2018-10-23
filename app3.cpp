//functions - C
//function pointers - C
//function objects - C++ (old)
//lambdas - C++11

#include <iostream>

using functype = float(*)(const int&);

float doIt(const int& some_value)
{
    std::cout << "doIt(" << some_value << ")\n";
    return some_value + 0.1f;
}

void runner(functype func_to_call)
{
    for(int i=0; i<10; ++i)
    {
        float retval = func_to_call(100);
        std::cout << "returned value = " << retval << "\n";
    }
}

int main(int argc, char* argv[])
{
//    functype a = &doIt;
    runner(&doIt);
}
