// Pointer arithmetic, chars, []
// heap: malloc/free
// heap: new/delete
// member functions
// Stack vs Heap: Java vs C vs C++
// constness
// type/variable, typedef, struct
// compile-time/run-time

#include "stdio.h"
#include "string.h"

struct Data
{
    char name[100];
    int age;

    void printAge();
    void printName();
};


void Data::printAge()
{
    printf("Age: %d\n", this->age);
}

void Data::printName()
{
    printf("Name: %s\n", this->name);
}

void printTitle()
{
    printf("This is our first CS321 program :)\n");

    Data d;
    d.age = 41;
    strcpy(d.name, "HELLO");

    d.printName();
    d.printAge();
}


int main(int argc, char* argv[])
{
    printTitle();
}
