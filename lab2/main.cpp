#include <iostream>

class Vector2d{
public:
    static unsigned int numVectorsCreated;
    int x;
    int y;

    Vector2d(): x(0), y(0){
        this->numVectorsCreated++;
    }

    Vector2d(int x, int y): x(x), y(y){
        this->numVectorsCreated++;
    }
    ~Vector2d() { this->numVectorsCreated--; }

};

unsigned int Vector2d::numVectorsCreated = 0;
using namespace std;

int main()
{
    cout<<"signed/unsigned test:"<< endl;
    unsigned short a_short = 0;
    unsigned int a_int = 0;
    a_short--; a_int--;
    cout << "unsigned short : \t" << a_short<< "\n" << "unsigned int : \t" << a_int << endl;


    signed short b_short = 0;
    signed int b_int = 0;
    b_short--; b_int--;
    cout << "unsigned short : \t" << b_short<< "\n" << "unsigned int : \t" << b_int << endl;


    cout <<"Vector2d tests"<< endl;

    Vector2d a; // default constructor initializes to x=0, y=0
    Vector2d b(10, 20);
    std::cout << "number of vectors alive : " << Vector2d::numVectorsCreated << std::endl;

    Vector2d* arr[100];
    for(int i=0; i<100; ++i)
        arr[i] = new Vector2d(i, i);
    std::cout << "number of vectors alive : " << Vector2d::numVectorsCreated << std::endl;

    for(int i=0; i<100; ++i)
        delete arr[i];

    std::cout << "number of vectors alive : " << Vector2d::numVectorsCreated << std::endl;
    return 0;
}
