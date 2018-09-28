#include "stdio.h"
#include "string.h"

struct Data
{
    char name[100];
    int age;
};


void printAgeInData(Data* data)
{
    printf("1) %d\n", data->age);
    data->age = 50;
    printf("2) %d\n", data->age);
}

void printTitle()
{
    int k = 0;
    Data d;
    d.age = 41;
    strcpy(d.name, "HELLO");
    printAgeInData(&d);

    printf("3) %d\n", d.age);

    printf("This is our first CS321 program :)\n");
    printf("[%s]\n", d.name);
}


int main(int argc, char* argv[])
{
    printTitle();
    printf("Number of arguments passed: %d\n", argc);
    for(int i=0; i<argc; ++i)
        printf("'%lx'\n", argv[i]);

}
