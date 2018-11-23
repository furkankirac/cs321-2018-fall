// pure functions vs functions with state (doing assignments to variables)
// template<int> factorial example is pure
// Pure functional languages have no mutable data. Therefore, they use recursive definitions instead of loops.
// from the compiler's point of view:
// template<int> factorial example is not recursive. Only the definition looks recursive

// example: haskell example for definition of multiplication in terms of addition
// mult n 0 = 0
// mult n 1 = n
// mult n m = (mult n (m - 1)) + n

#include <iostream>

int main(int argc, char* argv[])
{
    return 0;
}
