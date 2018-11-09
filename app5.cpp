// typename vs class. type and non-type template parameters

#include <iostream>

template<typename T>
class ArrayList
{
    T values[10] = {0};

public:
//    ArrayList() = default;
    inline T operator[](int index) const
    { return values[index]; }

};

int main(int argc, char* argv[])
{
    int a = int();

    ArrayList<int> L;

    return L[0];
}
