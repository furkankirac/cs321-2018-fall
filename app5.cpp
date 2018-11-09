// operator precedence: chaining =, chaining other things
// inline functions
// factorial evaluated at compile time using template meta programming
//   (specialization of function templates)
// typename vs class. type and non-type template parameters

//#include <iostream>

inline int factorial(int n)
{
    int k=1;
    for(int i=n; i>=2; --i)
        k *= i;
    return k;
}

inline int factorial_recursive(int n)
{
    if(n == 0)
        return 1;
    return n * factorial_recursive(n-1);
}

inline int factorial_0() { return 1; }
inline int factorial_1() { return 1; }
inline int factorial_2() { return 2*factorial_1(); }
inline int factorial_3() { return 3*factorial_2(); }
inline int factorial_4() { return 4*factorial_3(); }
inline int factorial_5() { return 5*factorial_4(); }

template<int n>
int fact()
{
    return n * fact<n-1>();
}

template<>
int fact<0>()
{
    return 1;
}


int main(int argc, char* argv[])
{
//    return factorial(5);
//    return factorial_recursive(5);
//    return factorial_5();
    return fact<5>();
}
