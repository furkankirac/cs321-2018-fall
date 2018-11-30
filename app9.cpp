// functional programming: type constructor:
// templates in C++, std::vector, std::list, ...
// monadic style, will talk about it in following lectures after midterm

// std::initializer_list, range-for
// uniform initialization, struct Point, int i{2.0}

// std::map

// && for r-value binding
// move constructor, move assignment

// std::unique_ptr

#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Point
{
    int x{};
    int y{};
    string name{};

    Point(int x, int y) : x(x), y(y)
    {
        cout << "ctor\n";
    }

    Point(std::initializer_list<int> il) :
        x{*il.begin()},
        y{*(il.begin()+1)}
    {
        cout << "ctor with init-list\n";
    }

    Point(const Point& other) : x(other.x), y(other.y), name(other.name)
    {
        cout << "copy ctor\n";
    }

    Point(Point&& other) :
        x(other.x),
        y(other.y),
        name(move(other.name))
    {
        cout << "move ctor\n";
    }

    Point& operator =(const Point& other)
    {
        x = other.x;
        y = other.y;
        name = other.name;
        cout << "copy assignment\n";
        return *this;
    }

    Point& operator =(Point&& other)
    {
        x = other.x;
        y = other.y;
        name = (string&&)other.name;
        cout << "move assignment\n";
        return *this;
    }


};


template <typename>
struct TypeDisplayer;

int main(int argc, char* argv[])
{
    //    TypeDisplayer<decltype(a)> k;
//    for(auto value : {5, 10, 20})
//        cout << value << endl;

    Point p1{10, 20};
    cout << endl;
////    cout << "x=" << p1.x << endl;
////    cout << "y=" << p1.y << endl;

//    Point p2 = p1; // copy ctor
//    cout << endl;

//    Point p3(p1); // copy ctor
//    cout << endl;

//    Point p4{p1}; // copy ctor
//    cout << endl;

//    p1 = p2; // copy assignment
//    cout << endl;

    p1 = {50, 50}; // ctor with init-list + copy assignment
    cout << endl;

    Point pp = move(p1);

//    Point p5 = {50, 50};
//    cout << endl;

//    map<int, string> m{
//        {10, "ten"},
//        {20, "twenty"}
//    };

//    m[10] = "TEN";
//    try {
//        cout << m.at(25) << endl;
//    } catch(...)
//    {
//        cout << "exception\n";
//    }

////    int i = 2.0; // this will work
////    int i{2.0}; // this won't compile, which is good

    unique_ptr<char> str(new char[1000000]);

    unique_ptr<Point> mypoint(new Point(50, 20));
    auto mypoint2 = make_unique<Point>(50, 20);


    return 0;
}
