// -----------------------------------------------------------------------------------
// last before exam.: composing any number of functions
// last before exam.: lambdas with states: mutable lambdas
// -----------------------------------------------------------------------------------
// COURSE SUMMARY
// -----------------------------------------------------------------------------------
// global (free) functions, variables
// static member functions, static member variables
// unsigned, signed
// sizeof(T), alignof(T)
// RAII: If you're using a resource (state), encapsulate it in an object
// compile-time vs run-time
// class: operator() overloading, casting operator, copy/move construction/assignment
// functions, function pointers, function objects, lambdas
// generic programming -> templates (type and non-type compile-time parameters)
// value (C/C++/Pascal/...) vs reference (Java/JavaScript/Python/...) semantics
// functional programming: pure functions, no direct way of controlling execution path
// STL is functional+generic: std::erase/remove_if/copy_if/transform/accumulate/...
// type constructors: std::vector, std::list, std::map, ...
// initializer_list and braces { ... }
// && for r-value binding: move constructor/assignment
// std::unique_ptr
// variadic templates, parameter packs, auto... in lambdas, size...
// fold expressions
// binding run-time parameters with compile-time parameters
// lifting a function
// composing functions from other functions
// ranges library and | operator for function composition
// -----------------------------------------------------------------------------------
// Imperative: skipped: ADL (argument dependent lookup)
// OOP:        skipped: dynamic polymorphism (virtual functions)
// OOP:        skipped: inheritance (considered dangerous, better use composition and FP)
// Generics:   skipped: static polymorphism (CRTP: curiously recurring template pattern)
// Generics:   skipped: forwarding references template<typename T> ... T&& ... / auto&&
// Generics:   skipped: SFINAE (substitution failure is not an error)
// FP:         skipped: higher order functions (HOF), higher order components (HOC)
// -----------------------------------------------------------------------------------

// Functional Programming                   OOP
// -----------------------------------------------------------------------------------
// Uses Immutable data                      Uses Mutable data
// Follows Declarative Programming Model    Follows Imperative Programming Model
// Focus is on: “What you are doing”        Focus is on “How you are doing”
// Supports Parallel Programming            Not suitable for Parallel Programming
// Its functions have no-side effects       Its methods can produce serious side effects
// Flow Control is done using func.calls &  Flow control is done using loops and
//   function calls with recursion           conditional statements
// Uses "Recursion" concept to iterate data Uses "Loop" concept to iterate Data
// Execution order is not so important      Execution order of statements is very important
// Supports both "Abstraction over Data"    Supports only "Abstraction over Data"
//   and "Abstraction over Behavior"

#include <iostream>
#include <vector>

using namespace std;

#include <range/v3/all.hpp>

template<typename F, typename G>
auto compose_(F f, G g)
{
    return [=](auto ...x) {
        return f(g(x...));
    };
}

auto compose = [](auto f, auto g) {
    return [=](auto ...xs) {
        return f(g(xs...));
    };
};

double fahrenheitToCelsius(double fahrenheit) { return (fahrenheit - 32) / 180.0 * 100.0; }
bool isRoomTemperature(double celcius) { return celcius >= 20.0 && celcius <= 25.0; }

double bmi(double weight, double height) { return weight / (height*height); }
bool isOverweight(double bmi) { return bmi >= 30.0; }

int main(int argc, char* argv[])
{
    cout << compose(isRoomTemperature, fahrenheitToCelsius)(70) << endl;
    cout << compose(isOverweight, bmi)(75, 1.80) << endl;

    auto v = std::vector<int>{10, 20, 35};
    // lazily evaluated block
    auto rng = v
            | ranges::view::transform([](int value) { return value*value; })
            | ranges::view::reverse
            | ranges::view::take(2);

    return 0;
}
