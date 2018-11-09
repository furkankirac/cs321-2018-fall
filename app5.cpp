// typename vs class. type and non-type template parameters

#include <iostream>

template<typename T>
class ArrayList
{
    T values[10];

public:
    ArrayList()
    {
        for(int i=0; i<10; ++i)
            values[i] = T();
    }
    inline T get(int index) { return values[index]; }

};


int main(int argc, char* argv[])
{
    ArrayList<int> L;
    return L.get(0);
}
