#include <iostream>

using namespace std;

//#include <range/v3/all.hpp>
//using namespace ranges;

// operators size..., auto...

// lifting a function

// function composition: compose (template style, lambda style)
// fahrenheitToCelsius -> isRoomTemperature
// bmi -> isOverweight

// partial application
// sectorArea, circleArea

// specialize std::accumulate -> [](auto vec, auto lambda, auto init) { ... }

// structured binding
// ranges library quick reference

template<typename F, typename G>
auto compose_(F f, G g)
{
    return [=](auto x) {
        return f(g(x));
    };
}

auto compose = [](auto f, auto g) {
    return [=](auto x) {
        return f(g(x));
    };
};

double fahrenheitToCelsius(double fahrenheit)
{
    return (fahrenheit - 32) / 180.0 * 100.0;
}

bool isRoomTemperature(double celcius)
{
    return celcius >= 20.0 && celcius <= 25.0;
}


int main(int argc, char* argv[])
{
    auto func = compose(isRoomTemperature, fahrenheitToCelsius);
    bool isRoomTemp = func(70);

    cout << isRoomTemp << endl;

    return 0;
}
