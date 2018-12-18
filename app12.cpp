#include <iostream>

#include <range/v3/all.hpp>

int main(int argc, char* argv[])
{
    { // Sum up elements of a sequence, starting from the value 0.0.
        const auto v = std::vector<double>{ 1.5, 2.7, 3.8, 4.2 };
        auto val = ranges::accumulate(v, 0.0); // 12.2
    }
    { // Fold elements of a sequence via multiplication, starting from the value 1.
        const auto v = std::vector<int>{ 1, 2, 3, 4 };
        auto val = ranges::accumulate(v, 1, [](int a, int b){return a * b;}); // 24
    }
    { // Count the number of occurrences of number 7.
        const auto v = std::vector<int>{ 1, 2, 7, 4, 1, 7 };
        auto val = ranges::count(v, 7); // 2
    }
    { // Determine equality of two vectors.
        // [1, 2, 3] == [3, 2, 1]
        const auto v1 = std::vector<int>{ 1, 2, 3 };
        const auto v2 = std::vector<int>{ 3, 2, 1 };
        auto val = ranges::equal(v1,v2); // false
    }
    { // Determine equality of two strings.
        const auto s1 = std::string{"world"};
        const auto s2 = std::string{"WORLD"};
        auto val = ranges::equal(s1,s2); // false
    }
    { // Calculate the dot product of two vectors.
        const auto v1 = std::vector<int>{ 1, 3, -5 };
        const auto v2 = std::vector<int>{ 4, -2, -1 };
        auto val = ranges::inner_product(v1,v2,0); // 1*4 + 3*(-2) + (-5)*(-1) = 3
    }
    { // Sort elements of a sequence in ascending order.
        auto v = std::vector<int>{ 6, 7, 1, 3 };
        ranges::sort(v); // [1,3,6,7]
    }
    { // Sort elements of a sequence in descending order.
        auto v = std::vector<int>{ 6, 7, 1, 3 };
        ranges::sort(v, std::greater<int>()); // [7,6,3,1]
    }
    { // Create a range containing all the elements of the sequence. Useful for conversion.
        const auto v = std::vector<int>{ 1, 2, 3, 4, 5 };
        auto rng = v | ranges::view::all; // [1,2,3,4,5]
        std::cout << rng;
    }
    { // Create a vector of tuples, i.e. a cartesian product of two sequences.
        const auto letters = std::vector<char>{ 'A', 'B', 'C' };
        const auto numbers = std::vector<int>{ 1, 2 };

        auto rng = ranges::view::cartesian_product(letters, numbers);
        for(auto [a, b] : rng)
            std::cout << a << ' ' << b << ", ";
        // A 1, A 2, B 1, B 2, C 1, C 2
    }
    { // Create a quasi-infinite sequence of integers.
        auto rng = ranges::view::ints; // [0,1,2,3,4...]

    }
    { // Create a quasi-infinite sequence of integers starting from 4.
        auto rng = ranges::view::ints(4); // [4,5,6,7...]
    }
    { // Create a sequence of integers [4,5,6].
        auto rng = ranges::view::ints(4, 7); // [4,5,6]
    }
    { // Create a sequence of integers [8,9,10].
        auto rng = ranges::view::iota(8, 11); // [8,9,10]
    }
    { // Create a sequence of letters [A,B,C,D,E].
        auto rng = ranges::view::iota('A', 'F'); // [A,B,C,D,E]
    }
    { // Flatten a list of lists
        const auto v = std::vector<std::vector<int>>{
            {1, 3},
            {11, 13, 15},
            {25},
        };
        auto rng = v | ranges::view::join; // [1,3,11,13,15,25]
    }
    { // Create a quasi-infinite sequence with all elements equal to 4.
        auto rng = ranges::view::repeat(4); // [4,4,4,4,4,4,4,..]
    }
    { // Create a sequence by reversing the original sequence.
        const auto v = std::vector<int>{ 1, 2, 3, 4 };
        auto rng = v | ranges::view::reverse; // [4,3,2,1]
    }
    { // Create a sequence as a difference of two input sequences.
        auto v1 = std::vector<int>{ 3, 4, 5, 6, 7 }; // sort!
        auto v2 = std::vector<int>{ 4, 5 }; // sort!
        ranges::sort(v1); // sort!
        ranges::sort(v2); // sort!
        auto rng = ranges::view::set_difference(v1,v2); // [3,6,7]
    }
    { // Create a sequence as an intersection of two input sequences.
        auto v1 = std::vector<int>{ 3, 4, 5, 6 };
        auto v2 = std::vector<int>{ 5, 6, 7, 8 };
        ranges::sort(v1); // sort!
        ranges::sort(v2); // sort!
        auto rng = ranges::view::set_intersection(v1, v2); // [5,6]
    }
    { // Create a sequence as a union of two input sequences.
        const auto v1 = std::vector<int>{ 1, 2, 3 };
        const auto v2 = std::vector<int>{ 4, 5, 6 };
        auto rng = ranges::view::set_union(v1,v2); // [1,2,3,4,5,6]
    }
    { // Create a sequence using every third element of the original sequence.
        const auto v = std::vector<int>{ 0, 1, 2, 3, 4, 5, 6 };
        auto rng = v | ranges::view::stride(3); // [0,3,6]
    }
    { // Create a sequence without the first element of the original sequence.
        const auto v = std::vector<int>{ 1, 2, 3, 4 };
        auto rng = v | ranges::view::tail; // [2,3,4]
    }
    { // Create a sequence that contains the first three elements of the original sequence.
        const auto v = std::vector<int>{ 1, 2, 3, 4, 5 };
        auto rng = v | ranges::view::take(3); // [1,2,3]
    }
    { // Multiply each element of the sequence by 2.
        const auto v = std::vector<int>{ 3, 2, 1 };
        auto rng = v | ranges::view::transform([](int x) { return 2*x; }); // [6,4,2]
    }
    { // Create a sequence by removing duplicate neighbouring elements of the original sequence.
        const auto v = std::vector<int>{ 1, 2, 2, 3, 1, 1, 2, 2 };
        auto rng = v | ranges::view::unique; // [1,2,3,1,2]
    }
    { // Join two sequences by applying addition.
        const auto v1 = std::vector<int>{ 4, 2, 7 };
        const auto v2 = std::vector<int>{ 3, 2, 1 };
        auto rng = ranges::view::zip_with([](int a, int b) {return a + b; }, v1, v2); // [7,4,8]
    }

    return 0;
}
