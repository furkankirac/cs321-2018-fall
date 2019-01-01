#include <iostream>


using namespace std;

// this is the base case for stopping recursive behavior
inline void printTitleDetail() { }

template<typename T>
inline void printTitleDetail(T first)
{
    cout << first << endl;
}

template<typename First, typename Second, typename ...Rest>
inline void printTitleDetail(First first, Second second, Rest... rest)
{
    cout << first << ": " << second << endl;
    printTitleDetail(rest...);
}


template<typename First, typename Second, typename ...Rest>
inline void printTitleDetail_(First first, Second second, Rest... rest)
{
    if constexpr(sizeof...(rest) == 0)
        return;
    else if constexpr(sizeof...(rest) == 1)
        cout << first << endl;
    else
    {
        cout << first << ": " << second << endl;
        printTitleDetail(rest...);
    }
}


int main(int argc, char* argv[])
{
    cout<< "Without constexpr's: " << endl;
    printTitleDetail("Age", 23, "Height", 1.70, "Weight", 65, string{"Name"}, "John", string{"Surname"}, "Doe", "Grade", 'A', "-----END-----");


    cout<< "With constexpr and sizeof" << endl;
    printTitleDetail_("Age", 23, "Height", 1.70, "Weight", 65, string{"Name"}, "John", string{"Surname"}, "Doe", "Grade", 'A', "-----END-----");


    return 0;
}
