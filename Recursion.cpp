//
// Created by danie on 24/05/2021.
//

#include <unordered_map>
#include "Recursion.h"

namespace Recursion
{
    // Naive implementation.  No optimisation.
    large_t f(const large_t n)
    {
        if (n < 3)
        {
            return 1;
        }

        if (n & 1)
        {
            // Odd
            const large_t half = (n - 1) / 2;
            return f(half) + f(half - 1);
        }
        else
        {
            // Even
            return f(n / 2);
        }
    }

    large_t f_cache(const large_t n)
    {
        if ((n & (n-1)) == 0)
        {
            return 1;
        }

        static std::unordered_map<large_t, large_t> _cache;

        auto cache_search = _cache.find(n);

        if(cache_search != _cache.end())
        {
            return cache_search->second;
        }

        large_t result;

        if (n & 1)
        {
            // Odd
            const large_t half = (n - 1) / 2;
            result = f_cache(half) + f_cache(half - 1);
        }
        else
        {
            // Even
            result = f_cache(n / 2);
        }

        _cache[n] = result;
        return result;
    }
};