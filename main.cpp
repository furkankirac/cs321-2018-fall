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
};


void printAgeInData(Data& data)
{
    printf("1) %d\n", data.age);
    data.age = 50;
    printf("2) %d\n", data.age);
}

void printTitle()
{
    printf("This is our first CS321 program :)\n");

    Data d;
    d.age = 41;
    strcpy(d.name, "HELLO");

    printAgeInData(d);

    printf("3) %d\n", d.age);

    printf("[%s]\n", d.name);
}

char letters[10] = {'C', 'S', '3', '2', '1'};

int main(int argc, char* argv[])
{
    printf("'%c'\n", *(letters+2));
    printf("'%c'\n", *(2+letters));
    printf("'%c'\n", letters[2]);
    printf("'%c'\n", 2[letters]);

    printTitle();
    printf("Number of arguments passed: %d\n", argc);
    for(int i=0; i<argc; ++i)
        printf("'%s'\n", argv[i]);
}
