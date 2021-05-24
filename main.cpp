#include <iostream>

#include <chrono>

#include "Recursion.h"
#include "HashMap.h"

int main() {
//    using namespace Recursion;
//    auto start = std::chrono::high_resolution_clock::now();
//
//    std::cout << f_cache(magic_number) << "\n";
//    auto end = std::chrono::high_resolution_clock::now();
//    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us" << std::endl;
    {
        hash_map<int, int> map(10);
        map.insert(10, 11);
        map.insert(20, 21);
        map.insert(30, 31);

        {
            std::optional<int> find = map.lookup(10);
            if(find)
            {
                std::cout << *find << "\n";
            }
        }

        {
            std::optional<int> find = map.lookup(20);
            if(find)
            {
                std::cout << *find << "\n";
            }
        }


        {
            std::optional<int> find = map.lookup(30);
            if(find)
            {
                std::cout << *find << "\n";
            }
        }

    }
    hash_map<int, int> map(10);
}
