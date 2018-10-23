//functions - C
//function pointers - C
//function objects - C++ (old)
//lambdas - C++11

#include <iostream>

using functype = void(*)(int&);

void doIt(int& some_value)
{
    std::cout << "doIt(" << some_value << ")\n";
    ++some_value;
}

void run10times(functype func_to_call)
{
    for(int i=0; i<10; ++i)
    {
        int j = i;
        std::cout << "value of j (before) = " << j << "\n";
        func_to_call(j);
        std::cout << "value of j (after) = " << j << "\n";
    }
}

int main(int argc, char* argv[])
{
    run10times(&doIt);
}
