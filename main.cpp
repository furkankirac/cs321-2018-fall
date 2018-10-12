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

struct Data
{
    char name[100];
    int age;

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

    Data d;
    d.age = 41;
    strcpy(d.name, "HELLO");

    d.printName();
    d.printAge();
    printAgeInData(d);
}
