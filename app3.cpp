//functions - C
//function pointers - C
//function objects - C++ (old)
//lambdas - C++11

#include <iostream>

using functype = void(*)();

void doIt()
{
    std::cout << "doIt()\n";
}

void justDoIt()
{
    std::cout << "justDoIt()\n";
}

void runner(functype func_to_call)
{
    for(int i=0; i<10; ++i)
        func_to_call();
}

int main(int argc, char* argv[])
{
//    functype a = &doIt;
    runner(&justDoIt);
}
