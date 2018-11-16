#include <iostream>

// 1) write a class template named Any, with a single type parameter T
// 2) it must have only one attribute of type T with name "value"
// 3) it must have only one constructor declaration and
// must handle both default construction and construction from a value of type T
// 4) Any<T> must be castable to T such that below works:
// Any<int> i1(3);
// int i2 = i1;
// 5) Calling the instance of Any<T> must print the internal stored value to std::cout
// 6) overload + operator so that adding two Any<T> objects (T being the same for both)
// returns a new Any<T> instance whose internal value is addition of the two instances' internal values
// do this by a member operator + overload, and also with free functions

template<typename T>
struct Any
{
    T value;
    Any(T value = T()) : value(value) { }
    operator T() { return value; }
    void operator() (){ std::cout << value << std::endl; }
    Any<T> operator +(const Any<T>& other) { return Any<T>(value + other.value); }
};

// free function version requires a function template usage
//template<typename T>
//Any<T> operator +(const Any<T>& first, const Any<T>& second) { return Any<T>(first.value + second.value); }

int main(int argc, char* argv[])
{
    Any<int> i1(10);
    int i2 = i1;
    Any<int> i3 = i1;
    i3 = i1;
    i3();
    Any<int> i4(20);
    Any<int> i5 = i3+i4;
    (i1 + i4)();

    return 0;
}

