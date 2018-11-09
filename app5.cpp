// typename vs class. type and non-type template parameters

#include <iostream>

template<typename T, int N>
class ArrayList
{
    T values[N] = {0};

public:
    ArrayList() = default;
    inline T& operator[](int index)
    { return values[index]; }

    inline T operator[](int index) const
    { return values[index]; }

    template<typename U>
    ArrayList(const ArrayList<U, N>& other)
    {
        for(int i=0; i<N; ++i)
            values[i] = other[i];
    }

    template<typename U>
    ArrayList<T, N>& operator =(const ArrayList<U, N>& other)
    {
        for(int i=0; i<N; ++i)
            values[i] = other[i];
        return *this;
    }


};

int main(int argc, char* argv[])
{
    ArrayList<short, 10> S;
    ArrayList<char, 10> C;
    ArrayList<int, 10> L = S;
    ArrayList<int, 10> L2 = C;

//    ArrayList<ArrayList<int>> A;



    L[0] = 10;

    return L[0];
}
