#include "stdio.h"
#include "string.h"

struct Data
{
    char name[100];
    int age;
};

void printTitle()
{
    int k = 0;
    Data d;
//    d.name[0] = 'A';
//    d.name[1] = 0;

    strcpy(d.name, "HELLO");

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
