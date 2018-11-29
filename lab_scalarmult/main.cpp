#include <iostream>


template<int n, int d>
struct Fraction
{
    static const int num = n;
    static const int denom = d;
};

template<int k, typename F>
struct ScalarMult
{
    using result = Fraction<k*F::num, F::denom>;
};

template<int u, int v>  struct gcd          { static const int value = gcd<v, u % v>::value; };
template<int u>         struct gcd<u, 0>    { static const int value = u; };


int main(int argc, char* argv[])
{
    using namespace std;

    using F = ScalarMult<22, Fraction<1, 11>>::result;
    static const int k = gcd<F::num, F::denom>::value;
    using Fsimp = Fraction<F::num/k, F::denom/k>;

    cout << "result = " << F::num << "/" << F::denom << endl;
    cout << "result = " << Fsimp::num << "/" << Fsimp::denom << endl;

    return 0;
}
