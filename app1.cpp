// global functions, global variables (C)
// namespaces
// static member functions, static member variables (C++)
// struct vs class
// unsigned/signed
// memory layout of classes
// reflection in C
// RAII (Resource Acquisition is Initialization), constructor, destructor (C++)
// compile-time/run-time

#include "stdio.h"
#include "stdint.h"
#include <string>

//typedef uint16_t Age; // C way of type aliasing
using Age = uint16_t; // C++ way of type aliasing

class Data
{
public:
    static int numData;

    std::string name;
    Age age; // this can store between 0..65535

    Data() : age(0)
    {
    }

    Data(Age age) : age(age)
    {
    }

    Data(Age age, const char* name) : age(age), name(name)
    {
    }


    void printAge() const;
    void printName() const;
};



void printAgeInData(const Data& d)
{
    printf("Age: %d\n", d.age);
}

void Data::printAge() const
{
    printf("Age: %d\n", this->age);
}

void Data::printName() const
{
    printf("Name: %s\n", this->name.c_str());
}

int main(int argc, char* argv[])
{
    printf("Our CS321 program is evolving.\n");
    printf("Size of Data class is %ld bytes.\n", sizeof(Data));
    printf("Size of std::string class is %ld bytes.\n", sizeof(std::string));
    printf("Alignment of Data is %ld bytes.\n", alignof(Data));
    printf("Alignment of uint32_t is %ld bytes.\n", alignof(uint32_t));

    Data d(41, "HELLO");

    d.printName();
    d.printAge();
    printAgeInData(d);
}
