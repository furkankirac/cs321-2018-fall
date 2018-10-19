//Constructor / destructor
//Operators / overloading
//Casting

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

    ~Fraction() = default;

    Fraction& operator =(const Fraction& other)
    {
        num = other.num;
        denum = other.denum;
        return *this;
    }

    Fraction operator +(const Fraction& other)
    {
        return Fraction(
                    num*other.denum + other.num*denum,
                    denum*other.denum
                    );
    }

    operator float()
    {
        return (float)num / denum;
    }

    void print() const
    {
        std::cout << "num = " << num << "\n";
        std::cout << "denum = " << denum << "\n\n";
    }

    void operator () (const char* title)
    {
        std::cout << title << "\n";
        print();
    }

};


int main(int argc, char* argv[])
{
    Fraction f1(2, 3);
    Fraction f2(5);
//    Fraction f2b = 10;

//    Fraction f2b(f2);
    Fraction f2b(Fraction(5));

    Fraction f3(5, 2);

    f1 = Fraction(11, 3);
    Fraction fadd = f1 + f2;
    fadd.print();
    fadd("TITLE TITLE TITLE");

    std::cout << "float value = " << (float)fadd << "\n";

//    Fraction f2c = 5;

//    f1.print();
//    f2.print();
//    f2b.print();
//    f3.print();

    return 0;
}
