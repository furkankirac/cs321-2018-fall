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
#include "string.h"
#include "stdint.h"

class Data
{
public:
    static int numData;

    char name[97];
    uint16_t age; // this can store between 0..65535

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
    printf("Name: %s\n", this->name);
}

int main(int argc, char* argv[])
{
    printf("Our CS321 program is evolving.\n");
    printf("Size of Data class is %ld bytes.\n", sizeof(Data));
    printf("Alignment of Data is %ld bytes.\n", alignof(Data));
    printf("Alignment of uint32_t is %ld bytes.\n", alignof(uint32_t));

    Data d;
    d.age = 41;
    strcpy(d.name, "HELLO");

    d.printName();
    d.printAge();
    printAgeInData(d);
}
