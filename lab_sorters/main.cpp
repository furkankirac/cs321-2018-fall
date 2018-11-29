#include <iostream>
#include <vector>
#include <algorithm>

class Bubble{
    public:
        template<typename T>
        void operator()(T& vec){

            for(auto& _ :vec) {

                for(auto elem = vec.begin(); elem!= vec.end();++elem){

                    if(*elem<*(elem+1))
                        std::iter_swap(elem, (elem+1));

                }
            }

        }
};

class Insertion{
    public:
        template<typename T>
        void operator()(T& vec){

            for (auto i = vec.begin() + 1; i != vec.end(); ++i)
              {
                  auto key = *i;
                  auto j = i - 1;

                  while (j >= vec.begin() && *j < key)
                  {
                      *(j + 1) = *j;
                      --j;
                  }

                  *(j + 1) = key;
              }
        }
};

template<typename T, typename SortType>
inline void sortIt(T& vec, SortType& sort)

{
    sort(vec);
}


template<typename T>
inline void print(const T& vec){

    for(auto v : vec)
        std::cout<< v << " ";
    std::cout<< "\n"<< std::endl;
}

int main(int argc, char* argv[])

{
    auto n = 0;
    std::vector<int> numbers_vector(50);
    std::generate(numbers_vector.begin(), numbers_vector.end(), [&n] ()  { return n++; });
    std::random_shuffle(numbers_vector.begin(),numbers_vector.end());
    print(numbers_vector);

    Bubble bubble{};
    std::cout<<"Bubble sort:\n";
    sortIt(numbers_vector,bubble);
    print(numbers_vector);



    std::cout<<"Insertion sort:\n";
//  shuffle ages again:
    std::random_shuffle(numbers_vector.begin(),numbers_vector.end());
    print(numbers_vector);
    Insertion insertion{};
    sortIt(numbers_vector,insertion);
    print(numbers_vector);





    return 0;

}
