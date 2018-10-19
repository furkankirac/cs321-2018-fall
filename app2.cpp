//Constructor / destructor
//Operators / overloading
//Casting
//Reflection: decltype
//C++ trailing return
//Almost always auto

#include <iostream>

class Fraction
{
public:
    int num = 0;
    int denum = 1;

    Fraction() = default;
    Fraction(int val) : num(val) { }
    Fraction(int num, int denum) : num(num), denum(denum) { }

    Fraction(const Fraction& other) = default;
//    {
//        num = other.num;
//        denum = other.denum;
//    }

    ~Fraction() = default;

    void print() const
    {
        std::cout << "num = " << num << "\n";
        std::cout << "denum = " << denum << "\n\n";
    }
};


int main(int argc, char* argv[])
{
    Fraction f1;
    Fraction f2(5);
//    Fraction f2b = 10;

    Fraction f2b(f2);
//    Fraction f2b(Fraction(5));

    Fraction f3(5, 2);

//    Fraction f2c = 5;

//    f1.print();
//    f2.print();
    f2b.print();
//    f3.print();

    return 0;
}
